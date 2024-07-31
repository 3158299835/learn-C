# 进阶学习 C 语言可以编写的程序以及个人的理解记录

介绍

这些是我在学习C语言的过程中自己练习的一些题目以及个人笔记

大家也可以参考着来学习

正在更新，初阶学习在→[初阶部分](https://blog.csdn.net/L_Z_J_I/article/details/140400417?spm=1001.2014.3001.5501)←可以点击打开

**大家可以在[我的gitee仓库](https://gitee.com/Xiao____liu/learning---c-language) 中下载笔记源文件**

**笔记源文件可以在Notion中导入**

# 一、深度剖析数据在内存中的存储

**本章重点**

1. 数据类型详细介绍
2. 整形在内存中的存储:原码、反码、补码
3. 大小端字节序介绍及判断
4. 浮点型在内存中的存储解析

## 1. 数据类型的介绍

- char            1字节
- short          2字节
- int               4字节
- long           在64位中占8字节 在32位系统重占4字节
- long long     C99中引入     8字节
- float             4字节
- double         8字节

**类型的意义:**

1. 使用这个类型开辟内存空间的大小(大小决定了使用范围)
2. 类型决定如何看待内存空间的视角

### 1.1 类型的基本归类

> **整形家族**
> 
- char
    - unsigned char
    - signed char
- short
    - unsigned short [int]
    - signed short [int]
- int
    - unsigned int
    - signed int
- long
    - unsigned long [int]
    - signed long [int]
- long long double
- 他们在头文件limits.h的头文件中

其中cahr  字符的本质是ASCII值，是整形
unsigned 为无符号
signed     为有符号    默认为有符号的。

在使用unsigned时，32为bit都可以用来做数值位置。
原来的符号位不用了。符号位为1=2^31

> **浮点型家族**
> 
- float
- double
- long double
- 他们在float.h的头文件中

其中float精度低。存储数值范围小
double精度高。存储的数值范围更大

> **构造类型**
> 
- 数组类型
- 结构体类型 struct
- 枚举类型    enum
- 联合类型    union

> **指针类型**
> 
- int* pi
- cahr* pi
- float* pi
- **void* pi**

等等都是指针类型

> 空类型
> 

void 表示空类型(无类型)
通常应用于函数的返回类型、函数的参数、指针类型。

1. 函数的在定义式用void。表示函数不会返回值
2. 函数的参数为void。表示函数不需要 传参，你别给我传！（强行传会警告）

## 2.整形在内存中的存储

### 2.1原码、反码、补码

计算机中的整数有三种2进制表示方法，即原码、反码和补码。
三种表示方法均有符号位和数值位两部分，符号位都是用0表示“正“，用1表示“负”，而数值位正数的原、反、补码都相同。
负整数的三种表示方法各不相同。
**原码**
直接将数值按照正负数的形式翻译成二进制就可以得到原码。
**反码**
将原码的符号位不变，其他位依次按位取反就可以得到反码。
**补码**
反码+1就得到补码。

为什么要用补码来存储呢?
在计算机系统中，数值一律用补码来表示和存储。原因在于，使用补码，可以将符号位和数值域统一处理;
同时，**加法和减法**也可以统一处理(CPU只有加法器)（-1和1补码相加=0000..0000）
此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路。
**（补码也可以取反+1得到原码。他们的计算过程是相同的）**

### 2.2大小端介绍

我们可以看到整形存储在内存中的补码。但是我们发现内存上顺序有点不对劲。是从右往左的
这是又为什么?

> **什么大端小端:**
大端(存储)模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中;
小端(存储)模式，是指数据的低位保存在内存的低地址中，而数据的高位,，保存在内存的高地址中。
> 

左边为低地址，右边为高地址 。
字节序是以字节为单位进行排序。
比如a= 0x 11 22 33 44   
但是存储在内存中的是11 22 33 44    就叫做大端字节序存储   （在码中左边的为高位）
**VS中存储的为小端的存储模式、 他会倒着存进去**

**大端【字节序】存储:**
把一个数据的**高位字节序**的内容存放在**低地址处**，把低位字节序的内容放在高地址处，就是大端字节序存储。
**小端【字节序】存储:**
把一个数据的高位字节序的内容存放在高地址处，把低位字节序的内容放在低地址处，就是小端字节序存储。

### 为什么有大小端？

为什么会有大小端模式之分呢?因为在许算机系统举，我是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8 bit。但是在C语言中除了8 bit的char之外，还有16 bit的short型，32 bit的long型(要看具体的编译器)，另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如何将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。
例如:一个16bit的 short型x，在内存中的地址为0x0010，x的值为 0x1122，那么 0x11为高字节，0x22为低字节。对于大端模式，就将0x11放在低地址中，即0x0010中，0x22放在高地址中，即 0x0011中。小端模式，刚好相反。我们常用的x86结构是小端模式，而KEIL C51则为大端模式。很多的ARM，DSP都为小端模式。有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。

**和硬件有关。**

### 写一个判断大小端的程序

这里考察对申请内存和指针操作权限的理解

```c
int main()
{
int a = 1;
if(*(char*)&a == 1) //把int型的a的地址，转化为char型。让他只能读取第一个字节的内容。
	printf("小端\n");   //如果为01 00 00 00 则为倒装。把高位放到高地址。 是小端 、
	else                    //否则为大端。
	printf(“大端\n");
return 0;
}
```

### 整形存储 练习

> 一、数据截断、整型提升规则
> 

```c
#include<stdio.h>
int main()
{
	char a = -1; 
	signed char b = -1;
	unsigned char c = -1;

	// - 1在内存中的 原码 为10000000000000000000000000000001
	// - 1在内存中的 反码 为11111111111111111111111111111110
	// - 1在内存中的 补码 为11111111111111111111111111111111
	// 在存入到char中时。从低位截断8个。11111111
	// 在打印时，整形提升 为11111111111111111111111111111111
	// 因为为有符号数，所以有符号的概念，高位第一位代表符号。在提升时其余位补符号
	// 还原为 原码   后为 为10000000000000000000000000000001
	// 所以打印为-1
	// 在存入到unsigned char中时。从低位截断8个bit11111111
	// 因为为无符号，所以没有符号位的概念。在这里也代表数值
	// 所以整形提升后补0  为00000000000000000000000011111111
	// 所以打印为 255
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}
	// char -128~127
```

**`char`**：通常是一个 8 位的有符号整数，范围是 `-128` 到 `127` 。

**`unsigned char`**：8 位的无符号整数，范围是 `0` 到 `255` 。

**`short`**：通常是 16 位的有符号整数，范围是 `-32768` 到 `32767` 。

**`unsigned short`**：16 位的无符号整数，范围是 `0` 到 `65535` 。

**`int`**：在大多数系统中是 32 位的有符号整数，范围是 `-2147483648` 到 `2147483647` 。

**`unsigned int`**：32 位的无符号整数，范围是 `0` 到 `4294967295` 。

**`long`**：在 32 位系统中通常与 `int` 范围相同；在 64 位系统中，通常是 64 位的有符号整数，范围更大。

**`unsigned long`**：对应的无符号类型。

**`long long`**：64 位的有符号整数，范围是 `-9223372036854775808` 到 `9223372036854775807` 。

**`unsigned long long`**：64 位的无符号整数，范围是 `0` 到 `18446744073709551615` 。

> 二、在进行整形提升的时候， 要根据数据的类型来判断补0 还是补  1
> 

```c
#include <stdio.h>

int main()
{
	char a = -128; 
	//-128   10000000000000000000000010000000 - 原码
	//-128   11111111111111111111111101111111 - 反码
	//-128   11111111111111111111111110000000 - 补码
	// 存储在cahr中为10000000
	// 打印为无符号时。整形提升。因为char为有符号的类型，
	//       11111111111111111111111110000000 - 补码
	//       11111111111111111111111110000000 - 原码
	printf("%u\n"，a);  // 4,294,967,168
	//%u -打印无符号整数/1
	return 0;
}
//在进行整形提升的时候， 要根据数据的类型来判断补0 还是补  1
```

> 三、结果一样。
> 

```c
#include<stdio.h>
int main()
{
	char a = 128;
	//128 - 00000000000000000000000010000000 - 原码
	//128 - 11111111111111111111111101111111 - 反码
	//128 - 11111111111111111111111110000000 - 补码
	// 截断  10000000
	//提升  11111111111111111111111110000000 - 补码
	//打印  11111111111111111111111110000000 - 原码
	printf("%u\n", a);
	return 0;
}
//结果一样。
```

> 四、注意类型转换。强制提升并不会影响最后以% 啥的形式打印
> 

```c
#include <stdio.h>
int main()
{
	int i = -20;
	unsigned int j = 10;
	//-20    10000000000000000000000000010100 -源码
	//-20    11111111111111111111111111101011 -反码
	//-20    11111111111111111111111111101100 -补码
	// 10    00000000000000000000000000001010 -补码
	//-20+10 11111111111111111111111111110110 -补码
	//int 和unsigned int提升为 后者.但是他是按照%d的形式输出需要转换为原码
	// 符号位不变，取反+1
	//       10000000000000000000000000001001 - 反码
	//       10000000000000000000000000001010 - 原码      
	// 所以打印出来为 - 10
	printf("%d\n",i + j);
	return 0;
}
```

> 五、-1在无符号打印为很大的正数
> 

```c
#include <stdio.h>

int main()
{
	unsigned int i = 0; 
	for (i = 9; i >= 0; i--)
		printf("%u\n",i);
	//打印9 8 7 6 5 4 3 2 1 0
	//到-1时，对于%u的整形  -1的补码是32个1.他是一个很大的正数
	return 0;
}
```

> 六、字符串求长度 和char 赋值
> 

```c
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d",strlen(a));  
	// strlen求字符串长度。 到\0结束 。他的ascii为0
	// char a 的范围为-128 ~ 127
	// a[i]的值会从-1开始  -2 -3 -4 -5 ...-128  此时再-1 就会变成
	//-128 补码	   10000000
	//-128 -1 补码 01111111
	// 反码        01111111
	// 原码        01111111   = 127
	//    .... -128  127  126 ......3 2 1 0 到 \0结束，
	// 之前一共有128 + 127 = 255个数字
	// 所以字符串长度为255
	return 0;
}
```

> 七、unsigned char的取值范围为0-255
> 

```c

#include<stdio.h>
int main()
{
	unsigned char i = 0;

	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
	//这里的 char为 unsigned修饰。
	//在从0到127最大值后 变为11111111 对于无符号。他的值为正数
	//再继续加会被截断为00000000  然后继续循环
	//unsigned char的取值范围为0-255
}
```

> 八、库函数strlen 返回值为无符号数
> 

```c

#include<stdio.h>
#include <string.h>

int main()
{
	if (strlen("abc") - strlen("abcdef") >= 0)
		printf(">\n"); 
	else
		printf("<\n");
	return 0;
	//strlen的返回值是size_t类型。也就是unsigned int 类型
	//他们相减后的也是一个无符号整数。也是正数。
}
```

## 3.浮点型在内存中的存储

常见的浮点数

> 3.14
1E10    1.0*10^10
> 

### 3.1浮点数存储的一个例子

**整形和浮点型在存储和获取值时他们的方法是不一样的**

```c
#include <stdio.h>
int main()
{
	int n = 9; 
	float* pFloat = (float*)&n;
	printf("n的值为:%d\n",n);  // 9
	printf("*pFloat的值为:%f\n", * pFloat); //以浮点数的形式来打印整数

	*pFloat = 9.0; 
	printf("num的值为:%d\n",n ); //以整数的方式来打印浮点数
	printf("*pFloat的值为:%f\n", * pFloat);//以浮点数的方式来打印浮点数
	//所以他们打印出来的值与我们预想的不一样。  
	
	return 0;
}
```

### 3.2 浮点数存储规则

根据国际标准IEEE(电气和电子工程协会)754，任意一个二进制浮点数V可以表示成下面的形式

- V = -（1）^2  ×*M*×2^E
- (-1)^S表示符号位，所以当S=0，V为正数;  当S=1，V为负数。
- M表示有效数字，大于等于1，小于2。
- 2^E表示指数位。

**比如V = 5.0 f**

在二进制中表示的形式是101.0  
                              他等价于1.01 * 2^2   
                           =  （-1）^0 × 1.01 × 2^2

                     V    = （-1）^S × M     ×2^E

                           所以**S = 0    M=1.1    E=2** 

**再举例子  V = 9.5f**      那么他的二进制是1001.1 （小数点后的1 位 2的 -1 次方）

=（-1）^0  × 1.0011 × 2^3

所以S = 0   M=1.0011   E=3

我们也由此可以了解浮点数的精度问题

例如V = 1.6  那么他的二进制数为1.1XXX  后面的XX是因为后面的2的n次方。但是float只能存四位字节。即使是double也才能存8个字节。
没办法精确的等于0.1  这个值。所以精度会丢失

**IEEE 754规定：**
对于32位的浮点数，
最高的1位是符号位S，紧接着的**8位**是指数E，剩下的**23位**为有效数字M

对于64位的浮点数，

最高的1位是符号位S，紧接着的**11位**是指数E，剩下的**23位**为有效数字M   

**补零补后边**

**IEEE 754对有效数字M和指数E，还有一些特别规定。**

1. 对于数字M
    
    前面说过，1≤M<2，也就是说，M可以写成1.xxxxxx的形式，其中xxxxxx表示小数部分
    
    IEEE 754规定，在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxxxx部分。比如保存1.01的时候，**只保存01**，等到读取的时候，再把第一位的1加上去。这样做的目的，是节省1位有效数字。以32位浮点数为例，留给M只有23位
    将第一位的1舍去以后，等于可以保存24位有效数字。 这样存储数据的精度就会更高
    
2. 对于数字E，情况就比较复杂（E有可能是负数）
    
    首先，E为一个无符号整数(unsignedint)这意味着，如果E为8位I它的取值范围为0~255;如果E为11位，它的取值范围为0~2047。但是，我们知道，科学计数法中的E是可以出现负数的，
    
    所以IEEE 754规定，存入内存时E的真实值必须再加上一个中间数，对于8位的E，这个中间数是127;**对于11位的E，这个中间数是1023。**
    
    真实值（E）+中间值 ( 172 / 1023 )
    
    比如，2^10的**E是10**，所以保存成32位浮点数时，必须保存成**10+127**=137，即10001001.
    

**然后，指数E从内存中取出还可以再分成三种情况:**

1. E不全为0或不全为1
    
    > 这时，浮点数就采用下面的规则表示，即指数E的计算值**减去127(**或1023)，**得到真实值，**再将有效数字M前加上第一位的**1。**
    比如:
    0.5(1/2)的二进制形式为0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0*2^(-1)，其阶码为-1+127=126，表示为
    01111110，而尾数1.0去掉整数部分为0，补齐0到23位00000000000000，则其二进制表示形式为:`0 01111110 00000000000000000000000`
    > 
2. E全为0
    
    > **这时，浮点数的指数E等于1-127(或者1-1023)**即为真实值有效数字M不再加上第一位的1，而是还原为0.xxxxxx的小数。这样做是为了表示+0，以及接近于0的很小的数字。
    > 
3. E为全1
    
    > 这时，如果有效数字M全为0，表示+无穷大(正负取决于符号位s)
    > 

# 二、指针的进阶

**本章重点**

1. 字符指针
2. 数组指针
3.  指针数组
4.  数组传参和指针传参
5. 函数指针
6. 函数指针数组
7. 指向函数指针数组的指针
8.  回调函数
9. 指针和数组面试题的解析

指针的主题，我们在初级阶段的《指针》章节已经接触过了，我们知道了指针的概念
1.擂针就是个变量，**用来存放地址**，地址唯一标识一块内存空间。
2.指针的大小是固定的**4/8**个字节(32位平台/64位平台)。
3.指针是有类型，**指针的类型决定了指针的+-整数的步长**，指针解引用操作的时候的权限。
4.指针的运算。

## 字符指针

在指针的类型中有一个char*

正常使用不说了

他也可以这样使用

```c
const char* p = "hello";
printf("%s",p);
```

这里注意，hello并不是存到了指针变量p中。而是p保存了首字母h的地址。

这里使用const是为了保护字符串。 
如果const不用其实也改不了。 不过编译器会报错

一道面试题

```c
//一道笔试题
int main()
{
	const char* p1 = "abcdef"; 
	const char* p2 = "abcdef";
	char arr1[] = "abcdef"; 
	char arr2[] = "abcdef";
	if (p1 == p2)
		printf("p1 == p2\n");
	else
		printf("p1!=p2\n");

	if (arr1 == arr2)
		printf("arr1 == arr2\n");
	else
		printf("arr1 != arr2\n");
	return 0;
	//输出结果是p1 = p2  arr1 != arr2
	//说明。p1 和p2 都指向了内存中的只读区域中的 a。地址相同 
	//但是arr1 和arr 2 是单独开辟了一片内存。有不同的地址
}
```

## 指针数组

是用来存放指针的数组

指针数组来关联三个数组的代码示例

```c
#include <stdio.h>
int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5};
	int arr2[5] = { 3, 4, 5, 6, 7};
	int arr3[5] = { 4, 5, 6 ,8, 9};

	int* arr[3] = { arr1, arr2, arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
			//arr[0]指的是指针数组arr下标为0的元素。即arr1
			//arr1[j] = arr1 数组中下标为j个元素
		}
		printf("\n");
	}
	return ;
}
```

## 数组指针

> **数组指针是指针。举例**
> 

```c
int *p1[10];  //p1 为指针数组， 数组里面有是个指针 int*类型的  有[10]个元素
int(*p2)[10]; //p2 为数组指针，  指针指向的是一个有十个元素数组
```

 p1 为指针数组， 数组里面有是个指针 int*类型的  有[10]个元素

 p2 为数组指针，  指针指向的是一个有十个元素数组

> 数组指针是存放数组的地址，使用方法是
**`int(*p2)[10] = &arr`  他的类型是int* (*) [10]**
> 

> **再次讨论数组名**
> 

int arr [10] = { 0 };

数组名`arr`通常表示的都是**数组首元素的地址**

除了两个例外

1. 在`sizeof()`内  他计算的是整个数组的大小。  
2. 使用`&arr`     他取出的是整个数组的地址。 （如果你对他+1 则会跳过整个数组

### 利用数组指针来输出一个二维数组的内容

```c
#include <stdio.h>

void my_printf(int(*arr)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//printf("%d ",arr[i][j]);
				// 这里的arr虽然是第一行的地址但也是二维数组的地址，
				// 因为不管是二维数组还是一位数组，
				// 他们的首地址都是第一行第一个的元素的地址
			//printf("%d ",*(*(arr+i)+j));
				// 这里的*(arr+i)  arr指的是第一行的地址，+1则是第二行的地址
			printf("%d ",(*(arr+i))[j]);
				// 这里的*(arr+i) 指的是第第i行的地址 括号不能去掉，不然会有问题
				// [j]前面的解引用之后就等同于某行的数组名首地址。
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	my_printf(arr, 3, 5);//这里的arr传入的是二维数组的第一个元素。
		                 //即二维数组的第一行。
	return	0;
}
```

学习了这些知识。理解一下下面的代码

```c
int arr[5];  //整形数组
int *parrl[10];  //指针数组。可以存放十个地址的数组
int(*parr2)[10]; //数组指针，可以存放数组地址的指针
int(*parr3[10])[5]; //数组指针数组 。可以存放数组地址数组
```

## 数组参数、指针参数

在写代码的时候难免要把【数组】或者【指针】传给函数，那函数的参数该如何设计呢?

**4.1 一维数组传参!**

```c
#include <stdio.h>
void test(int arr[])
void test(int arr[10])
void test(int *arr)
void test2(int *arr[20]) 
void test2(int **arr) 
int main()
int arr[10]= {0};
int *arr2[20]= {0};
test(arr);
test2(arr2);
```

以上都可以。在数组传参的时候。可以以数组【】接收。也可以用指针来接收

**4.2 二维数组传参！**

```c
void test(int arr[3][5])
{}
void test(int arr[][5])
{}
{}
void test(int(*arr)[5])
{}
int main()
{
	int arr[3][5]= {0};
	test(arr);
}
//注意不要用指针和指针数组以及二级指针来传二维数组的地址。
```

**4.3 一级指针传参**

传指针。用指针接收

形参部分是 整形指针的时候  可以传整形变量的地址、整形指针、整形数组名、
只要传过去的本质是一个整形指针

**4.4二级指针传参**

传二级指针。用二级指针接收

形参部分是 整形的二级指针的时候。 
可以传二级指针变量的地址 。也可以取一级指针变量的地址传过去、
指针数组也可以传过去。它相当于指针数组的首地址。

函数指针

## 函数指针

### 什么是函数指针

函数指针的本质是 指向函数的指针

函数的名字就是他的地址。和数组一样

用指针这样指向函数。和数组指针类似。

```c
void Add (int x, int y)
{
	return x + y;
}
int main()
{
	int (*pf)(int , int) = Add; // =&Add
	int ret = pf(2,3);  // =*pf(2, 3) 其实这个解引用没啥用，因为Add = &Add = pf
	printf("%d",ret);   //5
	return 0;
}

```

### 两段代码加深函数指针的理解

```c
//代码1
(*(void(*)())0)();
//代码2
void(*signal(int ,void(*)(int)))(int);
```

第一个代码
`void(*)()`是一个函数指针类型。他把0强制转换为void函数指针
然后0的地址的函数进行调用。

第二个代码

首先，从最内层开始分析。

1.  因为`signal`左边的 `*` 没有被括起来。所以他`signal`是和右边绑定的。
所以`signal ( int, void ( * ) ( int ) )`  是一个小块儿。
其中`signal` 是一个函数名：`int` 表示这个函数的第一个参数是一个整数类型。
`void ( * ) ( int )` 表示这个函数的第二个参数是一个指向函数的指针变量，该函数接受一个整形参数并且没有返回值。（就像我们接受一个整形变量一样 `int *`）
2. 可以看到。函数`signal ( int, void ( * ) ( int ) )`  的外边又被一层：`void ( * ) ( int )`所包住。
而`*`位于的括号内是用来存放函数指针变量的。**所以 signal 函数的返回值是一个函数指针变量。比如返回的函数指针变量是p 那么 外边的一层就等于`void ( *p ) ( int )` 就可以表示p所指向的函数是一个接受int型变量，没有返回的函数。**
3. 所以整个 `void ( * signal ( int, void ( * ) ( int ) ) ) ( int );` 表示 signal 函数的返回值是一个函数指针变量，返回的函数指针变量所指向的函数是一个接受一个整数参数并且没有返回值。
4.  最后 `void (*signal(int, void (*)(int)))(int);`表示整个`signal`函数的返回类型是一个函数指针，该指针指向一个函数，这个函数接受一个整型参数并返回`void`。

**简化声明使用`typedef`**

为了提高代码的可读性，我们可以使用`typedef`来简化`signal`函数的声明：

```c
typedef void(*acc)(int)
acc signal(int, acc);
```

这里，`acc`是一个新的类型名，代表了一个函数指针类型，指向一个接受整型参数且返回`void`的函数。使用`typedef`使得`signal`函数的声明更加清晰，提高了代码的可读性。

### 使用回调函数，在函数指针在函数内部调用其他函数来实现+ - * 计算器

函数中利用函数指针调用其他函数叫做**函数回调。**

```c
//回调函数
//利用函数指针在函数内部引用函数
//实现一个 + - * /计算器
#include <stdio.h>

void menu()
{
	printf("*************************************\n");
	printf("********   1. add   2. sub   ********\n");
	printf("********   3. mul   4. div   ********\n");
	printf("*******    0. exit           ********\n");
	printf("*************************************\n");
}

int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
void compute(int(*pf)(int, int))
//定义compute函数的输入参数为 int类型的函数指针、
// 且指向的函数的输入参数为int  int
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("输入操作数>:");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("%d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入功能:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			compute(add);
			break;
		case 2:
			compute(sub);
			break;
		case 3:
			compute(mul);
			break;
		case 4:
			compute(div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
	

	return 0;
}
```

## 函数指针数组

有套娃了  233

类比一下吧，

指针数组是 int* arr1[5];      cahr* arr2[6];

函数指针是 int (*pf) (int, int);

所以函数指针数组是把指针变量pf变成指针数组arr[] 
也就是int (*arr[4]) (int, int);

那上小节的计算器举例。可以更改成这样子

可以看到，利用函数指针数组极大地增大了简洁性。 以及可拓展性

这个又叫做**转移表**  因为他利用函数指针数组的下标来在不同的函数之间跳转

```c
//利用函数指针数组来改写一下
#include <stdio.h>

void menu()
{
	printf("*************************************\n");
	printf("********   1. add   2. sub   ********\n");
	printf("********   3. mul   4. div   ********\n");
	printf("*******    0. exit           ********\n");
	printf("*************************************\n");
}

int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*pfArr[5])(int, int) = { 0, add,sub,mul,div };//补0是为了输入1为add
	do
	{
		menu();
		printf("请输入功能:>");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("退出计算器\n");
			break;
		}
		else if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("计算结果为:%d\n", ret);
		}
		else
		{
			printf("选择错误\n");
		}
	} while (input);

	return 0;
}
```

## 指向函数指针数组的指针

指向函数指针数组的指针是一个`指针`

指针指向一个`数组`，数组的元素都是`函数`

这是一个函数指针数组`int (*pfArr[5])(int, int) = { 0, add,sub,mul,div };`

我们要定义一个指向这个指针数组的指针。 

那么我们的指**针的类型 就是 数组+函数指针**

**数组则是** 加 `[5]`   函数指针类型则是`int (*) (int ,int)` 
所以就定义一个指针变量  `ppArr`   他得是数组所以加`[5]` 为 `ppArr[]` 

pparr[]  又要指向函数指针类型  `int (*) (int ,int)`  
所以他最终为`int (*(*ppArr[5])) (int ,int)`  
其中ppArr`*` 表示 `ppArr` 是一个数组，数组中的每个元素都是一个指针。

## 回调函数

回调函数是通过函数指针的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数。我们就说这个叫回调函数。
回调函数不是有该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或者条件进行相应。

### 利用qsort来实现int数组的升序/降序排列

qsort 头文件是 `stdlib.h`

1. `void`指针：
    - 明白`void`指针可以接受任意类型的数据。
    - 清楚`void`指针在使用前需要进行强制类型转换才能进行解引用和算术运算。
2. `qsort`函数的参数，包括要排序数据的起始位置、元素个数、元素大小以及自定义的比较函数指针。
`int(*cmp)(const void* e1, const void* e2)`

```c
//利用qsort来实现int数组的升序/降序排列

#include<stdio.h>
#include<stdlib.h>

//void qsort(void* base,//要排序的数据的起始位置
//	size_t num,//待排序的元素个数
//	size_t width,//待排序的元素大小（单位为字节）
//	int(*cmp)(const void* e1, const void* e2)//函数指针-比较函数
//	//这个函数需要自己写，返回大于0  等于0    小于0的数字
//);

void cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e2 - *(int*)e1);//此时是降序，更改e1 和e2 就可以实现升序
}
// void指针式无类型指针，它可以接受任意类型的数据
// 但是它无法进行解引用和 +  - 的操作。 在使用之前需要进行强制类型转换

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]); 
	int i = 0;

	//排序
	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
```

### 自己写一个qsort，然后实现结构体内数字、字符串、和int型排序

```c
//自己写一个qsort。然后判断。
#include <stdlib.h>

//比较整形的
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}

void test1()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	//0 1 2 3 4 5 6 7 8 9
	//把数组排成升序
	int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, sz);

	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//定义一个结构体
struct Stu
{
	char name[20];
	int age;
};
//交换两个元素的方法
//char是为了能够交换不同的元素，比如int、char、short等、
//根据函数传来的步长来交换字节。
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//定义自己的比较函数，。。输入起始位置、元素长度、字节长度、比较函数
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设数组是排好序
		//一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//这里的cmp是需要另外编写的。
			//因为并不知道使用这个函数的人是判断float还是iint或者是别的
			//进行对比的时候。传送过去的都是char类型的地址。他们的步长有width决定跳过几个字节再传送地址。
			//会在我们编写的对比函数中对比之后再返回值进行判断然后交换
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;//如果一趟发现没有一次发生交换。那么就退出排序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

//abbdef
//abbqwerttt
//使用strcmp对比字符串时。是按位对比。a=a、b=b ..d<q 所以下面的大
//也就是说，在升序排列时，a开头的字母会在最前。z在最后 相同则比较下一个字母
//注意在定义的时候，实用的是const void*
//因为void*可以接受任何类型的指针，在使用的时候只需要进行类型转换就可以了。
//结构体比较字符串大小
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//strcmp --> >0 ==0 <0
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

//在进行结构体元素比较的时候，因为传的是地址，。所以用箭头符号来引出元素。

//结构体比较年龄大小
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

//测试使用qsort来排序结构数据
void test2()
{
	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);//传入自己写的比较age大小的函数
}
//使用自己写的冒泡排序来对int型数组的元素排序
void test3()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	//输出
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
//测试使用自己写的排序函数来排序结构数据中的字符串
void test4()
{

	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
```

这段 C 语言代码主要实现了自定义的排序算法和对不同数据类型（整型数组、结构体数组）的排序操作。

**1. 比较函数 `cmp_int`**：
- 这个函数用于比较两个整数。它通过将两个指针转换为 `int` 类型，然后计算差值来确定大小关系。

**2. `test1` 函数**：
- 定义了一个整数数组 `arr`，并通过 `qsort` 函数对其进行升序排序。
- `qsort` 函数需要四个参数：待排序的数组、数组元素个数、每个元素的大小以及比较函数的指针。

**3. 结构体 `Stu` 的定义**：
- 包含一个字符数组 `name` 用于存储姓名和一个整数 `age` 表示年龄。

**4. `Swap` 函数**：
- 用于交换两个元素，通过逐个字节交换来实现不同类型元素的交换。

**5. `bubble_sort` 函数**：
- 这是一个冒泡排序函数，它接受一个通用的指针 `base`、元素个数 `sz`、每个元素的宽度 `width` 和比较函数的指针 `cmp`。
- 在函数内部，通过循环比较相邻元素并根据比较结果进行交换。

**6. 比较函数 `cmp_stu_by_name` 和 `cmp_stu_by_age`**：
- `cmp_stu_by_name` 用于按照结构体中 `name` 字段的字符串进行比较。
- `cmp_stu_by_age` 用于按照结构体中 `age` 字段的整数值进行比较。

**7. `test2` 函数**：
- 定义了一个结构体数组 `s`，并使用 `qsort` 函数根据年龄进行排序。

**8. `test3` 函数**：
- 对整数数组使用自定义的冒泡排序函数 `bubble_sort` 进行排序。

**9. `test4` 函数**：
- 对结构体数组使用自定义的冒泡排序函数 `bubble_sort` 根据姓名进行排序。

## 数组名的理解

总结

> sizeof中只有数组名单独出现才是代表整个数组，有别的都不行其他都是**首元素**地址
sizeof只关注类型。不关注数值
> 
> 
> 1.sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
> 2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
> 3.除此之外所有的数组名都表示首元素的地址。
> 

```c

数组名的理解
指针的运算和指针类型的意义

int main()
{
	int a[] = { 1,2,3,4 };

	printf("%d\n", sizeof(a));//16
	//sizeof(数组名)，数组名表示整个数组，计算的是整个数组的大小，单位是字节
	printf("%d\n", sizeof(a + 0));//4
	//a不是单独放在sizeof内部，也没有取地址，所以a就是首元素的地址，a+0还是首元素的地址
	//是地址，大小就是4/8个字节
	printf("%d\n", sizeof(*a));//4
	//*a中的a是数组首元素的地址，*a就是对首元素的地址解引用，找到的就是首元素
	//首元素的大小就是4个字节
	printf("%d\n", sizeof(a + 1));
	//这里的a是数组首元素的地址
	//a+1是第二个元素的地址
	//sizeof(a+1)就是地址的大小
	printf("%d\n", sizeof(a[1]));//4
	//计算的是第二个元素的大小
	printf("%d\n", sizeof(&a));//4/8
	//&a取出的数组的地址，数组的地址，也就是个地址
	printf("%d\n", sizeof(*&a));//16
	//&a----> int(*)[4]
	//&a拿到的是数组名的地址，类型是 int(*)[4],是一种数组指针
	//数组指针解引用找到的是数组
	//*&a ---> a
	//
	//2.
	//&和*抵消了
	//*&a ---> a
	//
 //printf("%d\n", sizeof(&a + 1));//4/8
	//&a取出的是数组的地址
	//&a-->  int(*)[4]
	//&a+1 是从数组a的地址向后跳过了一个（4个整型元素的）数组的大小
	//&a+1还是地址，是地址就是4/8字节
	//
	printf("%d\n", sizeof(&a[0]));//4/8
	//&a[0]就是第一个元素的地址
	//计算的是地址的大小
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	//&a[0]+1是第二个元素的地址
	//大小是4/8个字节
	//&a[0]+1 ---> &a[1]
	//
	return 0;
}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6
	//sizeof(数组名)
	printf("%d\n", sizeof(arr + 0));//4/8
	//arr + 0 是数组首元素的地址
	printf("%d\n", sizeof(*arr));//1
	//*arr就是数组的首元素，大小是1字节
	//*arr --> arr[0]
	//*(arr+0) --> arr[0]
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8
	//&arr是数组的地址，是地址就是4/8个字节
	printf("%d\n", sizeof(&arr + 1));//4/8
	//&arr + 1是数组后的地址
	//
	printf("%d\n", sizeof(&arr[0] + 1));//4/8
	//&arr[0] + 1是第二个元素的地址
	//
	return 0;
}

#include <string.h>

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };

	printf("%d\n", strlen(arr));//随机值  没\0
	printf("%d\n", strlen(arr + 0));//随机值

//	printf("%d\n", strlen(*arr));//--> strlen('a');-->strlen(97);//野指针
//	printf("%d\n", strlen(arr[1]));//-->strlen('b')-->strlen(98);

	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1

	return 0;
}

int main()
{
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	char arr[] = "abcdef";
	//strlen是求字符串长度的，关注的是字符串中的\0，计算的是\0之前出现的字符的个数
	//strlen是库函数，只针对字符串
	//sizeof只关注占用内存空间的大小，不在乎内存中放的是什么
	//sizeof是操作符
	//
	//[a b c d e f \0]
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	//printf("%d\n", strlen(*arr));//err
	//printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5

	//[a b c d e f \0]
	//printf("%d\n", sizeof(arr));//7
	//printf("%d\n", sizeof(arr + 0));//4/8
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4/8
	//printf("%d\n", sizeof(&arr + 1));//4/8
	//printf("%d\n", sizeof(&arr[0] + 1));//4/8

	return 0;
}

	char arr[] = "abcdef";
	//strlen是求字符串长度的，关注的是字符串中的\0，计算的是\0之前出现的字符的个数
	//strlen是库函数，只针对字符串
	//sizeof只关注占用内存空间的大小，不在乎内存中放的是什么
	//sizeof是操作符
	//
	//[a b c d e f \0]
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	//printf("%d\n", strlen(*arr));//err
	//printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5

int main()
{
	char* p = "abcdef";
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));

	printf("%d\n", strlen(p));
	printf("%d\n", strlen(p + 1));
	printf("%d\n", strlen(*p));
	printf("%d\n", strlen(p[0]));
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(&p + 1));
	printf("%d\n", strlen(&p[0] + 1));

	return 0;
}

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	a[0]是第一行这个一维数组的数组名，单独放在sizeof内部，a[0]表示第一个整个这个一维数组
	sizeof(a[0])计算的就是第一行的大小
	printf("%d\n", sizeof(a[0] + 1));
	a[0]并没有单独放在sizeof内部，也没取地址，a[0]就表示首元素的地址
	就是第一行这个一维数组的第一个元素的地址，a[0] + 1就是第一行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));
	a[0] + 1就是第一行第二个元素的地址
	*(a[0] + 1))就是第一行第二个元素
	printf("%d\n", sizeof(a + 1));//4/8
	a虽然是二维数组的地址，但是并没有单独放在sizeof内部，也没取地址
	a表示首元素的地址，二维数组的首元素是它的第一行，a就是第一行的地址
	a+1就是跳过第一行，表示第二行的地址
	printf("%d\n", sizeof(*(a + 1)));//16
	*(a + 1)是对第二行地址的解引用，拿到的是第二行
	*(a+1)-->a[1]
	sizeof(*(a+1))-->sizeof(a[1])
	
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	&a[0] - 对第一行的数组名取地址，拿出的是第一行的地址
	&a[0]+1 - 得到的是第二行的地址
	
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	a表示首元素的地址，就是第一行的地址
	*a就是对第一行地址的解引用，拿到的就是第一行
	
	printf("%d\n", sizeof(a[3]));//16
	只关注类型，不关注值 
	printf("%d\n", sizeof(a[0]));//16

	int a = 10;
	sizeof(int);
	sizeof(a);

	return 0;
}
```

## 指针笔试题

```c

#include <stdio.h>

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 }; 
	int* ptr = (int*)(&a + 1);
	//取地址a是数组a的地址  +1  后 是数组最后一个元素的地址再+1
	printf("%d,%d", *(a + 1), *(ptr - 1));
	//a+1  a是首元素的地址，+1是第二个元素的地址，再解引用就是 2     
	//ptr -1 是数组指针-1 也就是  a的地址  所以输出为  2   5 
	return 0;
}

struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p = (struct Test*)0x100000;   //把地址值强制类型转换为struct
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
//x86
int main()
{
	printf("%p\n", p + 0x1);//跳过一个结构体 20个字节
	//0x100000+20-->0x100014
	printf("%p\n", (unsigned long)p + 0x1);
	//100000转换为整数位1048576
	//1,048,576+1 --> 1,048,577
	//0x100001 
	printf("%p\n", (unsigned int*)p + 0x1);//跳过四个字节。 int型
	//0x100000+4-->0x100004
	return 0;
}

int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	//数组最后一个元素的地址+1（+4字节）
	int* ptr2 = (int*)((int)a + 1);
	//a转换为int类型后+1  只是+1 不是+四字节
	//然后转换为int* 的地址。  相当于 a数组第一个元素的地址 + 一个字节。
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}

#include <stdio.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//考逗号表达式， 这里等效于(1, 3, 5);
	int* p;
	p = a[0];//这里是第一行的地址，即第一个元素的地址  也就是 1
	printf("%d", p[0]);
	return 0;
}

int main()
{
	int a[5][5];
	int(*p)[4];
	//int (*p)[4] 是数组指针变量，用来存放数组
	p = a;
	//a在这里是数组的名字，数组名=首元素地址，=第一行的地址，
	// 它的类型是int (*) [5]
	//而int(*p)[4]的指针类型是int (*) [4]
	//所以数组指针p在存a的首元素地址的时候。是觉得这个数组以四个字节为一组去存的
	//换个说法就是，如果此时对p+1  它的步长是4个字节。

	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	//	&p [4][2] 的意思是读取以p角度的第四排第二个数字。
	// 此时p指向的是a的首元素的地址 0 。那么[4][2] 这个数字就要往右+4*4+2=18
	//	也就是&p [4][2] 取的是数组a的第 18 / 5 = 3 ...3 第4行第4个
	// 而 &a[4][2] 是第5行第3个。 中间差了4个字节。

	//那么地址相减之后就是 -4   以%d打印就是-4
	//但是以%p打印地址。就需要打印-4的补码的16进制了
	//-4的原码是 10000000 00000000 00000000 00000100
	//反码是     11111111 11111111 11111111 11111011
	//补码是     11111111 11111111 11111111 11111100
	//16进制是   F   F    F   F    F   F    F   C
	
	return 0;
}

#include <stdio.h>
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1); 
	//数组地址+1跳过去， = aa最后一个元素的地址+1的地址
	//这里的&aa取出的是aa的首元素 即一个数组的地址。
	int* ptr2 = (int*)(*(aa + 1));
	// 这里的aa是首元素的地址
	//aa不是单独放在这里面的， 所以此时的aa是二维数组的第一个元素的地址，
	// 也就是第一行的地址，然后再+1 得到的是第二行第一个元素的地址，
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	//ptr1 -1 是 最后一个元素的地址。 再解引用  =   10
	// ptr2 -1  是第二行第一个的元素的地址-1 即第一组最后一个元素的地址，   即  10   5
	//  10    5 
	return 0;
}

#include <stdio.h>
int main()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;

	pa++;
	printf("%s\n", *pa);
 输出at  pa存的是第一个首地址，然后++ 到at
	return 0;
}

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;

	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);//ER
	//先++ 解引用 后-- 再++最后解引用 
	printf("%s\n", *cpp[-2] + 3);  // ST
	//  = **(cpp-2) +3 
	printf("%s\n", cpp[-1][-1] + 1);//EW
	//==  *(*(cp-1)-1)+1
	//+1 是最后才操作的，。步长是1字节
	return 0;
}
```

# 三、字符函数和字符串函数

> 本章重点
重点介绍处理字符和字符串的库函数的使用和注意事项
> 

**求字符串长度**
strlen

**长度不受限制的字符串函数**
strcpy
strcat
strcmp

**长度受限制的字符串函数介绍**
strncpy
strncat
strncmp

**字符串查找**
strstr
strtok

**错误信息报告**
strierror字符操作

**内存操作函数**
memcpy
memmove
memset
memcmp

## 函数介绍

头文件，<string.h>

### strlen

用来求字符串的长度。计算\0之前的字符数量。

他的反回蚀sze_t。是**无符号的
所以不要去进行相减的操作，
对于无符号数字 3-5 的值是大于0的**

`char arr[] = {‘a’,‘b’,‘c’}` 是没有`\0`的
`char arr[] = “abc”` 是有`\0`的

### strcpy

`char* strcpy(char *destination, const char *source)`

意思是把源头的字符串拷贝到目标字符串
返回目标空间的起始地址
传入的是字符串的指针。cahr数组  数组名字就是地址~
要注意在传入的时候源数据里必须要有\0
并且目标数组要放得下原数组内的东西
并且目标空间要能够被修改。

- 源字符串必须以'\0'结束。
- 会将源字符串中的'\0'拷贝到目标空间。
- 目标空间必须足够大，以确保能存放源字符串。
- 目标空间必须可变。
- 学会模拟实现。

```c
//写一个strcp

#include<stdio.h>
#include<string.h>
#include<assert.h>

////返回目标空间的起始地址
//int my_strcpy(char* arr1, char* arr2)
//{
//	char* p = arr1;
//	assert(arr1);
//	assert(arr2);
//
//	while (*arr2 != '\0')
//	{
//		*arr1++ = *arr2++;
//	}
//	*arr2 = '\0';//最后一次要把\赋值上去
//	return p;
//}

//简化后

int my_strcpy(char* arr1, char* arr2)
{
	char* p = arr1;
	assert(arr1 && arr2);
	while (*arr1++ = *arr2++)//赋值为\0后 ascii为0 退出循环
		;
	return p;
}

int main()
{
	char arr1[] = "woaini";
	char arr2[20] = { 0 };
	my_strcpy(arr2, arr1);
	printf("%s", arr2);

	return 0;
}
```

### strcat

`char* strcpy(char *destination, const char *source)`
两个参数目标地址和要追加的字符的地址。
返回目标空间的起始地址

字符串追加 函数

使用的注意事项

- 要追加的目标要有足够大的空间来存放追加的字符串
- 追加的字符串和被追加的字符串都要有\0
- 被追加的空间要能够被修改

模拟一下

```c
#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串追加
char* my_strcat(char* dest, const char* src)
{
	assert(dest&&src);
	char* ret = dest; 
	assert(dest && src);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{	
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "woaini";
	char arr2[] = "yuanzhiqi";
	my_strcat(arr1, arr2);
	printf("%s", arr1);

	return 0;
}

```

### strcmp

标准规定:
第一个字符串大于第二个字符串，则返回大于0的数字第一个字符串等于第二个字符串，则返回0
第一个字符串小于第二个字符串，则返回小于0的数字

这里的比较不是比较字符串长度，而是按位比较每位字节的大小（ascii码）

就比如abcq 比abdcef 大！

模拟实现strcmp

```c
#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串对比函数 strcmp模拟
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//相等且都为\0就不用往后比较了。
//		{
//			return 0; 
//		}
//		str1++;
//		str2++;
//	}
//	//不相等了则代表找到了
//	if (*str1 > *str2)//找一圈找到一个不一样的，判断大小然后返回值
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//可以改进一下
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')//相等且都为\0就不用往后比较了。
		{
			return 0; 
		}
		str1++;
		str2++;
	}
	//不相等了则代表找到了
	return (*str1 - *str2);
}

int main()
{
	char arr1[20] = "woaini";
	char arr2[] = "x";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
	{
		printf(">");
	}
	else if(ret < 0)
	{
		printf("<");
	}
	else
	{
		printf("=");
	}
	return 0;
}

```

### strncpy、strncat、strncmp

### strcpy、strcat、strcmp是不受限制的。如果目标承受不了会报错的

**所以我们可以使用长度受限制的函数：**
strncpy、strncat、strncmp 、他们在传参的时候回多一个无符号整形 num 。
意为cpy几个字符。追加几个字符。比较几个字符

### strstr

查找子串的一个函数

给一个字符串，在这个字符串里查找另一个字符串

返回这个子串的第一个字符的地址 char*的指针。

找不到则返回空指针NULL

模拟实现。

（但这个不是效率最高的。）

效率高的有KMP算法
这个算法也是用来实现在一个字符串中查找子字符串的
效率高，但是实现难度大
B站搜索：比特大博哥，可以找到KMP算法的实现

```c

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	//保证不会出现空指针访问
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	//p为假设从这里开始可以找到子字符串
	//如果一次没找就+1继续找，直到找到 \0的位置

	while (*p)//到\0则代表没找到。
	{
		s1 = p;//把指针s1赋值为p的位置，为这次重新查找子字符串做准备。
		s2 = str2;//重置待查找的字符串的指针
		while (*s1!='\0' && *s2!='\0' && *s1 == *s2)//如果子字符串和字符串的指针到\0 就停下，在此基础上如果相等就继续找下一个相等的
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//如果循环完了之后，待查找的子字符串的指针到\0就代表已经找到了。
		{
			return (char*)p;//返回p的地址，
		}
		p++;
	}
	return NULL;//没找到则返回空指针
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "def";
	char* ret = my_strstr(arr1, arr2);

	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}
```

### strtok

`char * strtok(char* *str,const char** sep);`

- 这个函数是用来 切割字符串用的。 **返回分隔符号前的字符串的第一个字符的地址**
- 但是需要注意这个函数是**会改原字符串**的，他会在你定义的分隔符的地方补`\0` 
所以在使用的时候要临时拷贝一份字符串，来对拷贝的字符串进行操作。不影响原字符串。
- 这个函数。传入的第一个参数是待查找的字符串、**第二个参数是可用作分隔符的一个字符集合**
字符集合这样写的 “@.” 这里面俩都是可以用作字符集合的。可以自己添加。
- 第一个参数传参的时候。传入的第一个变量有两种情况。
    - 第一种情况是：传入的变量是一个**字符串地址**，那么他会从字符串第一个字符开始查找，一直到找到分隔符号才停止。然后把这个分隔符变为`\0` 然后返回`\0` 左边的这个字符串的第一个元素的地址。首地址。**并且保存这次的分隔符号的地址。（是的，他是一个有记忆的函数。）**
    - 第二种情况是：传入的变量是一个**空指针。**那么他会从他上次记忆的分隔符号的地址的下一个地址开始找分隔符。直到找到一个分隔符，记住他的地址。然后替换为`\0`.  并返回这个这次开始查找到的字符串的首元素地址。
    
    我们可以使用for循环来用这个函数。不用写的一列一列的。
    
    ```c
    //
    //strtok
    //切割字符串
    //
    // zhangpengwei@bitejiuyeke.com
    
    int main()
    {
    	const char* sep = "@.";
    	char email[] = "zhangpengwei@bitejiuyeke.com.net";
    	char cp[40] = { 0 };//"zhangpengwei@bitejiuyeke.com"
    	strcpy(cp, email);
    
    	char* ret = NULL;
    	for (ret = strtok(cp, sep);
    		ret != NULL;
    		ret = strtok(NULL, sep))
    	{
    		printf("%s\n", ret);
    	}
    
    	//char* ret = strtok(cp, sep);
    	//if(ret != NULL)
    	//	printf("%s\n", ret);
    
    	//ret = strtok(NULL, sep);
    	//if (ret != NULL)
    	//	printf("%s\n", ret);
    
    	//ret = strtok(NULL, sep);
    	//if (ret != NULL)
    	//	printf("%s\n", ret);
    
    	//ret = strtok(NULL, sep);
    	//if (ret != NULL)
    	//	printf("%s\n", ret);
    
    	return 0;
    }
    ```
    

### strerror

设置错误码函数

C语言的库函数，在执行失败的时候，都会设置错误码函数。0 1 2 3 4 5 6 7 8 都是错误码

函数会自动设置。

使用示例，

```c
#include <errno.h>

int main()
{
	//printf("%s\n", strerror(0));
	//printf("%s\n", strerror(1));
	//printf("%s\n", strerror(2));
	//printf("%s\n", strerror(3));
	//printf("%s\n", strerror(4));
	//printf("%s\n", strerror(5));

	//errno - C语言设置的一个全局的错误码存放的变量

	FILE* pf = fopen("C:\\Users\\zpeng\\Desktop\\test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		//
	}
	return 0;
}
```

### **字符分类函数 <ctype.h>**

[**int isalnum(int c)**](https://www.runoob.com/cprogramming/c-function-isalnum.html)

该函数检查所传的字符是否是字母和数字。

[int isalpha(int c)](https://www.runoob.com/cprogramming/c-function-isalpha.html)

该函数检查所传的字符是否是字母。

[int iscntrl(int c)](https://www.runoob.com/cprogramming/c-function-iscntrl.html)

该函数检查所传的字符是否是控制字符。

[int isdigit(int c)](https://www.runoob.com/cprogramming/c-function-isdigit.html)

该函数检查所传的字符是否是十进制数字。

[int isgraph(int c)](https://www.runoob.com/cprogramming/c-function-isgraph.html)

该函数检查所传的字符是否有图形表示法。

[int islower(int c)](https://www.runoob.com/cprogramming/c-function-islower.html)

该函数检查所传的字符是否是小写字母。

[int isprint(int c)](https://www.runoob.com/cprogramming/c-function-isprint.html)

该函数检查所传的字符是否是可打印的。

[int ispunct(int c)](https://www.runoob.com/cprogramming/c-function-ispunct.html)

该函数检查所传的字符是否是标点符号字符。

[int isspace(int c)](https://www.runoob.com/cprogramming/c-function-isspace.html)

该函数检查所传的字符是否是空白字符。

[**int isupper(int c)**](https://www.runoob.com/cprogramming/c-function-isupper.html)

该函数检查所传的字符是否是大写字母。

[int isxdigit(int c)](https://www.runoob.com/cprogramming/c-function-isxdigit.html)

该函数检查所传的字符是否是十六进制数字。

---

标准库还包含了两个转换函数，它们接受并返回一个 "int”

[int tolower(int c)](https://www.runoob.com/cprogramming/c-function-tolower.html)

该函数把大写字母转换为小写字母。

[int toupper(int c)](https://www.runoob.com/cprogramming/c-function-toupper.html)

该函数把小写字母转换为大写字母。

### memcpy <string.h>

=memory   +  copy

他可以直接把内存中的数据拷贝。 而不是像“strcpy和strncpy”一样只能拷贝字符串

void * memepy  （void * destination,  const vo1d source,  size_t num );
目标内存地址，源空间内存地址。拷贝的字节数量

返回目标空间的起始地址

他是用来操作两个独立的内存空间的。把一个复制到另一个

**他在使用时最好不用对对重叠空间进行拷贝。有memmove**来进行拷贝。
但是你要是真的拿他来对他进行重叠空间的操作，也是可以的

自己写一个

```c
#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);//断言
	void* ret = dest;//存一下。

	while (num--)  // 4   3   2   1   1--为非
	{
		*(char*)dest = *(char*)src;//一个字节一个字节拷贝，不然分享个27就G了
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}

	return ret;//返回目标内存的地址
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1,2,1,2,3,4,5,8,9,10
//int arr2[10] = { 0 };
//my_memcpy(arr2, arr1, 28);
	my_memcpy(arr1 + 2, arr1, 20);
	//memcoy是对两个独立内存空间进行操作。
	//memcpy 负责拷贝两块独立空间中的数据
	//重叠内存的拷贝。是memmove ！！

	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
	//float arr4[10] = { 0.0 };
	//memcpy(arr4, arr3, 20);

	return 0;
}
```

### **memmove**

`void * memepy  （void * destination,  const vo1d source,  size_t num );`

参数都是和上面的memmove一样的。但是她是可以对重叠空间进行移动的。、

模拟实现一下。

```c
//memmove的模拟实现
//在memcpy函数中，面对重叠的内存空间就会不正确的发生赋值的情况。
//所以我们可以根据源地址和目标地址的位置情况来判断用从前往后复制，还是从后往前复制
//目标空间和源空间的指针地址重叠的时候不用讨论了。
//如果目标空间的起始地址小于源空间的地址，那么就从前往后 拷贝
//反之，则从后往前
//目的是为了在拷贝的过程中  在拷贝前不改变待拷贝的值。
#include<stdio.h>
#include<assert.h>
#include<string.h>

void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);//断言
	void* ret = dest;//存一下。
	
	if (dest < src)
	{
		//从前往后复制
		while (num--)  // 4   3   2   1   1--为非 //这里的字节是从前往后拷贝。
		{
			*(char*)dest = *(char*)src;//一个字节一个字节拷贝，不然分享个27就G了
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//从后往前复制。要想先找到最后一个。
		while (num--)  // 4   3   2   1   1--为非 //这里的字节是从前往后拷贝。
		{
			*((char*)dest + num) = *((char*)src + num);//从源头拿！！！一个字节一个字节拷贝，不然分享个27就G了
		}
	}

	return ret;//返回目标内存的地址
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1,2,1,2,3,4,5,8,9,10
//int arr2[10] = { 0 };
//my_memcpy(arr2, arr1, 28);
	my_memmove(arr1 + 2, arr1, 20);
	//memcoy是对两个独立内存空间进行操作。
	//memcpy 负责拷贝两块独立空间中的数据
	//重叠内存的拷贝。是memmove ！！

	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
	//float arr4[10] = { 0.0 };
	//memcpy(arr4, arr3, 20);

	return 0;
}
```

### memcom

`void * memepy  （const void * ptr1,  const vo1d ptr2,  size_t num );`

比较ptr1和ptr2开始   的 向后的num个字节的内容进行比较

如果大于则返回>0的数字。 = 返回0          小于则返回<0 的数字

### memset

`void *memset( void *ptr, int value, size t num );`

第一个参数：传入一个地址
第二个参数：要设置的值
第三个参数：设置的长度

用法。**只能在char字符串中**，五个字符改成x 
**不能来改int 。 他会改每个字节为x（的ascii码）**

   

### 一些作业题

把奇数变1  把偶数变 0

1 2 3   =  1 0 1

22222   =  0

```c

#include<stdio.h>
#include<math.h>

int main()
{
	int intput = 0;
	int sum = 0：
	scanf("%d", &intput);
	int i = 0;
	while (intput)
	{
		int a = intput % 10;//求出input各个位。
		if (a % 2 == 1) //则为奇数
		{
			//则对应的1添加到sum的个、十、百...上
			sum += 1 * pow(10, i);
			i++;//准备为10位上赋值做准备。
		}
		else//否则为偶数
		{
			//则对应的0添加到sum的个、十、百...上
			sum += 0 * pow(10, i);
			i++;//准备为10位上赋值做准备。
		}
		intput /= 10; 
	}
	return 0;

}
```

**实现一个函数。可以左旋字符串中k个字符**

```c
//实现一个函数。可以左旋字符串中k个字符
#include <stdio.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符。
//方法1
void left_rotate(char arr[], int k)
{
	int i = 0;
	int len = strlen(arr);
	k %= len;
	//节省资源。直接%字符长度
	for (i = 0; i < k; i++)//左移k次
	{
		char tmp = arr[0]; //把第一个字符存起来
		int j = 0;  
		for (j = 0; j < len - 1; j++)//把剩下的字符整体左移一次。
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;//把刚才存起来的放到最后一个元素的位置。
		//综上，为一次左移
	}
}

//方法2
#include <assert.h>

//反转两个地址之间的元素
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
//通过revese函数来进行三次反转  
// 以左旋转n次后的点位的左边进行反转、右边进行反转
//然后整体进行反转
void left_rotate(char arr[], int k)
{
	int len = strlen(arr);
	k %= len;
	//节省资源。直接%字符长度

	reverse(arr, arr + k - 1);//左
	reverse(arr + k, arr + len - 1);//右
	reverse(arr, arr + len - 1);//整
}

int main()
{
	char arr[] = "abcdef";//cdefab
	int k = 0;
	scanf("%d", &k);//2
	left_rotate(arr, k);
	printf("%s\n", arr);

	return 0;
}
```

杨氏矩阵找数字

```c
//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
//时间复杂度，。有九个东西，至多要找9次，才能找到。那么9就是时间复杂度n

//1 2 3
//4 5 6
//7 8 9

//采用先找最右边的列、如果小于列。那么肯定不在这一列了。
// 如果大于列。那么继续向下找，找到小于的情况。
// 如果找到行号2都小于0了、或者列都大于列2 了，就代表没有
int find_num(int arr[3][3], int r, int c, int k)
{
	int x = 0;//初始的行
	int y = c - 1;//初始的列。 在右上角
	while (x<=r-1 && y>=0)//定义停止的条件
	{
		if (k < arr[x][y])//如果小于现在的列  右上角
		{ 
			y--; //那么就往左走。因为刚才那一列肯定都没有
		}
		else if (k > arr[x][y])//如果大于，则继续往下找
		{
			x++;//往下找
		}
		else//上面两个条件都不满足，只能是等于了。
		{
			return 1;//如果这些条件都不满足。//然后就返回1告诉他我找到了
		}
	}
	return 0;//找不到
}

struct Point
{
	int x;
	int y;
};

struct Point find_num(int arr[3][3], int r, int c, int k)
{
	int x = 0;
	int y = c - 1;
	struct Point p = { -1, -1 };
	while (x <= r - 1 && y >= 0)
	{
		if (k < arr[x][y])
		{
			y--;
		}
		else if (k > arr[x][y])
		{
			x++;
		}
		else
		{
			p.x = x;//把返回值发送到全局变量的结构体中
			p.y = y;
			return p;//返回结构体
		}
	}
	return p;//找不到
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	scanf("%d", &k);
	struct Point ret = find_num(arr, 3, 3, k);
	printf("%d %d\n", ret.x, ret.y);
	return 0;
}

//返回型参数

int find_num(int arr[3][3], int *px, int*py, int k)//输入参数变成函数外的变量的地址
{
	int x = 0;
	int y = *py - 1;//根据传入的行和列来定义右上角
	while (x <= *px - 1 && y >= 0)
	{
		if (k < arr[x][y])
		{
			y--;
		}
		else if (k > arr[x][y])
		{
			x++;
		}
		else
		{
			*px = x;//把找到的坐标传给x 和y
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;//找不到
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	scanf("%d", &k);
	int a = 3;//行
	int b = 3;//列
	int ret = find_num(arr, &a, &b, k);
	if (ret == 1)
		printf("%d %d\n", a, b);
	else
		printf("找不到\n");

	scanf("%d", &k);//再次输入需要重新初始化行和列。不然会传入错误的行和列
	a = 3;
	b = 3;
	ret = find_num(arr, &a, &b, k);
	if (ret == 1)
		printf("%d %d\n", a, b);
	else
		printf("找不到\n");
	return 0;
}
```

先输入矩阵的列、在输入行、然后按照行再列的方式已打印

```c

#include<stdio.h>
//先输入矩阵的列、在输入行、然后按照行再列的方式已打印
int main()
{
	int arr[2][3] = {0};
	int j = 0;
	int i = 0;
	for (j = 0; j < 3; j++)
	{
		 for (i = 0; i < 2; i++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 2; i++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");

	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
```

# 四、自定义类型详解（结构体、枚举、联合）

本章重点

- 结构体
    - 结构体类型的声明
    - 结构的自引用
    - 结构体变量的定义和初始化
    - 结构体内存对齐
    - 结构体传参
    - 结构体实现位段(位段的填充&可移植性)
- 枚举
    - 枚举类型的定义
    - 枚举的优点
    - 枚举的使用
- 联合
    - 联合类型的定义
    - 联合的特点
    - 联合大小的计算

## 结构体struct

### 1 结构体的声明

结构体的基础知识：
结构是一些值的集合，这些值被称为成员变量，结构的成员可以是不同类型的值
结构体的变量是全局变量还是局部变量。取决于变量放的位置。

### 2 匿名结构体类型

没有名字的结构体叫匿名结构体类型。他只能用一次

### 3 结构体的自引用

数据结构
数据在内存中的存储结构

- 线形
    - 顺序表
        
        在内存中连续存放。1 2 3 4 5
        
    - 链表
        
        让1能找到2 ，让2 能找到3.  3能找到4    4能找到5  这样叫链表
        放下一个节点的地址。
        这个结构体的一个部分存**数据**—-指针域
        另一个存放另一个节点的**地址**——-指针域
        
- 树形
    - 二叉树

### 4 结构体的初始化

不记了。跟二维数组那种差不多，嵌套的时候也是一样的。{ {} ， x  , }

### 5 结构体内存对齐

计算结构体的大小

结构体的成员相同，但是顺序不同 。他们所占用的字节大小也是不同的。 

结构体的对齐就是探讨这方面的知识的。

结构体的一些成员。必须存储在某一些对齐的位置以上才可以

**首先得掌握结构体的对齐规则:**

1. 第一个成员在与结构体变量偏移量为0的地址处。
2. 其他成员变量要对齐到某个数字(对齐数)的整数倍的地址处。对齐数=编译器默认的一个对齐数 与 该成员大小的较小值。
    1. VS中默认的值为8
3. **结构体总大小**为最大对齐数(每个成员变量都有一个对齐数)的整数倍。
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍。

> **使用offsetof可以查看结构体成员在结构中的偏移量**
> 
- **为什么存在内存对齐?**

大部分的参考资料都是如是说的:

1. 平台原因(移植原因):
不是所有的硬件平台都能访问任意地址上的任意数据的;某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
2. 性能原因
    
    数据结构(尤其是栈)应该尽可能地在自然边界上对齐。 原因在于，为了访问未对齐的内存，处理器需要作**两次**内存访问;而对齐的内存访问**仅需要一次访问**。
    

**结构体的内存对齐是拿空间来换取时间的做法。**

那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：

> 让占用空间小的成员尽量集中在一起
> 

> `#pragma pack(8) //设置默认对齐为8`
> 

### 6 结构体传参

两种方法：传址和传值调用

传值调用时用  .   
这个会对系统内存有较大开销

传址调用是用 ->    
优选传址调用传址调用，并且在后边加上const来保证参数不被修改

### 7 位段

**什么是位段**

**位段的声明:**

位段成员必须是整形家族

位段的成员后面有一个冒号和数字

：3 意思是给他分配 3 个 比特位   （例如存储真、假）

位段是一种节省空间的做法。在开辟时。他是看到是啥类型的就先开辟啥类型，同类型就往里边赛。如果不够就再开辟一个整形。

一般情况下位段是同一类型的东西放到一块儿~

位段是不跨平台的。 跨平台性不好。
1. int位段被当成无符号还是有符号，未被定义
2. 从左向右还是从右向左未被定义
3. 最大位数不确定。16位、32位、64位、最大数不一样
4. 对于无法容纳的成员，是舍弃还是利用。是重新分配 还是再次开辟不确定

### 静态通讯录的实现、自定义通讯录大小。名称年龄上限等…

**Contacts.c**

```c
#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
//实现一个通讯录
//存放人的信息
//人的信息有：姓名、年龄、电话、地址
// 功能：存放100个人的信息、增加联系人、
// 删除指定联系人、查找联系人、
// 修改联系人、排序、显示联系人

//菜单
void menu()
{
	printf("*****************************************\n");
	printf("*****  1. add            2. dle     *****\n");
	printf("*****  3. edit           4. search  *****\n");
	printf("*****  5. show           6. sort    *****\n");
	printf("*****************************************\n");
}

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//使用memset来设置单位字节为0
}

//添加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//满了就停
	{
		printf("联系人已满。无法添加\n");
		return;
	}
	else
	{
		//在下标为count的位置添加
		printf("请输入姓名:>");
		scanf("%s", pc->date[pc->count].name);
		printf("请输入年龄:>");
		scanf("%d", &pc->date[pc->count].age);//这里需要取地址，age是int型，其余为数组
		printf("请输入性别:>");
		scanf("%s", pc->date[pc->count].gender);
		printf("请输入电话:>");
		scanf("%s", pc->date[pc->count].phone);
		printf("请输入地址:>");
		scanf("%s", pc->date[pc->count].address);
	}
	pc->count++;
	printf("录入成功\n");

}

//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
										pc->date[i].name,
										pc->date[i].age,
										pc->date[i].gender,
										pc->date[i].phone,
										pc->date[i].address);
	}
}

int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)//如果=0就代表下标为i的结构体数组的名字与要查的一样
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc ->count == 0)
	{
		printf("通讯录中没有信息,不能删除\n");
		return;
	}
	else//输入名字来删除
	{
		printf("请输入要删除的人的名字:>");
		scanf("%s", name);
		int i = 0;

		//从0到count遍历一下，查找名字
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}

		//删除:直接让后面一位覆盖前面
		//从要覆盖的哪一位开始。i不用动
		for (i = ret; i < pc ->count - 1; i++)//这里虽然最后一位没动，但是我们又不用看它
		{
			pc->date[i] = pc->date[i + 1];
		}
		pc->count--;

		printf("删除成功\n");
	}
}

//编辑联系人
void EditContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录中没有信息,不能编辑\n");
		return;
	}
	else//输入名字来删除
	{
		//输入
		printf("请输入要编辑的人的名字:>");
		scanf("%s", name);
		int i = 0;
		//查找
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}
		printf("当前联系人信息\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
												pc->date[ret].name,
												pc->date[ret].age,
												pc->date[ret].gender,
												pc->date[ret].phone,
												pc->date[ret].address);
		//编辑
		printf("请输入修改后的姓名:>");
		scanf("%s", pc->date[ret].name);
		printf("请输入修改后的年龄:>");
		scanf("%d", &pc->date[ret].age);
		printf("请输入修改后的性别:>");
		scanf("%s", pc->date[ret].gender);
		printf("请输入修改后的电话:>");
		scanf("%s", pc->date[ret].phone);
		printf("请输入修改后的地址:>");
		scanf("%s", pc->date[ret].address);

		printf("编辑成功\n");
	}
}

//搜索联系人
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录中没有信息,不能搜索\n");
		return;
	}
	else//输入名字来删除
	{
		//输入
		printf("请输入要搜索的人的名字:>");
		scanf("%s", name);
		int i = 0;
		//查找
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}
		printf("搜索得到联系人信息如下：\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
												pc->date[ret].name,
												pc->date[ret].age,
												pc->date[ret].gender,
												pc->date[ret].phone,
												pc->date[ret].address);
	}
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	//对比人的信息结构体中名字元素的ascii码然后升序排序
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
	//返回大于0、小于0、等于0；
}

//通讯录升序排序
void SortContact(Contact* pc)
{
	//使用qsort来排序
	//排序数据的起始位置、元素个数、元素大小以及自定义的比较函数指针。
	qsort(pc->date, pc->count, sizeof(peoinfo), cmp_peo_by_name);
	printf("排序成功。当前为升序");
}
```

**Contacts.h**

```c
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100		//通讯录 最大 存储人数
#define NAME 20		//通讯里 姓名 最大字符串长度
#define GENDER 10	//通讯录 性别 最大字符串长度
#define PHONE 12	//通讯录 电话 最大字符串长度
#define ADDRESS 20	//通讯录 地址 最大字符串长度

//通讯录菜单
void menu();

//定义通讯录的人的信息的结构体
typedef struct peo
{
	char name[NAME];
	int age;
	char gender[GENDER];
	char phone[PHONE];
	char address[ADDRESS];
}peoinfo;

//定义通讯录的结构体
typedef struct Contact
{
	peoinfo date[MAX];//MAX个人的数据
	int count;//计数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//编辑联系人
void EditContact(Contact* pc);

//搜索联系人
void SearchContact(Contact* pc);

//通讯录排序
void SortContact(Contact* pc);
```

游戏测试文件**test.c**

```c
#define _CRT_SECURE_NO_WARNINGS

#include "Contacts.h"

int main()
{
	Contact con;//创建了一个通讯录
	InitContact(&con);//初始化通讯录
	int input = 0;
	do
	{
		menu();
		printf("请输入功能>:");	
		scanf("%d", &input);
		switch (input)
		{
		case 1://add联系人
			AddContact(&con);
			break;
		case 2://删除联系人
			DelContact(&con);
			break;
		case 3://编辑联系人
			EditContact(&con);
			break;
		case 4://搜索联系人
			SearchContact(&con);
			break;
		case 5://显示通讯录
			ShowContact(&con);
			break;
		case 6://通讯录按照名字升序
			SortContact(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}
```

## 枚举menu

有些值是可以一一列举出来的。这时就能用枚举了。

和结构体类似，他的后面是 ，   默认%d打印从 0 开始。他是一个图纸。不占用空间

只有当用这个图纸创建一个枚举变量的时候他才会像内存申请空间。

在 ， 的后面加 数字 可以自定义他的数字 不是从 0 开始的， .

枚举的好处

1. 增加代码的可读性和可维护性
2. 和#define定义的标识符比较，枚举有类型检查，更加严禁
3. 防止了命名污染
4. 便于调试，用枚举的时候，不会替换
5. 使用方便，一次可以定义多个常量

## 联合（共用体）union

联合也是一种特殊的自定义类型

这种类型定义的变量也包含一系列的成员，

特征是这些成员 共用同一块空间 (所以联合也叫共用体)

**联合体的特点：**

> ,联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小(因为联合至少得有能力保存最大的那个成员)。
并且他也存在对齐。
vs 默认的对齐是8。用的时候要除以一下最大的对齐数。
联合体在计算大小的时候也存在内存对齐。
> 

他的大小是最大的那个成员。在用的时候只能同时一个人用。用完就会覆盖。

他们每个成员的地址是相同的。

**用联合体的思想写一个判断大小端的函数**

```c
//使用联合体来判断你大小端

#include <stdio.h>

int check_sys()
{
	union  //匿名类型也可以，反正我就用一次 不用命名
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}

int main()
{

	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端");
	}
	else
	{
		printf("大端");
	}
	return 0;
}
```

# 五、 动态内存管理

本章重点：

- 为什么存在动态内存管理
- 动态内存管理的介绍
    - malloc
    - colloc
    - realloc
    - free
    
    他们申请的空间是在**堆区**里的
    
- 常见的动态内存错误
- 柔性数组

## 为什么存在动态内存管理

空间开辟大小是固定的。是不能改变的
数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。

## 动态内存管理的介绍

### 1、malloc    <stdlib.h>    不会初始化

`void* malloc(size_t size)` 

申请zize个字节的内存。
返回一个void*的指针，指向这个新开辟的内存的起始位置的地址。

如果开辟失败，就返回空指针。

如果size为0，这个是未被定义的。取决于编译器。

**malloc的使用**

```c
//malloc的使用

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int arr[10] = { 0 };
	//动态内存开辟
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//使用开辟的内存
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	//使用完之后没有还，没有用free。
	//但是在程序关闭的时候，分配的空间也是会还回去的，
	//但倘若程序在一直走，并且没有还空间。他还不用。
	//那么这个空间 就叫做内存溢出了， 别人也用不了。	
	//在C语言初阶笔记中，有这么一句话
	//堆区：它是由操作系统管理的，
	// 但分配和释放操作由程序员通过代码显式完成，
	// 通常使用malloc()、calloc()分配内存，使用free()释放内存。
	// 堆内存地址由低到高增长，适合存储大数据或生命周期长的对象，
	// 但需注意内存泄漏问题。
	//释放空间用free(p);
	free(p);//但是p内存的地址是不会变的。
	p = NULL;//把p赋值为空指针。
	return 0;
}

```

使用完之后没有还，没有用free。
但是在程序关闭的时候，分配的空间也是会还回去的，
但倘若程序在一直走，并且没有还空间。他还不用。
那么这个空间 就叫做内存溢出了， 别人也用不了。	
在C语言初阶笔记中，有这么一句话
堆区：它是由操作系统管理的，
但分配和释放操作由程序员通过代码显式完成，
通常使用malloc()、calloc()分配内存，使用free()释放内存。
堆内存地址由低到高增长，适合存储大数据或生命周期长的对象，
但需注意内存泄漏问题。
释放空间用free(p);

### 2、free  <stdlib.h>

C语言提供的用来动态内存的释放和回事用的函数

`void free(void* ptr);`
free函数用来释放动态开辟的内存。
如果参数 ptr指向的空间不是动态开辟的，那free函数的行为是未定义的。
如果参数 ptr 是NULL指针，则函数什么事都不做。

malloc和free都声明在 stdlib.h头文件中。

> free 只能释放动态开辟出来的空间！！
> 

### 3、calloc  <cstdlib>    = malloc + memset  他会会初始化为0.

`void* calloc(sizet num, size_t size);`  

num：要开辟几个元素

size：每个元素的大小

void* 返回开辟好的空间的起始地址

他在返回地址之前，**会初始化**

使用案例

```c
//calloc的使用
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	//开辟空间
	int* p = calloc(10, sizeof(int));//开辟10个int型的空间
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//打印
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));//打印出0 0 0 0 0 0 0 0 0 0 
	}
	//释放
	free(p);
	p = NULL;

	return 0;
}

```

### 4、realloc

realloc函数的出现让动态内存管理更加灵活。

有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，

那为了合理的时候内存，我们一定会对内存的大小做灵活的调整。

那rea11oc 函数就可以做到对动态开辟内存大小的调整。
函数原型如下:

`void* realloc(void* ptr, size_t size)`

第一个参数：**要修改的空间的起始地址。**

第二个参数：希望把它调整为多大的新的空间。

返回的类型是新的地址，或者原地址不变。理由如下：

realloc在追加字节的时候有两种情况。
一种情况是在追加时。后面能用的是不够的。因为后面有正在使用的内存空间。如果使用就覆盖掉了

- **这种情况。他会去找一片新的空间，然后把旧的空间的数据拷贝过来。然后返回新的地址。并且帮你把旧的空间释放掉。**
    - 在接收新的地址的时候，**不能用原来的指针变量来接收**。因为当realloc申请的空间过大。会申请失败，realloc会返回空指针！！！**这样就把原来的地址也忘了！**
    - 要用新的指针来接收新的地址。在判断不是空指针后，在把新的地址覆盖到原来的地址上，能保证不忘记原来的地址！！
    
    ```c
    	//扩容
    	int* ptr = (int*)realloc(p, 80);//把p所指向的空间调整为80个字节
    	if (ptr != NULL)//保护p的地址不为空
    	{
    		p = ptr;
    	}
    ```
    

另一种该情况是空间是够得。后面没有正在使用的内存空间，直接扩容。地址不变。

**realloc的使用**

```c
//relloc的使用
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	int* p = (int*)malloc(40);//申请40个字节大小的空间
	if (p == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	//赋值
	//赋值40个字节为1 2 3 4 5 6 7 8 9 10
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1;
	}
	//扩容
	int* ptr = (int*)realloc(p, 80);//把p所指向的空间调整为80个字节
	if (ptr != NULL)//保护p的地址不为空
	{
		p = ptr;
	}
	//使用
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p == NULL;
	return 0;
}
```

## 常见的动态内存错误

1. 对NULL进行解引用操作
这里的p可能为空指针， 应该先判断再赋值
    
    ```c
    void test()
    {
    	int* p = (int*)ma110c(INT_MAX / 4);
    	*p = 20;//如果p的值是NULL，就会有问题
    	free(p);
    }
    ```
    
2. 对动态开辟空间的越界访问
这里开辟了10个字节，但访问了11个字节

```c
int main()
{
int* p = (int*)malloc(40); 
if (p == NULL)
{
	printf("%s\n", strerror(errno));
	return 1;
}
	//方式
	int i =0;
	for (i = 0; i <= 10; i++)
	{
		p[i] = i;
	}
	free(p);
	p = NULL;
return 0;
}
```

1. 对非动态开辟内存使用free释放
这里的p不是动态开辟的内存。会报错

```c
int main()
{
	int a = 10;
	int* p = &a; 
	//....
	free(p);
	p = NULL; 
	
	return 0;
}
```

1. 使用free释放一块动态开辟内存的一部分
这里的p在程序运行中移动了。不再指向起始位置，会报错

```c
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 1;
	}
	//使用
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*p = i;
		p++;
	}
	//释放
	free(p);
	p = NULL;
	return 0;
}
```

1. 对同一块的动态内存多次释放
释放再次释放就会报错！所以在释放空间后，应该把p赋值为空指针， 如果不弄成空指针，p就是野指针！

```c
int main()
{
	int* p = (int*)malloc(40);
	//..
	free(p);
	//..
	free(p);
	return 0;
}
```

1. 动态内存开辟后忘记释放造成**内存泄漏**

## 柔性数组

> 柔性数组(flexible array)
C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员
> 

```c
typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;
```

有些编译器会报错，那么可以改成

```c
typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;
```

柔性数组的特点

- 结构中的柔性数组成员**前面必须至少一个其他成员**
- **sizeof 返回的这种结构大小不包括柔性数组的内存。sizeof不会算柔性数组的内存进去**
- 包含柔性数组成员的结构**应该用malloc()函数进行内存的动态分配，**
并且分配的内存**应该大于结构的大小，以适应柔性数组的预期大小。**

柔性数组的优势

**第一个好处是:方便内存释放**
如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
**第二个好处是:这样有利于访问速度**
连续的内存有益于提高访问速度，有益于减少内存碎片。(其实，我个人觉得也没多高了，反正你跑不了要用做偏移量的加法来寻址)

# 六、语言文件操作

**本章重点**

1. 为什么使用文件
2. 什么是文件
3. 文件的打开和关闭
4.  文件的顺序读写
5. 文件的随机读写
6. 文本文件和二进制文件
7. 文件读取结束的判定
8. 文件缓冲区

## 1. 为什么使用文件

使用文件我们可以将数据直接存放在电脑的硬盘上，做到了数据的持久化。

## 2.什么是文件

但是在程序设计中，我们一般谈的文件有两种：程序文件和数据文件
(从文件功能的角度来分类的)

程序文件比如，`.c`  `.exe`等等..

数据文件是程序在运行时**读写（输入）**的程序，
或者用来**输出（写）**内容的文件

## 3.文件的打开和关闭

### 操作文件的步骤

1. 打卡文件
2. 对文件进行读或者写
3. 关闭文件

### 文件指针

缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针"

每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信

(如文件的名字，文件状态及文件当前的位置等)。

这些信息是**保存在一个结构体变量**中的。该结构体类型是有系统声明的，取名FILE.

每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，
并填充其中的信息
**使用者不必关心细节。**

一般都是通过一个FLE的指针来维护这个FILE结构的变量，这样使用起来更加方便。

定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区(是一个结构体变量)。通过该文件信息区中的信息就能够访问该文件。也就是说，

**通过文件指针变量能够找到与它关联的文件。**

**也就是说，当你用`FILE*`的指针变量来指向一个文件的时候。实际上他指向的 是存在内存中的文件信息区。文件信息区会自动的 关联到你想指向的文件，然后来操作文件**

任何一个c程序，只要运行起来就会默认打开3个流:

FILE*stdin -标准输入流(键盘)
FILE* stdout -标准输出流(屏幕)
FILE* stderr -标准错误流(屏幕)

### 文件的打开和关闭

文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
在编写程序的时候，在打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针和文件的关系。
ANSIC 规定使用**fopen函数来打开文件，fclose来关闭文件。**

**也就是说，当你用`FILE*`的指针变量来指向一个文件的时候。实际上他指向的 是存在内存中的文件信息区。文件信息区会自动的 关联到你想指向的文件，然后来操作文件**

**打开 fopen**

`FILE * fopen ( const char* *filename, const char** mode );`

*filename为文件名*

mode 为打开模式（读或写）

**打开失败会返回空指针**

mode的参数可以为如下。记得带`“”`

| 文件使用 | 含义 | 如果指定文件不存在 |
| --- | --- | --- |
| “r” | 为了输入数据，打开已存在的文本文件 | 出错 |
| “w” | 为了输出数据，打开一个文本文件 | 建立一个新的文件 |
| “a” | 向文本文件尾添加数据 | 建立一个新的文件 |
| “rb” | 为了输入数据，打开一个二进制文件 | 出错 |
| “wb” | 为了输出数据，打开一个二进制文件 | 建立一个新的文件 |
| “ab” | 向一个二进制文件尾添加数据 | 出错 |
| “r+” | 为了读和写，打开一个文本文件 | 出错 |
| “w+” | 为了读和写，建议一个新的文件 | 建立一个新的文件 |
| “a+” | 打开一个文件，在文件尾进行读写 | 建立一个新的文件 |
| “rb+” | 为了读和写打开一个二进制文件 | 出错 |
| “wb+” | 为了读和写，新建一个新的二进制文件 | 建立一个新的文件 |
| “ab+” | 打开一个二进制文件，在文件末尾读和写 | 建立一个新的文件 |
|  |  |  |

## 4.文件的顺序读写

功能

字符输入函数

字符输出函数

文本行输入函数

文本行输出函数

格式化输入函数

格式化输出函数

二进制输入

二进制输出

函数名
fgetc

fputc

fgets

fputs

fscanf

fprintf

fread

fwrite

适用于

所有输入流

所有输出流

所有输入流

所有输出流

所有输入流

所有输出流

文件

文件

### **fputc  写一个数据**

`int fputc ( int character, FIlE* stream);`

 第一个参数是int、第二个参数是FILE类型的文件指针
成功则返回写入的字符

在同一段程序中多次使用，则在同一行后追加

### **fgetc 读一个数据**

`int fgetc(FILE * stream ).`

参数是文件指针。
成功则返回读到的字符类型为int
如果成功读取，他的内部文件指针会推进到下一个字符
也就是说下次读写会读写这次读写的下一个字符

读取失败则返回EOF

那么我们就可以写一个while循环，直到他读取到EOF才停下

### fputs 写一行数据
`int fputs ( const char * str, FILE * stream );`

第一个参数是写一个字符串，第二个参数是关联到那个文件（文件指针）

成功返回一个非负值、失败返回EOF、

字符串中的\0不会被写入进去

在同一段程序中多次使用，则在同一行后追加

**可以自己使用\n来换行**

### fgets 读一行数据
`char * fgets ( char * str, int num, FILE * stream );`

第一个参数是把读到的东西放到str所指向的空间当中

第二个参数是最多读这么多的数字**减一**.因为要留一个来放\0

成功则返回存放字符串的地址str的地址。

失败则返回空指针

### fprintf 格式化输出函数
`int fprintf ( FILE * stream, const char * format, ... );`

第一个参数是要写入的文件，后面的和printf使用方法一样。

返回值是字符总数。

### fscanf 格式化输入函数
`int fscanf ( FILE * stream, const char * format, ... );`

第一个参数是要读取的文件，后面的和scanf使用方法一样。

### fwrite 二进制输出
`size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );`

第一个参数是要写入的数据的起始位置

第二个参数是每个元素有多大

第三个参数是有多少个元素要输出

第四个参数是写入的文件流指针。

### fread 二进制输入
`size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );`

第一个参数是要输入的起始地址

第二个参数是每个元素有多大

第三个参数是有多少个元素要输入

第四个参数是写入的文件流指针。

### **sscanf   针对字符串，不针对文件和流**
`int sscanf ( const char * s, const char * format, ...);`

**从一个字符串中转换出一个格式化的数据**

**从字符串中获取一个格式化的数据到另一个地方。**

### **sprintf  针对字符串，不针对文件和流**
`int sprintf ( char * str, const char * format, ... );`

**写格式化的数据到一个字符串里去**

**把一个格式话的数据写到字符串中** 

使用举例

```c
int main()
{

	struct S s = { 10,"nihao",13.14f };
	struct S tmp = { 0 };
	char buf[100] = { 0 };

	//sprintf的使用
	//把s中格式化的数据转换成字符串放到buf中
	sprintf(buf, "%d %s %f", s.a, s.arr, s.b);
	printf("%s\n", buf);
	//sprintf的使用
	//从字符串buf中获得格式化的数据放到tmp中
	sscanf(buf, "%d %s %f", &(tmp.a), tmp.arr, &(tmp.b));
	printf("%d %s %f", tmp.a, tmp.arr, tmp.b);
	return 0;
}	
```

## 5.文件的随机读写

> fseek
> 

根据文件指针的位置和偏移量来定位文件和指针
`int fseek ( FILE * stream, long int offset, int origin );`

第一个参数，操作那个文件流？

第二个参数，偏移量是多少

第三个参数，

| 常数 | 参考位置 |
| --- | --- |
| SEEK_SET | 文件的开始 |
| SEEK_CUR | 文件指针的当前位置 |
| SEEK_END | 文件的末尾 |

> ftell
> 

返回文件指针相对于文件起始位置的偏移量
`long int ftell ( FILE * stream );`

> rewind
> 

让文件指针回到文件的起始位置
`void rewind ( FILE * stream );`

## 6.文本文件和二进制文件

根据数据的组织形式，**数据文件被称为文本文件或者二进制文件。**

数据在内存中以二进制的形式存储，**如果不加转换的输出到外存，就是二进制文件。**

**如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。以ASCII字符的形式存储的文件就是文本文件**。

一个数据在内存中是怎么存储的呢?

字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。

如有整数10000，如果以ASCI码的形式输出到磁盘，则磁盘中占用5个字节(每个字符一个字节)，而二进制形式输出，则在磁盘上只占4个字节(VS2013测试)。

10000在内存中为00000000 00000000 00100111 00010000

二进制形式储存是00000000 00000000 00100111 00010000

ASCII形式存储是00110000 00110000 00110000 00110001 00110000
是把每个数字当成一个字符存储。存储的是ASCII码

## 7.文件读取结束的判定

### 7.1被错误使用的feof

牢记：在文件读取的过程中，不能用feof函数的返回值来判断文件是否结束

**而是应用于文件读取结束的时候，用它来判断是读取失败结束，还是遇到文件末尾。**

1. **文本文件**读取是否结束，**判断返回值是否为E0F(fgetc)， 或者 NULL(fgets )**
    
    例如:
    
    fgetc判断是否为 EOF
    ofgets 判断返回值是否为 NULL.
    
2. **二进制文件**的读取结束判断，判断返回值是否小于实际要读的个数。
    
    例如:
    
    fread判断返回值是否小于实际要读的个数。
    

### 8.文件缓冲区

ANSIC 标准采用**“缓冲文件系统”**处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程)中每一个正在使用的文件开辟一块**“文件缓冲区”**。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(程序变量等)。缓冲区的大小据C编译系统决定的。

# 七、程序环境和预处理

## 1 编译和链接

每个源文件都会单独经过**编译器**编译成**目标文件，后缀为.obj  （linux为 . o）**

最后目标文件会经过**链接器**，加上链接库  链接成可执行程序  .exe文件

其中编译分为三个阶段

1. 预编译/预处理 
头文件的包含、这一步会删除#define 和注释//
2. 编译
把C语言代码编译为汇编代码
3. 汇编
把汇编代码转换成二进制的机器指令

链接是吧多个目标文件和链接库链接输出成可执行文件 .exe

它分为两个阶段

1. 合并段表（每个函数都有一个地址，如果地址对不上啥的就会报错）
2. 符号表的合并和重定位

## 2 #define

#define 定义的后面最好不要加；容易出现问题

## 3 #define 定义宏

#define 机制包括了一个规定：
允许把参数**替换**到文本中，
这种实现通常称为宏(macro)或定义宏(define macro)

申明方式如下

`#define name( parament-list )stuff`
注意宏名和左括号要临近，不能加空格

分别是宏名   宏体    和参数

比如一个x * x 的一个宏

`#define SQUARR（X）  ( (x）*（x）)` 
注意在参数部分加括号！！在参数部分不能吝啬括号，不然会因为优先级的问题出问题.外圈和内圈都要加括号

使用是这样的

`int r = SQUARR(5）;` 

结果r为25

## 4 # 和 ##

### #

#可以在宏中把参数插入到字符串中。例如#n它相当于“n”

举个栗子

```c
#include <stdio.h>

#define PRINTF(N) printf("我是"#N"\n")

int main()
{
	PRINTF(小明);
	PRINTF(小红);
	PRINTF(小刘);

	return 0;
}
```

他的输出的是

```c
我是小明
我是小红
我是小刘
```

### ##

##可以把两边的符号合并成一个符号

```c
#include <stdio.h>

#define ABC(A,B) A##B

int main()
{
	int abc = 1000;
	printf("%d\n", ABC(a, bc));
	//这里的传入的a和bc被##合并成一个符号了
	//等同于printf("%d\n",abc));
	return 0;
}
```

## 5 宏和函数的命名约定

宏的名字全大写

函数的名字不全大写

## 6 undef 移除宏定义

undef + 宏名

消除宏

## 7.条件编译

### 根据宏定义的条件输出

```c
#include <stdio.h>

#define DEBUG1
//#define DEBUG2

int main()
{
#ifdef DEBUG1
	printf("你好\n");
#endif // DEBUG

#ifdef DEBUG2
	printf("世界\n");
#endif // DEBUG

	return 0;
}
```

这里的输出为你好。

也可以用 #if  和 #endif

### 在单片机中有一段是这里用到的！！

```c
//单片机中经常实用的
#ifndef __NAME__//如果NAME没有被定义，那么就执行中间的 定义然后一些函数
//如果被定义了。那么#ifndef __NAME__为假。 就可以不被重复定义！！！
#define __NAME__

//这里函数的声明
int xxxx(int x, int y);

#endif // 
```

## 头文件<>和“”的区别

他们的查找策越不一样

<>是去库里查找

“”是先去代码所在的路径下查找，如果找不到，再去库目录下查找。

> 完结撒花。去学32 了
>