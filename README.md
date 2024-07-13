> 

> ### 我把后续所有笔记放到了[我的CSDN博客](https://blog.csdn.net/L_Z_J_I/article/details/140400417?spm=1001.2014.3001.5502)中


> ### 这个README文件不再更新。
>  **所有的代码被我提交到了这个仓库的 :[code分支](https://gitee.com/Xiao____liu/learning---c-language/tree/code/)中去了** 
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
> -
这些是我在学习C语言的过程中自己练习的一些题目

大家也可以参考着来学习

## 初认C语言

### printf打印小飞机

> 2024-07-09
> 

```
#include <stdio.h>
int main() {

    printf("     **     \n");
    printf("     **     \n");
    printf("************\n");
    printf("************\n");
    printf("    *  *    \n");
    printf("    *  *    \n");
    return 0;
}
```

### 输入两个数，输出商和余数

> 2024-07-09
> 

```
#include "stdio.h"

int main()
{
    int a = 0;
    int b = 0;
    //输入整数a和b 其中a>0  b<10,000
    scanf("%d %d", &a, &b);
    //计算输出
    printf("%d %d",a/b,a%b);
    return 0;
}
```

### 根据ASCII码输出字符

> 2024-07-09
> 

```
#include <stdio.h>
int main() {
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33);
    return 0;
}
```

- 输出时常用到的如下：
- **%c** 字符型格式符，作用是读入一个字符。
- **%d** 表示输出十进制有符号的整数。
- **%u** 十进制无符号整数。
- **%f** 表示输出浮点数。
- **%s** 表示输出 字符串。
- **%c** 表示输出单个字符。
- **%p** 表示输出指针的值。
- **%e** 表示输出指数形式的浮点数。
- **%0x** 表示输出无符号以十六进制表示的整数。
- **.%0** 表示输出无符号以八进制表示的整数。

### 出生日期输入输出

> 2024-07-09
> 

**输入描述：** 输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
**输出描述：** 三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。

```c
#include <stdio.h>
int main()
{
    int date;
    //输入(19991123)
    scanf("%d", &date);
    //除10000，让小数点左移四位，保留年份
    //除100，让小数点左移两位，保留年份和月份。再对100取模，保留百位内即月份
    //直接取模，保留百位内，即日期
    printf("year=%04d\nmonth=%02d\ndate=%02d\n", date / 10000, (date / 100) % 100, date % 100);
    return 0;
}
```

### 输出printf的返回值

> 2024-07-11
> 

```
#include <stdio.h>

int main() {

    int a = printf("Hello World!");
    printf("\n");
    printf("%d",a);
    return 0;
}
```

printf会打印出字符的个数，等等也算一个字符。
也可以使用

```
printf("\n%d",n);直接打印这样也能换行。
```

### 输出printf(“hello world”);

> 2024-07-11
这个题考验的是转义字符  的运用
> 

```
#include <stdio.h>

int main() {

    printf("printf(\"Hello World!\\n\");\n");

}
```

题中的  “ 都需要.
### 四个数找出最大数
**输入：** 四个整数，用空格隔开
**输出：** 一个整数，为四个数的最大的
2022-07-11
方法一：存起来再比较

```
#include<stdio.h>

int main ()
{
    int arr[4] = {0};
    int i = 0;
    while (i < 4) //输入0-3四个元素
    {
        scanf("%d",&a[i]);
        i++;
    }
    int max = arr[0];//假设第一个数为最大数（让第一个数站上擂台）
    while(i < 4) //判断最大数
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        i++;
    }
    return 0;
}
```

方法二：输入的时候直接比较

```
#include

int main ()
{
    int i = 1;
    int n = 0;
    int max = 0;

    scanf("%d",&max);假设第一次输入的数为擂主

    wihle(i < 4)  //因为i = 1 所以再循环三次
    {
        scanf("%d",&n); //如果输入的数大于擂主，那么成为擂主
        if (n > max)
            max = n;

        i++；
    }
    printf("%d\n",max);
        return 0;

}
```

### 计算球的体积

> 2024-07-11
> 

输入：一个浮点值0-15
输出：球的体积，小数点保留三位
这个题考察的是float和double的区别
float占4字节， double占8字节，所以double的精度会更高
float在初始化的时候是float = 0.0f：
double在初始化的时候是float = 0.0lf;或者 0.0 因为0.0默认使用的是double
代码如下：

```
#include <stdio.h>

int main()
{
    double r = 0.0;
    double v = 0.0;
    //输入r
    scanf("%lf",&r);
    //计算v
    v = 4/3 * 3.1415926 * r * r * r;
    //输出v
    printf("%.3lf\n",v);
    return 0;
}
```

## 分支部分

### 学生基本信息输入输出

> 2024-07-09
> 

**输入描述：** 学号以及3科成绩，学号和成绩之间用英文分号隔开，成绩之间用英文逗号隔开。
**输出描述：** 学号，3科成绩，保留两位小数

#include<stdio.h>

```
int main()
{
    int num;
    float x,y,z;
    scanf("%d;%f,%f,%f",&num,&x,&y,&z);
    printf("The each subject score of No. %d is %.2f, %.2f, %.2f.",num,x,y,z);

    return 0;
}
```

- 格式字符串 “%d;%f,%f,%f” 规定了输入数据的格式，&num、&x、&y、&z 分别表示将输入的值存储到对应的变量地址中。
- %.2f 表示将浮点数按照小数点后保留两位的格式进行输出。
### 判断输入数字是否为5整除
2024-07-10

```
#include <stdio.h>

int main() {

    int M = 0;
    scanf("%d",&M);
    if(M % 5 == 0){
        printf("YES");
    }
    else {
        printf("NO");
    }
}
    return 0;
```

## 循环部分

### 计算n的阶乘

> 2024-07-11
> 

1. 的阶乘可以先定义一个为1的变量num，用来累加
2. 定义一个n，用来表示n的阶乘
2! = 2*1
5! = 5*4*3*2*1

```
#include <stdio.h>
int main()
{
    int n = 3;  //定义为 3 的阶乘
    int x = 1; //阶乘初始的 1 已经有了，只需要再*2*3 就行
    int i = 0; //i 放在外边是为了通过老的编译器。C99 之后才支持在 for 里边
    for (i = 1; i <= n; i++) //让 i 从 1 循环到 n 。循环时一直累乘
    {
        x = x * i;
    }
    printf("%d 的阶乘为 %d", n, num);
    return 0;
}
```

在这个代码的基础上，可以去探究一下阶乘相加，例如n=5时，计算5!+4!+3!+2!+1!
上述代码已经有了计算一次的结果，需要在计算五次就可以了，这需要累减5到1就可以了

```
#include <stdio.h>
int main()
{
    int n = 3;  //定义为 3 的阶乘
    int x = 1; //初始的 1 已经有了，只需要再*2*3 就行
    int sum = 0;
    int i = 0; //i 放在外边是为了通过老的编译器。C99 之后才支持在 for 里边
    int j = 0;
    for (j = 1; j <= n; j++)//让 j 从1到n
    {
        for (i = 1; i <= j; i++) //让 i 从 1 循环到 j 。循环时一直累乘，计算单次
        {
             x = x * i;
        }
        sum = sum + x;   //循环后叠加到sum中
    }
    printf("!%d的阶乘和为：%d", n, num);
    return 0;
}
```

### 使用二分查找（折半查找）查找有序数组中某个数字的下标

> 2024-07-11
> 

比如数组为{1,2，3,4,5,6,7,8,9,10,11,12，13,14,15,16,17,18,19,20}
**二分查找的应用范围是：**被查找的数组是一个有序的数组，上数组符合要求
**二分查找过程如下**
1. 二分查找要定义 左范围值（ **下标为0** ） 和 右范围值（ **下标为元素-1** ） 和 查到的找值（下标为左值与右值中间）
2. 通过备查找到的值与待找到值比较。
- 如果查找到的值 **大于**待找到的值，也就表示 **待查找值** 在 **左范围值和查找到的值之间** 。即 **此次查找到的值的下标就是新的右范围值**
- 如果查找到的值 **小于**待找到的值，也就表示 **待查找值** 在 **查找到的值和右范围值之间** 。即 **此次查找到的值的下标就是新的左范围值**
3.定义新的左值或者右值，再算出新的中间值之后，继续回到第二步，直到找到为止（通过left和right来判断是否没找到）。
当然，如果是倒着的数组要另说，方法同上

```
#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int a = 17; //定义待查找值
    int sz = sizeof(arr)/sizeof(arr[0]);  //计算元素个数
    int left = 0; //计算左下标
    int right = sz - 1; //计算右下标
    while(left <= right)
    {
        int mid = left + (left + right)/2; //计算范围内中间下标 这里是 为了防止溢出。
        if (arr[mid] > a) //如果查找到的值大于待查找值，那么待查找值的范围为 left - mid（mid-1 成为新的 right）
        {
            right = mid - 1;
        }
        else if (arr[mid] < a) //如果查找到的值小于待查找值，那么待查找值的范围为 mid - right（mid+1 成为新的 left）
        {
            left = mid + 1;
        }
        else  //否则就是找到了
        {
            printf("找到%d 了，他的下标是:%d\n",a,mid);
            break; //找到就跳出循环
        } //综上，为一次查找，我们需要查找到 left 不再<=right 时才停止，即当 left>right 时，找不到
    }
    if(left > right)
    {
        printf("哎呀，找不到了呀\n");
    }
    return 0;
}
```

### 输出多个字符从两端移动，向中间汇聚

> 2024-07-11
> 

例如：
##############
h############!
hel#########!!
…..
hello world!!!
char arr[] = “hello world!!!”
- 这个 **属于字符串** ，可以用到 **strlen** 来计算字符串的长度
- 当然也可以继续使用sizeof来计算字符串的长度，即 sz = sizeof(arr)/sizeof(arr[0])。但是计算出的长度不是字符串的长度，他需要减去1。因为 **字符串的结尾处有\0** 。会多计算一个字符。

他们的下标则是计算出的长度-1
- 使用strlen函数时，right的下标为 strlen（arr）-1
- 使用sizeof函数时，right的下标为 sizeof(arr)/sizeof(arr[0]) - 2
下面是实现的方法

```
#include <stdio.h>
#include <windows.h>//使用Sleep函数需要包含<windows>头文件，Sleep的单位为ms
#include <string.h>  //使用strlen函数需要包含<string.h>头文件，用来计算字符串字符个数
#include <stdlib.h>  //使用system函数需要包含<stdlib.h>头文件，用来执行系统命令
int main()
{
    char arr1[] = "hello world!!!";
    char arr2[] = "##############";

    int left = 0;
    int right = strlen(arr1) - 1;

    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];//把#填充到原字符对应的地址中
        printf("%s\n", arr2);
        Sleep(1000);    //延迟1秒
        system("cls");  //system是一个库函数，可以执行系统命令,cls是请清屏指令
        //加上这两行可以在一行上显示出来这中向中间聚拢的效果
        left++;
        right--; //缩小范围，继续填充
    }
    printf("%s", arr1); //清屏后再打印出来。
    //综上就可以实现一行的文字逐渐聚拢的效果
    return 0;
}
```

### 写一个猜数字大小的游戏

> 2024-07-11
> 

1. 系统随机出一个 **1-100** 的数字
2. 用户猜，大了就反馈大了，小了就反馈小了。
这个需要利用rand()函数来生成一个随机数
rand需要定义一个种子，也就是srand
- rand的用法是直接int a = rand();
- srand的用法是srand(一个随机数); **srand函数期望输入的数字是unsigned int 类型** （可以在手册中查到）
在这里我们用的是系统读取当前的时间戳time()函数，因为time（） **返回的值是一个 time_t 类型** 的。所以我们需要将返回值 **强制转换为unsigned int类型** 的.而且time不需要输入值，即 **输入NULL**

**所以这个随机数可以写：**

```
srand((unsigned int)time(NULL)); //设置随机数种子
int a = rand(); //随机数赋值
```

其中 srand 定义随机数种子应放到主函数中，这样在多次利用时，才不会因种子定义的起点相同而生成的随机数相差不大。
1. 如果在程序中多次调用srand()，并且传入相同的种子值，那么rand()函数每次都会从 **相同的起点开始生成随机数** ，导致得到的“随机”数实际上是重复的。
2. srand()函数的作用是设置rand()函数的种子。 **种子是伪随机数生成器的起始点** ，决定了随机数序列的起点。 **如果每次运行程序时都用相同的种子，那么每次产生的随机数序列都会是一样的。**
3. rand()函数是一个 **伪随机数生成器** ，它通过一个确定的算法来生成一系列看起来像是随机的数字。这些数字实际上是可预测的，如果知道算法和种子值，就可以计算出整个序列。

他们的头文件要求是
- srand <stdlib.h>
- time <time.h>
**下面是猜数字游戏的程序**

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()//游戏菜单
{
    printf("***********************************\n");
    printf("************  1. 开始  ************\n");
    printf("************  0. 离开  ************\n");
    printf("***********************************\n");
}

void game()//游戏本体
{
    int a = rand() % 100 + 1;//生成 1-100 的随机数

    while (1)//直到才对才跳出循环
    {
        printf("猜猜数字是什么:>\n");
        int b = 0;
        scanf("%d" ,&b);
        if (b < a)  //如果猜的值b 比生成的值a 小，那么就反馈小了
        {
            printf("猜小了\n");
        }
        else if (b > a)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你猜对了！\n");
            printf("还要继续玩吗?\n");
            break;
        }
    }
}

int main()//主函数
{
    srand((unsigned int)time(NULL));//依时间戳 生成 随机种子  需要stdlib.h 和time.h 头文件
    int input = 0;

    do
    {
        menu();//生成菜单

        printf("请选择模式:>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
            {
                game();//猜数字的整个逻辑
                break;
            }
            case 0:
            {
                printf("退出游戏\n");
                break;
            }
            defaule:
            {
                 printf("选择错误请重新选择\n");
                 break;
            }
        }
    } while (input);//input为零则退出整个循环，即退出游戏。
}

```

### 模拟用户登录

> 2024-07-11
> 

**模拟用户登录情景，只能登录三次，三次内成功则提示登陆成功，三次都收入错误，则退出程序**
此题考验的是字符串相等
比较两个字符串是否相等，不能使用 == ，而是应使用一个库函数：strcmp

```
#include <stdio.h>

int main()
{
    char password[20] = "lzj888666";//定义密码
    char arr[20] = { 0 };
    int i = 0;
    for (i = 0; i < 3; i++)//循环输入三次
    {
        printf("请输入密码> ");
        scanf("%s", arr);
        if (strcmp(arr,password) == 0)  //比较两个字符串是否相等，不能使用 == ，而是应使用一个库函数：strcmp
        {
            printf("密码正确\n");
            break;//跳出循环
        }
        else
        {
            printf("密码错误\n");
        }
    }
    if (i == 3)
    {
        printf("三次输入密码错误，退出系统\n");
    }
    return 0;
}
```

### 关机程序

> 2024-07-11
> 

电脑运行起来后，一分钟内关机，如果输入我是猪，就取消关机
- 这个题考察了goto 语法的使用
- goto 语法一般不常用，但他可以用来跳深度嵌套的语句。

- 在windows中关机命令是
- 取消关机是:-a

```
#include <stdio.h>
#include <stdlib.h> //C语言中执行系统命令所包含的头文件
#include <string.h>//字符串对比头文件
int main()
{
    char input[20] = { 0 };
    system("shutdown -s -t 60");
    //system执行cmd命令的函数
    //shutdown 是用于执行关机操作的命令。
    //-s 表示关机（shutdown）操作。如果是 -r 则表示重启（reboot）操作。
    //-t 60 表示设置关机前的倒计时时间为 60 秒。
again:
    printf("你的电脑将在60秒后关机，如果输入：我是猪，则取消关机\n");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0)//对比字符串是否相等时，使用strcmp函数。
    {
        system("shutdown -a");
        printf("对对对，你是猪\n关机已解除");
    }
    else
    {
        goto again;
    }
    return 0;
}

```

**当然，最好还是不要用goto语句，这段可以改成while语句来代替**

```
#include <stdio.h>
#include <stdlib.h> //C语言中执行系统命令所包含的头文件
#include <string.h>//字符串对比头文件
int main()
{
    char input[20] = { 0 };
    system("shutdown -s -t 60");

    printf("你的电脑将在60秒后关机，如果输入：我是猪，则取消关机\n");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0)//对比字符串是否相等时，使用strcmp函数。
    {
        system("shutdown -a");
        printf("\n对对对，你是猪\n关机已解除");
        break;
    }

    return 0;
}
```

## 函数部分

### 写一个函数，实现对xy的交换

> 2024-07-12
> 

这部分考验了实参和形参。
- 形参在用完就销毁了

**代码1：**

```
#include <stdio.h>

void Swap(int a,int b)
{
    int z = a;
    a = b;
    b = z;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d &d",&a,&b);
    //交换前
    printf ("交换前：%d %d",a,b);
    //交换
    Swap(a,b);
    printf ("交换后：%d %d",a,b);
    return 0;
}
```

**这个代码是错误代码。**
- 因为main函数中是实参，而void中的a b为形参
- 当代码执行到这一部分的时候， **形参是实参的临时拷贝** ，它有了自己的地址。 **对形参的修改不能改变实参**
要想正确的交换，则应用到指针。
- 先把实参的地址传到子程序中，在子程序中通过地址准确的找到main中的实参，然后完成精准的控制。

```
#include <stdio.h>

#include <stdio.h>

void Swap(int* pa, int* pb)
{
    int z = *pa;
    *pa = *pb;
    *pb = z;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    //交换前
    printf("交换前：%d %d", a, b);
    Swap(&a, &b);
    printf("交换后：%d %d", a, b);
    return 0;
}
```

### 在往函数传递内容的时候需要用指针

> 2024-07-12
> 

线在上面的函数基础上，添加一个add函数

```
int add(int x,int b)
{
    int z = 0;
    z = x + y;
    return z;
}
```

可以看到在add函数中，并没有用到指针去传递地址。为什么呢？
- 因为在使用add时，并不需要改变实参a或b的值，只需要将他们相加再返回就可以
- 所以形参的值只要一样就可以了。
**结论：** 综上，可以看出函数的调用有两种
1. 传 **值** 调用
- 函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参
2. 传 **址** 调用
- 传址调用是吧函数外部创建的变量的内存地址传递给函数参数的一种调用方式
- 这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量。

### 1. 写一个函数可以判断一个数是不是素数。

```
void sushu(int x)
{
    int i = 1;
    int flag = 0;//标志位
    for (i = 2; i <= x-1; i++)
    {
        if (x % i == 0)
        {
            printf("这个数字不是素数");
            flag = 0
            break;
        }
    }
    if (flag == 1)
    {
        printf("这个数字为素数");

    }
}
```

当然这个代码还有优化的空间，
1. 可以使用sqrt库来对输入的数字进行开方，这样i只需要累加到sqrt(x)就可以了。因为当i累加到sqrt(x)时还没被x整除，那么想必，后面的肯定数中肯定也没有数是x的因子了。
2. 素数一定是一个奇数，所以++可以变成+=2
因此循环部分的代码可以改成这样，其余不变
**需要注意的是sqrt属于数学库，需要添加头文件#include <math.h>**

```
    for (i = 1; i <= sqrt(x); i+=2)
```

### 2. 写一个函数判断一年是不是闰年

> 2024-07-12
> 

闰年的要求
1. 能被4整除，且不能被100整除
2. 能被400整除

```
void is_leap_yer(int x)
{
    if(( x % 4 == 0)&&( x % 100 != 0 )) || ( x % 400 == 0 )
    {
        retrun 1;
    }
    else
    {
        return 0;
    }
}
```

**这个函数是返回1 或 0 相比上一题的函数，直接打印出来，他的功能更为单一，更容易让别人去复用**（比如别人不想打印，他只想判断）

### 3. 写一个函数，实现一个整形有序数组的二分查找

这个函数主要是考察到 **了数组在传参的过程中，传递的是数组首元素的地址，而不是整个数组。** 
比如有

```
main ()
{
    int arr[20]={1,2,3,4,5,6,7,8,9};
    Binary_Search(arr);
}
int Binary_Search(int arr)
{
    int a = sizeof(arr)/sizeof(arr[0]);
    printf("%d",a);
}
```

在这段代码中，arr元素个数的计算是在Binary_Search中计算的

但是由于**arr传过来的只是一个首地址**，所以他的元素个数打印出来就是1
所以在函数内部计算函数参数部分的数组的元素个数是不靠谱的
**所以正确的代码是在函数外部计算数组的元素个数**
所以完成二分查找的数组的程序是

```
#include <stdio.h>

int Binary_Search(int arr[], int cz, int sz)
{

    int left = 0;//初始化数组的左边下边
    int right = sz - 1;//初始化数组的右边下标
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
                if (arr[mid] > cz)//如果查找到的大于被查找值，那么新的右边界被定义
                {
                    right = mid - 1;
                }
                else if (arr[mid] < cz)//如果查找到的小于被查找值，那么新的左边界被定义
                {
                    left = mid + 1;
                }
                else
                {
                    return mid;//否则只能等于，然后返回下标
                }
        }
    //如果循环都结束了（left>right），还没有找到，就返回-1（因为下标是大于0的）
    return -1;
}

int **main()**
{
    int arr[20] **= { 1,2**,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };//定义数组
    int cz = 16; //定义待查找值
    int sz = sizeof(arr) / sizeof(arr[0]); //计算数组中元素个数

    int sign = Binary_Search(arr, cz, sz); //输入数组首地址，待查找值和数组的元素个数
    //根据返回值判断
    if (sign == -1)
    {
        printf("找不到啊\n");
    }
    else
    {
        printf("找到啦，%d的下标是:%d\n", cz, sign);
    }
    return 0;
}

```

### 4. 写一个函数，每调用一次这个函数，就会将 num 的值增加1

> 2024-07-11
> 
- 指针法

```
void add(int *num)
{
    (*num)++;
}
int main ()
{
    int num = 0;
    add(num);
}
```

- static修饰法//写函数的时候！最好不要用这种东西!!

```
void add(int num)
{
    num ++;
}
int main ()
{
   static int num = 0;
   add(num)
}
```

其他的就不多写了 也可以直接return num + 1;
### 函数的嵌套
- 函数可以嵌套调用，但是不能嵌套定义

```
#include <stdio.h>
void 1_line()
{
    printf("hello\n");
}
void 3_line()
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("hello\n");
    }
}
int main()
{
    3_line();
    return 0;
}
```

### 函数的链式访问

> 2024-07-12
> 

> 函数的返回值可以作为另一个函数的参数
> 

**未嵌套**

```
#include <stdio.h>
int main()
{
    int len = strlen("abcdef");//定义len
    printf("%d\n",len);
    return 0;
}
```

**嵌套后**

```c
#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n",strlen("abcdef"));
    return 0;
}

```

**一道链式访问的例题**

```c
printf(“%d ”,printf(“%d ”,printf(“%d ”,43)));
```

> printf的返回值是输出的字符个数所以输出43 2 1
> 

### 函数的声明

1.函数的声明是告诉提前告诉编译器，有一个函数叫什么，返回类型是什么，但是具体存不存在函数声明是决定不了的。

2.函数的声明  一般出现在函数使用之前，**要满足先声明后使用。**

3.函数的声明一般放到**头文件中**

函数的声明一般放到.h头文件中，在main.c文件中使用#include <xxxx.h>。函数部分可以放到xxxx.c文件中。

### 导出导入静态库

导出：导出可以把你写好的如add.c文件导出为add.lib的库文件，配合add.h的头文件声明。可以一定程度的隐藏代码，且能给别人使用。

导入：在导入静态库时，需要输入 #pragma comment(lib,“add.lib”)

### 递归

### 1.什么是递归？

1. 程序调用自身的编程技巧称为递归(recursion)
2. 递归做为一种算法在程序设计语言中广泛应用。一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解递归策略
3. 只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。
**递归的主要思考方式在于:把大事化小**

### 2.递归的两个必要条件

1. 存在限制条件，满足这个限制条件就不在递归
2. 每次递归调用后越来越接近这个限制条件

### 一道简单的递归练习题,输出输入的字符

输入12345

输出1 2 3 4 5

```c
#include <stdio.h>
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int num;
	scanf("%d", &num);
	print(num);
	return 0;
}
```

简单讲一下：

num=12345 进到函数之后，因为n>9所以进入函数，且被除10 变为

num=1234 同理

num=123

num=12

num=1  到1之后，因为小于10，所以取模打印，**打印1，**然后跳出这次循环 到

num=12 的循环中，取模打印，**打印2**，到

num=123 的循环中，取模打印，**打印3**，到

num=1234 ，**打印4**

num=12345，**打印5**

递归用到了大括号中的数只在大括号内有效。

### 一道练习题,求字符串长度

输入一串字符串

自己编写一个函数输出字符串的长度,但是！不允许使用临时变量

```c
#include <stdio.h>

int my_strlen(char* arr)//把整个数组丢进去
{
	int count = 0; //用来记录字符个数,是临时变量
	while (*arr != '\0') //arr是指针，在刚开始时*arr是字符串第一个数字的下标
	{
		count++;
		arr++;//下一个循环去对比第二个字符
	}
	return count;//查找到\0之后，跳出循环，然后返回count的值
}

int main()
{
	char arr[20] = { 0 };
	scanf("%s", arr);
	int len = my_strlen(arr);
	printf("%d", len);//打印返回值
	return 0;
}

```

所以我们要想一想如何在不创建临时变量的情况下计算出字符串长度

可以把他拆解成如下的步骤

```c
//my_strlen("abc");
//1+my_strlen("bc");
//1+1+my_strlen("c”)
//1+1+1+my_strlen("\n")//到\0就不进入递归了
//1+1+1+0
```

所以，我们可以把代码改成这样

```c
#include <stdio.h>

int my_strlen(char* arr)//把整个数组丢进去
{
	int count = 0; //用来记录字符个数,是临时变量
	if (*arr != '\0')
	{
		return 1 + my_strlen(arr + 1);//开始检查第2个是不是\n  只要有数就+1
	}                               //注意不要写成arr++，不然就成了先把arr穿进去再++了，会死循环
		return 0;//如果*arr最终='\n'则返回0	  //++arr可以，但是不建议这样写
}

int main()
{
	char arr[20] = { 0 };
	scanf("%s", arr);
	int len = my_strlen(arr);
	printf("%d", len);//打印返回值
	return 0;
}

```

### 再按照这个规律写一个阶乘的题吧！怎么弄呢？

输入5,输出需要是5x4x3x2x1  也就是说，加到这个数为0时，停止，5要依次递减1

```c
int jiecheng(int a)
{
	while (a)//为0时停止循环
	{
		return a * jiecheng(a - 1);//阶乘中会出现 5*4*3*2*1   
	}
	return 1; //a = 0 时返回1
}

int main()
{
	//输入
	int a = 0;
	scanf("%d", &a);
	long num = jiecheng(a);//把a丢到递归里
	printf("%d", num);
	return 0;
}
```

其实阶乘的这个函数还能再简单：

```c
int jiecheng(int a)
{
	if (n <= 1)
		return 1; 
	else
		return n * jiecheng(n - 1); // 5*4*3*2*1
}
```

太强了！

练习，求第n个柏菲拿起书

### 迭代

如递归的最后一题，实现阶乘的代码是

```c
//迭代的方式-非递归的方式
int fac(int n)
{
	int i = 0;
	int ret = 1;
	for(i = 1;i <= n; i++)
	{
		{
			ret *= i;
		}
		
	return ret;
}
```

### 递归和迭代的使用方法（斐波那契数列）

斐波那契数列: 1  2  3   5  8   13   21    34    55  … 前两个数字相加等于后者

**那我们先用递归的方式想想这题怎么做** 

设我们要求第n个斐波那契数列

那么在n <=2 时，F(n) =1  

         在n > 2 时，F(n) = F( n - 1  ) + F( n - 2 ) 

根据这个想法，我们就可以很方便的写出递归了

比如n现在等于4

那么他的值就等于F3 +1 =  F1+F2+1

```c
#include <stdio.h>

int fbnq(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return fbnq(n - 2) + fbnq(n - 1);
	}
}
//1 1 2 3 5 8 13 21 34
int main()
{
	//输入
	int n = 0;
	scanf("%d", &n);
	long num = fbnq(n);//把n丢到递归里,找出第n个数字是什么
	printf("%d", num);
	return 0;
}
```

但是当n数值很大的时候，比如n = 1000的时候

就需要递归2^1000次方。内存很容易爆炸！

而且可以看到，效率非常的慢

这时我们用循环迭代来解决这道题

```c
#include <stdio.h>

int fbnq(int n)
{
	int a = 1;//定义一下 前三个数
	int b = 1;
	int c = 1;//这里是为了解决当n=1或2的饿时候，让输出为1
	while (n >= 3)
	{
		c = a + b; //求出下一个值
		a = b;
		b = c;//数值往右移一位
		n--;//移动一次后让循环减一
	}
	return c;//循环结束后就是最终结果
}
int main()
{
	int n = 0;
	scanf("%d", &n);//输入要求的数
	int	ret = fbnq(n);
	printf("%d\n", ret);
	return 0;
}
```

在使用递归的时候，如果递归层次太深，我们可以**使用static对象来修饰局部对象为静态的**，这样就不会创建很多的局部变量导致**栈溢出**

### 递归:   汉诺塔

汉诺塔，有三个柱子，柱子上有n个盘子，大盘子不能放到小盘子上

盘子在a 要到c上

**思考一下**

如果现在盘子都在 a 上，     b       c   为空盘， 目的是把所有盘子放到c上

- 1个盘子的话，也就是 a → c
- 2个盘子的话，也就是 a → b     a → c      b → c
- 3个盘子测话，也就是 先把上面两个盘子放到b上，a → c  再把两个盘子放到c上

也就是先把n-1个盘子先放到借助柱上，再把n盘子放到目标柱子上

用公式来表示的话可以这样写：其中a是起始地，b是借助，c是目标地

- f(1,a,b,c) =   a  →  c
- f(2,a,b,c)  =  a → b   a → c   b → c
- f(3,a,b,c) = f(2,a,c,b)   a → c  f(2,b,a,c)

我们可以把f(3,a,b,c)等式右边的拆解成：

( a  →  c    a → b     c → b  )   a → c   ( b  → a  b → c   a → c  )

**需要注意，当我们将变量代入函数时，这些变量代表的是具体的对象或状态。别弄混了**

所以，我们也可以轻易地把f(4,a,b,c)换算成最终的步骤

也可以吧f(n,a,b,c)变成最终的步骤

                     f(n,a,b,c) = f(n-1,a,c,b)     a → c     f(n-1,b,a,c)

向下拆解时到n - 1，只需要把f(n-1,a,b,c )带入到f(n,a,b,c) 得到

                    f(n-2)    a  →  c   f(n-2)      a  →  c        f(n-2)    a  →  c   f(n-2) 

直到带入到最底层    f(1) 或者f(2)时， 带入就可，下面是代码步骤

```c
#include <stdio.h>

void hainuo(int n, char A, char B, char C)
{	static int count = 0;//记录步骤,放到静态堆栈里.
	if (n == 1)
	{
		count++;//计数,,整个递归中，只有这一步和放最后一个盘子是最底层的,需要+1
		printf("第%d步：%c -> %c\n", count, A, C);
	}
	else
	{
		//第一步，把A的n-1个盘字移动到辅助盘
		hainuo(n - 1, A, C, B);
		//第二步，把A最下面的盘移动到C盘
		count++;
		printf("第%d步：%c -> %c\n", count, A, C);
		//第三步，把辅助盘上的放到C盘上
		hainuo(n - 1, B, A, C);
	}
}

int main()
{
	int n = 0;
	printf("你打算放多少个盘子：>");
	scanf("%d", &n);
	//输出步骤
	hainuo(n, 'A', 'B', 'C');

	return 0;
}
```

### 递归：小青蛙上楼梯

有一只小青蛙，一次能跳2个台阶或者一个台阶。

现在有n个台阶。问小青蛙跳上台阶有多少种可能的情况

有了上一题的洗礼，这一题应该不难了.

**分析一波：**

现在1个台阶，他跳一下就可以了。

现在有2个台阶，他跳1+1或者2 就可以了 有两种情况

有n个台阶，他跳了一次之后，计数器加一，然后现在有两种情况1. 还剩n-1个台阶， 2. 还剩n-2 个台阶 。

再跳一次之后，又有了这两次情况，直到他还剩最后一次跳跃所以可以写如下代码：

```c
#include <stdio.h>

int Palouti(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else if (n > 2)
	{
		return Palouti(n - 1) + Palouti(n - 2);
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n = 0;
	printf("你打算让小青蛙爬多少个楼梯：>");
	scanf("%d", &n);
	//输出总次数
	int ret = Palouti(n);
	printf("小青蛙爬上楼梯有这么多可能：%d", ret);

	return 0;
}
```