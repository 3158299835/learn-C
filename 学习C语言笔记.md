# 学习C语言笔记

### 介绍

这些是我在学习C语言的过程中自己练习的一些题目

大家也可以参考着来学习

正在更新

**大家可以在[我的gitee仓库](https://gitee.com/Xiao____liu/learning---c-language) 中下载笔记源文件**

**笔记源文件可以在Notion中导入**

# 初认C语言

## printf打印小飞机

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

## 输入两个数，输出商和余数

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

## 根据ASCII码输出字符

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

## 出生日期输入输出

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

## 输出printf的返回值

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

## 输出printf(“hello world”);

> 2024-07-11
这个题考验的是转义字符  的运用
> 

```
#include <stdio.h>

int main() {

    printf("printf(\"Hello World!\\n\");\n");

}
```

## 四个数找出最大数

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

## 计算球的体积

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

# 分支部分

## 学生基本信息输入输出

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

## 判断输入数字是否为5整除

> 2024-07-10
> 

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

# 循环部分

## 计算n的阶乘

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

## 使用二分查找（折半查找）查找有序数组中某个数字的下标

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

## 输出多个字符从两端移动，向中间汇聚

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

## 写一个猜数字大小的游戏

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

## 模拟用户登录

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

## 关机程序

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

## 冒泡排序

这个冒泡排序顺便复习了一下函数的调用，复习了一下指针。

冒泡排序是两两对比，大的放右边，可以看作是一个大括号从下标为0 和1开始括，

然后往右移动，变成括起来 下标为 1 和 2 的两个数进行比较， 比较完成之后 最右边的数字就是最大值了， 

这时候就不需要再比较最右边的数了。

所以第二次重新开始比较循环的时候，就可以不管最右边的数了， 也就是 第二层for循环中的**len-1 -i**  

```c
//---------------------------------------------------------------------------------
#include <stdio.h>

//交换函数
void swap(int* px, int* py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

//冒泡排序函数从小到大
void bubble_sort_max(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[10];    //输入
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);//求长度

    bubble_sort_max(arr, len); //排序

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]); //输出
    }

        return 0;
}
//---------------------------------------------------------------------------------
```

# 说一下我对指针  地址  下标 的一些理解

1. 数组下标应该是从0开始的，所以arr[10]={0};这个代码中，有0到9共十个房间号。例如，printf("%d", arr[2]);打印的是第三个元素，即arr[2]的值
2. 指针 

指针是一种特殊的变量，全名叫指针变量。它存储的是另一个变量的内存地址。例如，

`int a = 10;     int *p = &a；`    这段代码将a的地址赋值给指针变量p。
1. 内存分为堆区、栈区和静态区。堆区由程序员显式分配和释放，栈区由编译器管理，存储局部变量和参数，静态区存储全局和静态变量。

1. **堆区**：它是由操作系统管理的，但分配和释放操作由程序员通过代码显式完成，通常使用`malloc()`、`calloc()`分配内存，使用`free()`释放内存。堆内存地址由低到高增长，适合存储大数据或生命周期长的对象，但需注意内存泄漏问题。
2. **栈区**：由编译器管理，存储局部变量和参数，内存地址由高到低递减。栈空间小但速度快，适合函数调用和临时数据存储。**比如临时变量，返回值，形参这些**
3. **静态区**：**存储全局和静态变量，**生命周期贯穿程序运行。已初始化变量在`.data`段，未初始化变量在`.bss`段，由系统初始化。

我们现在要打印变量a的地址，就需要这样的代码

```c
int a = 10;
printf("%p",&a) //这里的%p是输出地址用的
```

比如a的地址是0x0123

1. 指针

指针，他存储的是内存地址，它的表示是int* 或者char*比如这个代码

```c
int a = 10;
int* p = &a;  
```

这段代码的意思就是把a的地址0x0123赋值给p这个指针变量

但是需要注意，**指针变量p在内存中是有自己的内存地址的**，它里面存储的值是a的地址

如果输入`printf(”%p”,“&p)；`就可以显示出p在内存中的地址

现在这个情况

- **p 里是**a的地址0x0123  他的类型是int*

现在如果打印p这个值的地址:`printf(”%p”,p);` 就会输出0x0123

- ***p 指的是** 对p进行**解引用**  得到  **a的值**    他的类型是int

   对*p赋值相当于给a赋值。例如，`*p = 20;`等价于`a = 20;`

如果我们输入`printf(”%d”,*p);`  就相当于输入`printf(”%d”,a);`  他的结果就是10

> 这个时候输入`printf(”%p”,&*p)；` 
`*p` 是使用解引用操作符 `*` 来访问指针变量 `p` 指向的内存位置中的值。
*p指向的是a ，所以&*p 输出就等于&a输出就还是0x0123
> 

# 函数部分

## 写一个函数，实现对xy的交换

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

## 在往函数传递内容的时候需要用指针

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

## 1. 写一个函数，可以判断一个数是不是素数。

素数时只能被他本身和1整除的数字

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

## 2. 写一个函数，判断一年是不是闰年

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

## 3. 写一个函数，实现一个整形有序数组的二分查找

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

## 4. 写一个函数，每调用一次这个函数，就会将 num 的值增加1

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

## 函数的嵌套

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

## 函数的链式访问

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

## 函数的声明

1.函数的声明是告诉提前告诉编译器，有一个函数叫什么，返回类型是什么，但是具体存不存在函数声明是决定不了的。

2.函数的声明  一般出现在函数使用之前，**要满足先声明后使用。**

3.函数的声明一般放到**头文件中**

函数的声明一般放到.h头文件中，在main.c文件中使用#include <xxxx.h>。函数部分可以放到xxxx.c文件中。

## 导出导入静态库

导出：导出可以把你写好的如add.c文件导出为add.lib的库文件，配合add.h的头文件声明。可以一定程度的隐藏代码，且能给别人使用。

导入：在导入静态库时，需要输入 #pragma comment(lib,“add.lib”)

## 递归

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

## 迭代

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

## 递归和迭代的使用方法（斐波那契数列）

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

## 递归:   汉诺塔

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

## 递归：小青蛙上楼梯

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

## 写一个函数，返回参数中二进制数中1的个数的一道很妙的解法

```csharp
#include <stdio.h>
int count_num_of_1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & n - 1;
		count++;
	}

	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	printf("%d", count_num_of_1(n));
	return 0;
}
```

同理。我们也可以通过这个算法。去判断一个数是不是2的n次方

因为2的n次方有一个特点，他们的二进制数中只有一个1

所以只需要判断一下他们的二进制数中是否为一个1。

# 数组

## 一维数组

没啥说的

## 二维数组

int arr[][4] **列必须有，他**们**在内存地址上是连续的**，他们在可以写成

int arr[3][4]{{1，2，3，4}，{1，2，3，4}，{1，2，3，4}}；

## 数组的指针

### 对于一维数组

**数组名除了两种情况都是代表数组的首地址**

1. sizeof(数组名) 这里的数组名代表的是整个数组，计算的是整个数组的大小
2. &数组名，这里的数组名是整个数组的地址，不是首地址的地址

```c
int arr[10] = { 0 };

printf("%p",arr);    //打印数组名=打印首地址
printf("%p",&arr[0]);//打印数组首地址
printf("%p",&arr);   //打印数组地址
```

现在如果打印，可以到打印的是一模一样的地址。但是让他们同时+1。就会发现。数组的地址跳了10*4（用二进制算过之后）。

```c
int arr[10] = { 0 };

printf("%p",arr+1);    //打印数组名=打印首地址
printf("%p",&arr[0+1]);//打印数组首地址
printf("%p",&arr+1);   //打印数组地址
```

### 对于二维数组

二维数组的数组名表示的是 **一行的地址，而不是首元素的地址**

**但是二维数组arr+1  表示的是二维数组的第二行**，不是第二个

其实可以感觉的到，一维数组和二维数组，他们的arr在+1的时候都是跳过整个数组

根据`int = arr[3][4]={ { 1,2,3,4}, {2,3,4,5 }, {3,4,5,6 }}` 可以看出来

其实`{1,2,3,4}` 就可以看成是一个**二维数组的元素** 所以我们在取地址的时候，取的其实是整个二维数组的第一个元素，也就是这第一行。

我猜测同理，三维数组也是这样。

### 计算二维数组的行列

```c
#include <stdio.h>

int main()
{
	int arr[4][5] = { 0 };
	//行=整个二维数组/一行的数组的字节大小
	int hang = sizeof(arr) / sizeof(arr[0]);
	//列=一行数组/一个元素的字节大小
	int lie = sizeof(arr[0]) / sizeof(arr[0][0]);
	printf("hang=%d,lie=%d", hang, lie);
	return 0;
}
```

## 自适应棋盘+简单电脑+困难电脑+双人对战的三子棋小游戏

主函数**`test.c`**

```c
#define _CRT_SECURE_NO_WARNINGS

#include "3ziqi_game.h"

//---------------------------------------
//三子棋
//---------------------------------------
int main()
{
	srand((unsigned int)time(NULL));//设置随机种子
	int input = 0;
	do
	{
		//打印菜单
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 0:
			{
				break;//退出游戏
			}
			case 1: 
			{
				game(1);//玩家对战
				break;//退出游戏
			}
			case 2:
			{
				game(2);//简单电脑对战
				break;//退出游戏
			}
			case 3:
			{
				game(3);//困难电脑对战
				break;//退出游戏
			}
			default:
			{
				printf("输入错误，请重新输入\n");
			}
		}
	} while (input);//input = 0 结束游戏

	return 0;
}
```

可以看到有三个模式，输入1、 2、 3进入对应的模式，输入0则退出游戏.

输入别的就提示输入错误

在进入game函数中的时候会带入这个数字的值

#include "3ziqi_game.h" 包含的这个头文件中有#include <stdio.h>等必要头文件，所以主函数文件不需要再重复的包含头文件

下面我们看一下头文件：**`3ziqi_game.h`** 

```c
#pragma once

//包含必要头文件
#include <stdio.h>
#include <stdlib.h>//随机头文件
//宏定义
#define ROW 10  //定义行为3。为了以后能更好的修改参数
#define COL 10 //定义列为3

//打印游戏菜单
void menu();

//进入游戏
int game(int a);

//初始化棋盘
void InitBoard(char Board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char Board[ROW][COL], int row, int col);

//玩家1输入
void Player1_input(char Board[ROW][COL], int row, int col);

//玩家2输入
void Player2_input(char Board[ROW][COL], int row, int col);

//easy电脑输入
void Easy_Computer_input(char Board[ROW][COL], int row, int col);

//hard电脑输入
void Hard_Computer_input(char Board[ROW][COL], int row, int col);
// 辅助函数用于检测给定位置是否会导致立即获胜
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col);

//检测输赢或继续或平局
int Detection(char Board[ROW][COL], int row, int col);

//根据检测值打印
int Detprintf(char Board[ROW][COL], int row, int col,int role);
```

可以看到，我们把所有的函数的头文件全部丢到这个文件里了， 可以方便移植。

下面看一下游戏的函数文件：**`3ziqi_game.c`** 

```c
#define _CRT_SECURE_NO_WARNINGS
//包含了头文件声明
#include "3ziqi_game.h"
//接受输入到的值
int game(int a)
{

	//定义棋盘
	char Board[ROW][COL] = { 0 };

	//初始化棋盘
	InitBoard(Board, ROW, COL);
	
	int Power = 1;//用来控制是否循环
	int role = 0; // 0为电脑  1为玩家
	while (Power)
	{	
		switch (a)
		{
			case 0:
			{
				Power = 0;
				break;//退出游戏
			}
			case 1://玩家对战
			{
				role = 1;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL,role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}

				//玩家2输入
				Player2_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 2://电脑对战
			{
				role = 0;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}

				//电脑输入
				Easy_Computer_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 3:
			{
				role = 0;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}

				//电脑输入
				Hard_Computer_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}
		}
	}

}

//游戏菜单
void menu()
{
	printf("\n***************************************\n");
	printf("*****         1. 玩家对战         *****\n");
	printf("*****         2. 简单电脑         *****\n");
	printf("*****         3. 困难电脑         *****\n");
	printf("*****         0. 离开游戏         *****\n");
	printf("***************************************\n");
}

//初始化棋盘
void InitBoard(char Board[ROW][COL],int row,int col)//注意区分大小写
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			Board[i][j] = ' ';  //把这么多的行和列都赋值为空格
		}
	}
}

//打印棋盘---------------------------------------------------------------------
//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |    
// 
//把这个当成一次
//   |   |   
//---|---|---
//
//那么只需要少打印一次|和---|---|---即可
//再把---|当成一次，主需要少打印一次|就可以实现对列的自适应
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++) //打印一次
		{
			//打印初始化棋盘的第i行j列的字符
			printf(" %c ", Board[i][j]);
			//打印 | COL-1次
			if (j < row - 1)  //少打印一次 |
			{
				printf("|");
			}
		}
		//换行
		printf("\n");
		if (i < col - 1)//少打印一次---|---|---
		{
			int k = 0;
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)//少打印一次 |
				{
					printf("|");
				}
			}
		}
		printf("\n");//打印完一行
	}
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//输入

//规则
//只能落子在未被放置的区域
//注意程序中的坐标和玩家输入坐标不一致需要-1.
//注意不要让他输入出棋盘范围

//----------------------------------
//玩家输入1
//玩家输入坐标1-ROW 1-COL 来落子，落子符号为*
void Player1_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("玩家1落子>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '*';
			break;//跳出
		}
		else //否则不符合要求，
		{
			printf("\n坐标不符合要求，请重新输入。\n输入范围应是(1-%d 1-%d)\n且不要在已有棋子的情况下落子\n\n", row, col);
		}
	}
}
//----------------------------------

//----------------------------------
//玩家输入2
//玩家输入坐标1-ROW 1-COL 来落子，落子符号为#
void Player2_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("玩家2落子>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '#';
			break;//跳出
		}
		else //否则不符合要求，
		{
			printf("\n坐标不符合要求，请重新输入。\n输入范围应是(1-%d 1-%d)\n且不要在已有棋子的情况下落子\n\n", row, col);
		}
	}
}
//----------------------------------

//----------------------------------
//电脑输入(简单)
//玩家自动落子，落子符号为#
//随机输入- 
// srand <stdlib.h>
void Easy_Computer_input(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑落子\n");
	while (1)
	{
		//设置一个随机值，让电脑在棋盘范围内随机下棋
		x = rand() % row;
		y = rand() % col;
		//填进去，如果填的进去就退出循环、注意这里的x和y他是0-row-1的范围 不用像玩家输入一样-1
		if (Board[x][y] != '*' && Board[x][y] != '#' && 0 <= x && x <= row - 1 && 0 <= y && y <= col - 1)
		{
			Board[x][y] = '#';
			break;//跳出
		}
		continue;
	}
}

//----------------------------------

//----------------------------------
// 高级电脑输入
void Hard_Computer_input(char Board[ROW][COL], int row, int col)
{
	printf("电脑落子\n");

	// 检查是否有立即获胜的走法
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '#', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// 如果没有立即获胜的走法，检查是否能阻止对手获胜
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '*', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// 如果以上两种情况都不满足，选择一个空位放置棋子
	int x, y;
	do
	{
		x = rand() % row;
		y = rand() % col;
	} while (Board[x][y] != ' ');

	Board[x][y] = '#';
}

// 辅助函数用于检测给定位置是否会导致立即获胜
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col)
{
	Board[x][y] = symbol; // 假设在这个位置放棋子

	// 检查行
	int count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && Board[x - i][y] == symbol) ++count;
		if (x + i < row && Board[x + i][y] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查列
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (y - i >= 0 && Board[x][y - i] == symbol) ++count;
		if (y + i < col && Board[x][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查对角线
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y - i >= 0 && Board[x - i][y - i] == symbol) ++count;
		if (x + i < row && y + i < col && Board[x + i][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查反向对角线
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y + i < col && Board[x - i][y + i] == symbol) ++count;
		if (x + i < row && y - i >= 0 && Board[x + i][y - i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	Board[x][y] = ' '; // 撤销假设
	return 0;
}

//----------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//三子棋检测函数
//判断行，列，左对角和右对角是否有三个相同
//反馈类型有 *  #   P   C  分别表示 玩家1赢，玩家或电脑赢，平局，继续
//我是第一个想到冒泡排序的技巧
int Detection(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)  // 一行一行检测有无三个相同
	{
		for (j = 0; j < col - 2; j++)  // 列两两对比有无数据是否相同。可以少循环 2 次 1 = 2 & 2 = 3 同时相等时，行有三连
		{
			if (Board[i][j] == Board[i][j + 1] && Board[i][j + 1] == Board[i][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 列检测
	for (i = 0; i < col; i++)  // 一列一列检测有无三个相同
	{
		for (j = 0; j < row - 2; j++)  // 行两两对比有无数据是否相同。可以少循环 2 次 1 = 2 & 2 = 3 同时相等时，列有三连
		{
			if (Board[j][i] == Board[j + 1][i] && Board[j + 1][i] == Board[j + 2][i])
			{
				if (Board[j][i] == '*')
				{
					return '*';
				}
				else if (Board[j][i] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 从左上角开始向右下角的对角线检测
	for (i = 0; i < row - 2; i++)  // 控制行的起始位置
	{
		for (j = 0; j < col - 2; j++)  // 控制列的起始位置
		{
			if (Board[i][j] == Board[i + 1][j + 1] && Board[i + 1][j + 1] == Board[i + 2][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 从右上角开始向左下角的对角线检测
	for (i = 0; i < row - 2; i++)  // 控制行的起始位置
	{
		for (j = col - 1; j >= 2; j--)  // 控制列的起始位置
		{
			if (Board[i][j] == Board[i + 1][j - 1] && Board[i + 1][j - 1] == Board[i + 2][j - 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}
	// 判断是否为平局
	for (i = 0; i < row ; i++)  // 遍历每一行每一列是否不等于' '
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 'C';//有一个还是空格就返回继续
			}
		}

	}
	return 'P';//否则为平局
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//检测返回值并打印数据
int Detprintf(char Board[ROW][COL], int row, int col, int role)
{
	//检测
	switch (Detection(Board, ROW, COL))
	{
	case '*':
	{
		if (role = 1)
		{
			printf("玩家1获得胜利\n");
			return 0;
		}
		if (role = 0)
		{
			printf("玩家获得胜利\n");
			return 0;
		}
	}
	case '#':
	{
		if (role == 1)
		{
			printf("玩家2获得胜利\n");
			return 0;
		}
		if (role == 0)
		{
			printf("电脑获得胜利\n");
			return 0;
		}
	}
	case 'P':
	{
		printf("平局\n");
		return 0;
	}
	case 'C':
	{
		return 1;
	}
	}
}
//-----------------------------------------------------------------------------
```

写的可能有点麻烦，但是都是自己敲出来的.花了我一下午的时间！！

看代码然后跳转函数的对应位置自己看吧！！

## 字符串逆序（递归实现）

编写一个函数reverse_string(char* string)(递归实现)
将参数字符串中的字符反向排列，不是逆序打印。实现 : 要求 : 不能使用C函数库中的字符串操作函数.
比如`char arr[] = "abcdef"`
逆序之后数组的内容变成 : `fedcba`

1. 迭代解决方法

```csharp
int main()
{
	//解决思路是直接把函数两两交换，从两边开始
	//代码可以借鉴一下之前学过的二分查找
	char arr[] = "abcdef";
	//记录一下字符串的下标位置
	int lift = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 2;
	//注意哦，这里我是用的sizeof，他会把字符串后边的\0也计算在内 要计算拿下标就需要-2 
	// 如果你用的是字符串求长函数'strlen'就是字符的个数啦~   -1就OK了
	while (lift < right)
	{
		char temp = '0';
		temp = arr[lift];
		arr[lift] = arr[right];
		arr[right] = temp;

		lift++;
		right--;
	}
	printf("%s", arr);

	return 0;

}
```

1. 转换成函数的解决方法

```csharp
//函数方法解决
#include <stdio.h>
#include <string.h>
void reverse_string(char arr[])
{
	int lift = 0;
	int right = strlen(arr) - 1;  //strlen可以在函数中求长度， 不像那个sizeof

	while (lift < right)
	{
		char temp = arr[lift];
		arr[lift] = arr[right];
		arr[right] = temp;

		lift++;
		right--;
	}
}

int main()
{

	char arr[] = "abcdef";
	reverse_string(arr);

	printf("%s", arr);

	return 0;

}
```

1. 递归函数解决方法

```csharp
//递归解决方法

//思考
//abcdef
//先交换a和f 再交换bcde
//bcde先交换d和e，再交换
//*str 就是第一个元素的地址
//*(str+1) 就是第二个元素的地址
//目的是让每次进去之后的长度变小。这样就可以一直交换了
//把最后一位填成 \0
#include <stdio.h>
//要求：不能使用函数
不能更改传参
int my_strlen(char* str)//我的求长函数
{
	int count = 0;
	while (*str != '\0')    //数到\0停下
	{
		count++;
		str++;
 	}

	return count;
}
//要保证每次传入的时候，第一个元素和最后一个元素的下标变化
void reverse_string(char* str) //存是整个字符串的地址  地址是首元素的地址  
{
	//先把最后一个放到第一个的位置
	int right = my_strlen(str) - 1; //求最后一个元素的下标 
	printf("现在的字符长度%d\n", right);
	char temp = *str;//临时储存第一位元素
	*str = *(str + right);//把最后一个元素赋值给第一个元素
	*(str + right) = '\0';//把最后一位元素填充为‘\0’
	//开始下一轮
	if (my_strlen(str + 1) > 1)//停止递归的条件：当下一次递归如果就剩一个数字了，就不用递归了.这个要提前算一下
	{
		reverse_string(str + 1); //能保证下一次str往右移动一位
	}
	*(str + right) = temp;//然后依此把临时变量放到他们的最后一个元素
}

int main()
{

	char arr[] = "abcdef";

	reverse_string(arr);

	printf("%s", arr);
	return 0;

}
```

## 计算所有数字之和（递归实现）

```csharp

//-----------------------------------
//计算一个数的所有数字之和
//使用递归

//1234
//123+4
//12+3
//1+2

//输入正整数

#include <stdio.h>

int DogitSum(unsigned int n)
{

	if (n > 9)
	{
		return DogitSum(n / 10) + n % 10;
	}
	return n;
}
int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	int sum = DogitSum(n);
	printf("%d", sum);
	return 0;

}

```

## 实现输出n的k次方（递归实现）

```csharp

#include <stdio.h>

double cf(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k > 0)
	{
		return n * cf(n, k - 1);
	}
	else if (k < 0)
	{
		return 1.0 / cf(n, -k);
	}
}

int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double num = cf(n, k);
	printf("%lf", num);
	return 0;
}

```

## 数组的类型

```csharp
//数组的类型是 int [10]
#include <stdio.h>

int main()
{
	int num = 10;
	int arr[10] = { 0 };
	printf("%d\n", sizeof(num));//4
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(arr));  //40
	printf("%d\n", sizeof(int [10]));  //40

	return 0;
}
```

## 扫雷游戏带0-9棋盘扩展和雷自定义

### `test.c`

```csharp
#define _CRT_SECURE_NO_WARNINGS

//写一个扫雷游戏
//我自己想加一些扩展
//功能1：自适应棋盘，可以随意修改棋盘大小
//功能2：扫雷，扫到雷就炸，否则判断周围有无雷
//没有雷就继续扫，扫到附近有雷才停。然后显示有几个雷
//递归实现
//带插旗的功能
//每次输入完可以清屏，然后显示画面
//具有调试功能(作弊)
//输入 (x，y,1为查炸弹 2为插旗)   
//棋盘1   BOM是存放炸弹的   1为炸弹，  0为空气
//棋盘2   SHOW是用来显示给玩家看的 

#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));//设置随机种子
	int input = 0;
	char arrBom[ROWS][COLS] = { ' '};
	char arrShow[ROWS][COLS] = { '*' };
	do
	{
		menu();
		printf("请输入游戏模式:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				system("cls");//输入模式后清屏
				InitBoard(arrBom, arrShow, ROWS, COLS);//初始化棋盘
				SetBom(arrBom, ROWS, COLS, SetBomNum);//随机埋雷
				DispalyShow(arrShow, ROW, COL);//显示show棋盘
				//DispalyBom(arrBom, ROW, COL);//显示bom棋盘
				while (1)
				{
					int a = Boardinput(arrBom, arrShow, ROWS, COLS);//输入
					if (a == -1)//返回-1被炸死，否则继续
					{
						DispalyBom(arrBom, ROW, COL);//显示bom棋盘
						break;
					}
					int win = Win(arrBom, arrShow, ROWS, COLS);//判断输赢
					if (win == 1)
					{
						DispalyBom(arrBom, ROW, COL);//显示bom棋盘
						break;
					}
					DispalyShow(arrShow, ROW, COL);//显示show棋盘
					//DispalyBom(arrBom, ROW, COL);//显示bom棋盘
				}
				break;
			}
			case 2:
			{
				system("cls");//输入模式后清屏
				printf("已开启作弊模式\n");
				InitBoard(arrBom, arrShow, ROWS, COLS);//初始化棋盘
				SetBom(arrBom, ROWS, COLS, SetBomNum);//随机埋雷
				DispalyShow(arrShow, ROW, COL);//显示show棋盘
				DispalyBom(arrBom, ROW, COL);//显示bom棋盘
				while (1)
				{
					int a = Boardinput(arrBom, arrShow, ROWS, COLS);//输入
					if (a == -1)//返回-1被炸死，否则继续
					{
						DispalyBom(arrBom, ROW, COL);//显示bom棋盘
						break;
					}
					int win = Win(arrBom, arrShow, ROWS, COLS);//判断输赢
					if (win == 1)
					{
						DispalyBom(arrBom, ROW, COL);//显示bom棋盘
						break;
					}
					DispalyShow(arrShow, ROW, COL);//显示show棋盘
					DispalyBom(arrBom, ROW, COL);//显示bom棋盘
				}
				break;
			}
			case 3:
			{
				printf("\n输入行、列、和操作\n");
				printf("中间用空格隔开\n");
				printf("1操作为查雷、2操作为插旗 或者 取旗\n");
				printf("如\"1 1 2\",意思是在坐标为1 1 的地方查棋子(@)\n\n");
			}

		}

	} while (input);
	return 0;
}
```

### `game.c`

```csharp
#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//菜单
void menu()
{
	printf("*******************************************\n");
	printf("*****           0.退出游戏            *****\n");
	printf("*****           1.开始游戏            *****\n");
	printf("*****         2.开启透视模式          *****\n");
	printf("*****         3.游戏操作指南          *****\n");
	printf("*******************************************\n");
}

//初始化棋盘
//把两个棋盘都赋值为0  或者   '*'
void InitBoard(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			if (arrBom[0][0] == ' ')
			{
				arrBom[i][j] = ' ';
			}
			if (arrShow[0][0] == '*')
			{
				arrShow[i][j] = '*';
			}
		}
	}
}

//打印用户棋盘
void DispalyShow(char arrShow[ROWS][COLS], int row, int col)//显示show棋盘
{

//实际上的数组
//   |   |   |   |   |   |
//---|---|---|---|---|---|---
//   | * | * |   |   | * |
//---|---|---|---|---|---|---
//   | * |   |   |   |   |
//---|---|---|---|---|---|---
//   |   |   |   |   |   |

//需要打印的数组
//	5列打印五次"|---" 6次|
//                
//   |---|---|---|---|---|
//   | * | * |   |   | * |
//   |---|---|---|---|---|
//   | * |   |   |   |   |
//   |---|---|---|---|---|
	int i = 0;
	int j = 0;

	//打印列坐标
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	//打印第一行
	printf("   ");
	for (j = 0; j < col ; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//打印行坐标
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrShow[i + 1][j + 1]);
		}
		printf("|\n");
		//兜底
		printf("   ");
		for (j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}

//打印作弊棋盘
void DispalyBom(char arrBom[ROWS][COLS], int row, int col)//显示show棋盘
{
	int i = 0;
	int j = 0;
	//打印列坐标
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	//打印第一行
	printf("   ");
	for (j = 0; j < col; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//打印行坐标
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrBom[i + 1][j + 1]);
		}
		printf("|\n");
		//兜底
		printf("   ");
		for (j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}

//随机埋雷
void SetBom(char arrBom[ROWS][COLS], int rows, int cols, int num)
{
	int x = 0;
	int y = 0;
	int count = num;//定义雷的数量
	while (count)//一直埋雷，直到够数
	{
		x = rand() % (rows - 2) + 1;  //x范围是1 -  rows-2
		y = rand() % (rows - 2) + 1;  //y范围是1 -  rows-2
		//这个地方必须不是字符!才能埋雷
		if (arrBom[x][y] != '!')
		{
			arrBom[x][y] = '!';
			count--;
		}
	}
}

//输入坐标值，插旗或者查炸弹
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
//输入坐标值，插旗或者查炸弹
//插旗好弄，主要是查炸弹
//需要用到递归，思考一下怎么弄
//如果周围炸弹为0，则继续查周围八个格子是否有炸弹。有则继续递归。直到Show棋盘的字符为非0才行
//还要注意递归的范围不能超过范围，所以直接传送过来大棋盘。+2的
//字符0的ASCII码为48
// 查雷则显示附近的雷的数量。插旗则显示@，插旗后再插就是取消插旗
	int x = 0;
	int y = 0;
	int n = 0;
	printf("请输入坐标及操作:>");
	scanf("%d %d %d", &x, &y, &n);
	system("cls");//输入坐标后清屏
	if (1 <= x && x <= rows && 1 <= y && y <= cols && (n == 1 || n == 2))//判断坐标是否符合范围
	{
		if (n == 2)//旗部分
		{
			if (arrShow[x][y] == '*')//如果为*则插旗，如果为@则变为*，如果为数字0-8.则不能插旗 48 +8 = 56
			{
				printf("插旗成功，坐标为%d %d\n", x, y);
				arrShow[x][y] = '@';
			}
			else if (arrShow[x][y] == '@')
			{
				printf("取旗成功，坐标为%d %d\n", x, y);
				arrShow[x][y] = '*';
			}
			else if (48 <= arrShow[x][y] && arrShow[x][y] <= 56)//字符转ASCII码
			{
				printf("这个地方查过了，换一个地方插旗吧\n");
			}
		}
		if (n == 1)//炸弹部分  把坐标传过去，并且还要两个数组以及大棋盘的长和宽
		{
			if (arrBom[x][y] == '!')//被雷炸死了
			{
				printf("你被雷炸死了\n");
				return -1;
			}
			else
			{
				FindBom(arrBom, arrShow, rows, cols, x, y);//递归查找函数
			}
		}
	}
	else
	{
		printf("格式错误！\n");
		printf("格式为：行号 列号 1或2\n");
		printf("1为查雷，2为插旗\n");
	}
}

//递归查找函数
//停止条件：周围的炸弹和>=1
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols, int x, int y)
{
//查坐标周围八个的和是不是0 ，否则继续向八个坐标递归,并且把当前的坐标替换为他们的和
//因为是字符，' '的ascii是38     雷'！'的ascii是39  

// x-1,y-1   x-1,y     x-1,y+1
// x,y-1      x,y      x,y+1
// x+1,y-1   x+1,y     x+1,y+1

//如果查到的x y坐标为大棋盘的边界坐标，那么就停止查找
	if (x == 0 || x == rows || y == 0 || y == cols)
	{
		return;//停止
	}
	// 如果该单元格已经被揭露，则不再处理
	if (arrShow[x][y] == ' ') 
	{
		return;
	}
	//计算雷的个数
	int count = (arrBom[x - 1][y - 1] +
		arrBom[x - 1][y] +
		arrBom[x - 1][y + 1] +
		arrBom[x][y - 1] +
		arrBom[x][y + 1] +
		arrBom[x + 1][y - 1] +
		arrBom[x + 1][y] +
		arrBom[x + 1][y + 1]) - (8 * ' ');
	if (count != 0)//则有炸弹,显示炸弹个数
	{
		arrShow[x][y] = '0' + count;//注意show是字符，所以应该+ '0'
	}
	else//当前位置为0 则继续向下递归，并且把当前的字符换为' '
	{
		arrShow[x][y] = ' ';
		FindBom(arrBom, arrShow, rows, cols, x - 1, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x - 1, y);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x - 1, y + 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x, y + 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y + 1);//递归继续查找
	}
}

//判断输赢
int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	//如果show棋盘的*等于bom棋盘的!就代表剩下的都是雷，则胜利
	int showbom = 0;
	int bom = 0;

	int i = 0;
	int j = 0;
	//计算arrbom中的!
	for (i = 1; i < rows - 2; i++)
	{
		for (j = 1; j < cols - 2; j++)
		{
			if (arrBom[i][j] == '!')
			{
				bom++;
			}
			if (arrShow[i][j] == '*')
			{
				showbom++;
			}
		}
	}
	if (showbom == bom)//则胜利
	{
		printf("你赢了\n");
		return 1;
	}
}
```

### `game.h`

```csharp
#define _CRT_SECURE_NO_WARNINGS

//定义棋盘大小
#define ROW 9
#define COL 9
//定义棋盘外围一圈大小
#define ROWS ROW+2
#define COLS COL+2

//定义埋雷数量
#define SetBomNum 10
#include <stdio.h>
#include <windows.h>//清屏所用头文件
#include <stdlib.h> //随机函数头文件
#include <time.h>//时间头文件
//菜单
void menu();

//初始化棋盘
void InitBoard(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);

//显示show棋盘
void DispalyShow(char arrShow[ROWS][COLS], int row, int col);

//显示Bom棋盘
void DispalyBom(char arrBom[ROWS][COLS], int row, int col);

//随机埋雷
void SetBom(char arrBom[ROWS][COLS], int row, int col, int num);

//输入坐标值，插旗或者查炸弹
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);
//递归查找炸弹
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols ,int x, int y);

int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);
```

## 删除10个数字中某个数字，并打印

```csharp
#define _CRT_SECURE_NO_WARNINGS

//写一个函数，能够删除指定数字中的某个数字
//比如1234526
//删除2 后是13456
//在这里的思路是，有i和j同时遍历数组
//i负责遍历数组中的值是不是指定数字2
//j负责储存下标，当i发现指定数字，那么j不变
//j等待i发现下一个不是2的数字然后将其填入下标为j的数组中。
#include <stdio.h>

int Del(int arr[], int sz, int a)
{
	int i = 0;
	int j = 0;
	for (i = 0,j = 0; i < sz; i++)
	{
		if(arr[i] != a)//如果不等于a就赋值，然后j++
		{
			arr[j] = arr[i];
			j++;
		}
	}
	return j;//返回删除后数组的长度
}
int main()
{

	//填入数字到数组
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("请输入下标为%d数字:>", i);
		scanf("%d", &arr[i]);
	}
	//输入要删除的数字
	int a = 0;
	printf("请输入要删除的数字:>");
	scanf("%d", &a);
	//删除函数
	int sz = sizeof(arr) / sizeof(arr[0]);
	int num = Del(arr, sz, a);
	//打印删除后的函数
	for (i = 0; i < num; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
```

## 输入10个整数成绩，求最高和最低分之差

```csharp
//输入10个整数成绩，求最高和最低分之差
//分数范围为0 - 100
//思路，边输入边找最大值和最小值
#include <stdio.h>
int main()
{
	int a = 0;
	int max = 0;
	int min = 100;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("\n输入第%d个数字:>", i + 1);
		scanf("%d", &a);
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	printf("最大值和最小值的差是：%d", max - min);
	return 0;
}
```

## 写一个程序，输入大写字母输出小写的字母，反之亦然

```csharp
//写一个程序，输入a他输出A
//输入A他输出a

#include<stdio.h>

int main()
{
	char n = 0;
	while (scanf("%c", &n)== 1)//有输入则返回1
	{
		if (n >= 'a' && n <= 'z')
		{
			printf("%c\n", n - 32);
		}
		//如果不加这个if 需要用getchar来把后面的\n吃掉
		//或者在输入的时候，在%c之前加空格， 意思就是跳过所有的空白字符
		//scanf(" %c", &n)== 1
		else if (n >= 'A' && n <= 'Z')
		{
			printf("%c\n", n + 32);
		}
	}
	return 0;
}

```

## 水仙花变种题

```csharp

//描述
//变种水仙花数 - Lily Number : 把任意的数字，从中间拆分成两个数字，
// 比如1461可以拆分成(1和461)，(14和61)，(146和1), 
// 如果所有拆分后的乘积之和等于自身，则是一个Lily Number.
//例如 :
//	655 = 6 * 55 + 65 * 5
//	1461 = 1 * 461 + 14 * 61 + 146 * 1
//	求出 5位数中的所有 Lily Number。
//输出描述 :
//一行，5位数中的所有 Lily Number，每两个数之间间隔一个空格。
 
//思路，五位数中， 
// 前4个数字是54321/10  最后1个数字是54321%10
// 前3个数字是54321/100 最后2个数字是54321%100
//...
// 第1个数字是54321/10000 最后4个数字是54321%10000

#include <stdio.h>
#include <math.h>//数学头文件
int main()
{
	int i = 0;
	for ( i = 10000; i <= 99999; i++)
	{
		int sum = 0;
		int j = 0;
		for (j = 1; j <= 4; j++)
		{
			int k = (int)pow(10, j);//pow为次幂函数得到的值是double类型
			sum += (i / k) * (i % k);
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
```

# 操作符

### 原码，反码，补码

> **左移右移操作符只针对整数**
> 

**正整数**的原码、反码、补码相同

**负整数**的原码、反码、补码需要计算

7的`原码`是00000000000000000000000000000111

7的`反码`是00000000000000000000000000000111

7的`补码`是00000000000000000000000000000111

> 整形需要占四个字节， 一个字节是8个bit
因为7是整数，所以他的最高位为
> 

-7的`原码`是10000000000000000000000000000111

-7的`反码`是**符号位不变，其余取反**：111111111111111111111111 11111000

-7的`补码`是**反码加1**，11111111111111111111111111111001

**补码算反码的话就是先减1，然后符号位不变，其余取反**

> 整数在内存中存储的是补码
> 

### 左移操作符

左移操作符 `<<`  左边丢弃，右边补0

**对7左移**

```csharp
int a = 7;
int b = a << 1;
printf("%d",b);
```

补码：    00000000000000000000000000000111

左移后：00000000000000000000000000001110

转换为原码：(正整数相同)
00000000000000000000000000001110
输出14

**对-7左移**

```csharp
int a = -7;
int b = a << 1;
printf("%d",b);
```

补码：   11111111111111111111111111111001

左移后：11111111111111111111111111110010

转换为原码：(负整数计算)
**减1取反(符号位不变)**
11111111111111111111111111110001

100000000000000000001110
=8+4+2=14
输出**-14**

综上：**左移操作符的特点是乘2**

### 右移操作符

右移操作符分为`算术移位`和`逻辑移位`

> 算数移位是 右边丢弃  左边补`原符号`
逻辑移位是 右边丢弃  左边补`0`
> 

编译器都是按照算数右移来操作的。

不管是左移还是右移。都不要出现 << -2  或者 2.5这种弱智行为

## 按位与 &，按位或 | 、按位异或 ^

1. 按位与
    
    ```csharp
    int a = 3;
    int b = -5;
    int c = a & b;
    ```
    
    先写出a、b的二进制补码
    
    ```csharp
    a的原码是00000000000000000000000000000011
    b的原码是10000000000000000000000000000101
    b的反码是01111111111111111111111111111010
    b的补码是01111111111111111111111111111011
    a的补码是00000000000000000000000000000011
    他们的按位与时每个二进制码对应的与
    那么a&b得00000000000000000000000000000011
    再弄成原码就是0000000.......00000000000011
    ```
    
    所以c的值就是3了！
    
    同理 `或` 和 `异或`  就可以理解了
    

## 不用临时变量，交换两个数字

因为异或支持交换律

```csharp
0^5 = 5
3^3^5 = 5
3^5^3 = 5
```

那么如果有

```csharp
a = 3
b = 5
//要交换a和b
a = a ^ b//3 ^ 5
b = a ^ b//3 ^ 5 ^ 5
a = a ^ b//3 ^ 5 ^ 3
```

牛逼

## 写一个程序，整数存储在内存中1的个数

也就是说求补码中1 的个数 

```csharp
#define _CRT_SECURE_NO_WARNINGS
//写一个程序，能求出整数在内存中的1的个数
//也就是求补码的1的个数
//思路，用到左移和按位与。相同为1，不同为0
//比如7的补码是000....111
//而1的补码是0000.....001
//那么第一次7&1的结果是1
//那么将7右移，再次与还是1
//再次右移，还是1
// 再次右移时，就为0了。

#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d", &a);
	//求出这个数在内存中站多少个bit
	int bit = sizeof(a) * 8;

	int count = 0;//计数

	int i = 0;
	int j = 0;
	//有多少个bit 就移动bit-1次
	for (i = 0; i < bit - 1; i++)
	{
		if (((a >> i) & 1) == 1)//向右移动啊！
		{
			count++;
		}
	}

	printf("%d", count);
	return 0;
}
```

## 赋值操作符

赋值操作符是可以连续赋值的

```csharp
int a = 10;
int x = 0;
int y = 20;
a = x = y + 1;//x=y+1 \ a = x(x=y+1)
```

**由右向左。**语法支持，但是不建议这样写

复合付赋值符

> +=
-=
*=
/=
%=
>>=
<<=
&=
|=
^=
> 

## 单目操作符

对一个数操作的叫单目操作符

> !              逻辑反操作
-            负值
+             正值
&                 取地址
sizeof            操作数的类型长度，字节为单位
~                对一个数的二进制位**按位取反**
—           前置、后置—
++          前置、后置++
*              间接访问操作符（解引用操作符）
(类型)     强制类型转换
> 

## 把某一位bit从0变成1 或者从1变成0

从0变1 用按位或1 其余为0 就可以

```csharp
比如原来是a= 000000….0001101
想把他变成a= 000000….0001111
那么只需要把第二位的0变成1就ok
也就是说
只需要或上  000000...000010就可以了
a | (a << 1);
如果要变成00000000...0011101
**那么久是a | (a << 4);**
```

从1变0. 用按位与0，其余为1

```csharp
比如原来是a= 000000….0001101
想把他变成a= 000000….0000101
那么只需要把第4位的1变成0就ok
也就是说
只需要与上  1111111..1110111就可以了
**而这个数需要用00000...000100获得**
**a | (~(a << 3));**
```

## ++ , —操作符

`++a`    #前置++，**先++ 后使用**

`a++`    #后置++，**先使用，后++**

## 间接访问操作符 *（解引用操作符）

```csharp
int a = 10;
int* p =&a;  //类型是int*   p为指针变量
*p = 20;   //*p是对p进行解引用。通过p中的地址，找到它锁指的对象 意思就是对a赋值20
```

## sizieof的再理解

```csharp
int arr[10] = {0};
char ch[10 = {10};
peintf("%d\n",sizeof(arr));//40
peintf("%d\n",sizeof(ch));//10
test1(arr);
test2(ch);

void test1(int arr[])//传入的是指针变量
{
	printf("%d\n",sizeof(arr));//x86=4    x64 =8
}
void test2(int arr[])//传入的是指针变量
{
	printf("%d\n",sizeof(ch));//x86=4    x64 =8
}
```

## 关系操作符

没什么可讲的，>    <    >   >=    <=   !=      =     

注意字符串不能用== 。应该用`strcmp`  并添加`string`头文件
如果用==  实际上比的是两个字符串的呃首地址 `abc == abcde`

## 逻辑操作符||   &&

逻辑与 、逻辑或

他们只关注真假，**大于0则为真**   不关注按位 ||   &&

没啥好说，但可以有在这道题来出

这里的运算是 && 为从左到右计算

**短路求值类题**

```csharp
int i = 0, a = 0, b = 2 , c = 3 ,d = 4；
i = a++ && ++b && d++;
printf("a = %d , b = %d, c= %d, d = %d)；
```

这道题因为a++ && ++b
a++是先使用再++  所以相当于 0&& b 所以后面的就相当于不用算了

所以这道题只有a++了，和后面的都没加  也叫做**`短路求值`**

所以这道题的结果是 1 2 3 4 

如果让a  初始值为 1  

```csharp
int i = 0, a = 1, b = 2 , c = 3 ,d = 4；
i = a++ && ++b && d++;
printf("a = %d , b = %d, c= %d, d = %d)；
```

那么输出值就是 2 3 3 5

如果题中的&&变成 ||

```csharp
int i = 0, a = 1, b = 2 , c = 3 ,d = 4；
i = a++ || ++b || d++;
printf("a = %d , b = %d, c= %d, d = %d)；
```

因为a 为1  所以只有a++运算了，  后面直接就为1 了 不需要算了。

所以答案是 2 2 3 4

如果题中a的初始值为0 ，那么

```csharp
int i = 0, a = 0, b = 2 , c = 3 ,d = 4；
i = a++ || ++b || d++;
printf("a = %d , b = %d, c= %d, d = %d)；
```

a++ 和  ++b 就需要算了  他们或之后为1   后面的就不需要算了

所以答案是1 3 3 4

## 条件操作符

> 又称为三目操作符
> 

表达式1 ？ 表达式2： 表达式3

如果表达式1 为真，那么表达式2计算

如果表达式1 未假，那么表达式3计算

## 逗号表达式

逗号表达式，是从左到右依次计算，最后一个为表达式的结果

比如

```csharp
int a = 0;
int b = 5;
int c = 3;
int a = (c = a + b, b = a - c,b = 3 + b);
```

那么a 就等于 3+b   =  3+(a-c)  = 3+(a-a-b) = 3+0-5=-5 .

利用逗号表达式可以很方便的让我们的代码更加的整洁

比如，原本的一个递归函数是

```csharp
a = get_val();
count_val(a);
while(a> 0)
{
	//业务处理
	a = get_val();
	count_val(a);
}
```

这个函数就是，一直递归，直到a=0
但是看着还是有一些臃肿的
我们用逗号表达式可以这样来写

```csharp
while(a = get_val(),count_val(a),a>0)
{
	//业务处理
}
```

## 下表引用、函数调用和结构成员

### 下表引用

```csharp
int main()
{
	int arr[10] = {0};
	arr[7] = 8;
	
	return 0;
}
```

其中`[]` 为**下表引用操作符**  他的操作数是 `arr` 和 `7`

所以你也可以写成`7[arr] = 8`他的结果是一样的

其实啊。

> `arr[7]` 其实等于 `*(arr+7)`  其中 arr是数组首元素的地址  arr+7就是arr的第八个元素，而*就是解引用。对他的第八个地址解引用。
> 

### 函数调用

```csharp
//函数定义
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 10;
	int b = 20;
	//函数调用
	int c = Add(a,b);//(函数调用操作符)
}
```

可以看到`( )` 是函数调用操作符
他的操作数函数Add和a  ，b 

函数在调用的时候，操作数至少是一个

### 结构成员

代码1
这里的函数在传参的时候，只是传送了一个s 
那么形参就相当于是实参s的一份临时拷贝，
我们再函数中对ss的一切操作都不会影响到实参的s
所以我们应该用指针去指到实参s的地址

```csharp
struct Stu
{
	char name[20];//名字
	int age;//年龄
	double score;//分数
}

void set_stu(struct stu ss)
{
	strcpy(ss.name, "zhangsan");//使用strcpy来赋值字符串
	ss.age = 20;
	ss.score = 100.0;
}
void printf_stu(struct stu ss)
{
	printf("%s %d %lf",ss.name,ss. age, ss.score)
}
int main()
{
	struct Stu s = {0}; //定义一个s对象
	set_stu(s)//函数给s设置值
	print_stu(s)//函数打印s里的值
	return 0;
}
```

代码2:
这里我们把s的指针传送过去，&s。
对应的形参也要修改成保存地址的指针类型
在使用的时候，我们应该对他进行解引用，来正确的指到我们想要的变量的身上。
其中。printf_stu就不用指针传参了，因为他只负责打印，是不是临时拷贝不重要。只要值一样就OK。**但是为了不浪费内存空间**，我们可以把& 加上~~

但是这个代码还可以这样写， 这样他的观赏性就会好很多，  不用* 了

```csharp
struct Stu
{
	char name[20];//名字
	int age;//年龄
	double score;//分数
}

void set_stu(struct stu* ps)
{
	strcpy((*ps).name, "zhangsan");//使用strcpy来赋值字符串
	(*ps).age = 20;
	(*ps).score = 100.0;
}
void printf_stu(struct stu ss)
{
	printf("%s %d %lf",ss.name,ss. age, ss.score)
}
int main()
{
	struct Stu s = {0}; //定义一个s对象
	set_stu(&s)//函数给s设置值
	print_stu(s)//函数打印s里的值
	return 0;
}
```

代码三

在这里我们用到了`箭头操作符`

```csharp
struct Stu
{
	char name[20];//名字
	int age;//年龄
	double score;//分数
}

void set_stu(struct stu* ps)
{
	strcpy(ps->name, "zhangsan");//使用strcpy来赋值字符串
	ps->age = 20;
	ps->score = 100.0;
}
void printf_stu(struct stu ss)
{
	printf("%s %d %lf",ss.name,ss. age, ss.score)
}
int main()
{
	struct Stu s = {0}; //定义一个s对象
	set_stu(&s)//函数给s设置值
	print_stu(s)//函数打印s里的值
	return 0;
}
```

> 箭头操作符使用时 是   结构体指针 -> 成员
> 

> 点操作符使用时     是   结构体对象 .  成员
> 

```csharp
ps -> age
(*ps) . age 
//这两个代码其实是一样的。等价的
```

## 表达式求值

> 表达式求值的顺序一部分是由操作符的优先级和结合性来决定
同样，**有些表达式的操作数在求值的过程中可能需要转换为其他类型**
> 

优先级问题，   乘除的优先级是超过加减的

结合性问题，优先级相同的情况下不同的符号他的计算顺序不一样（L→ R 或者R→ L）

### 隐式类型转换

C的整数算数运算总是包含至少以缺省整形类型的精度来精度来进行的
缺省（是至少默认用整形的）

为了获得这个精度，表达式中的字符或短整形操作数在使用之前被转换为普通整形，这种整形称为**整形提升**

**举个栗子**

```csharp
char a = 5：
char b = 126;
cahr c = a + b;
printf("%d\n",c);
```

比如 5  + 126  但是char的字节大小是1  所以他需要进行整形提升  变成字节大小为4 的int型

下面我把这个计算的步骤写出来

cahr类型的bit位是8个，意味着他只能存储8位二进制数字。

1. `char a = 5；`的阶段中
因为5的的二进制序列为`00000000000000000000000000000101` 
但是char类型只能存储8个bit 所以他存储的就是00000101
2. 同理，在`char b = 126;`的阶段中
因为126的的二进制序列为`00000000000000000000000001111110`
char b 中存储的是`01111110`  
3. `在char  c = a + b;` 中，a和b的大小才8个bit 不足以进行整形相加
所以此时就有发生了**整形提升
a** 变为了`00000000000000000000000000000101`  
b 变为了`00000000000000000000000001111110` 
那么他们在相加后c就是`000000000000000000000000100000011` 
但是char c不足以放那么多，只能取8位，也就是`10000011` 
4. `printf("%d\n",c);` 时，因为c的值只有8为，不能打印整形
所以又发生了整形提升。char c在提升为整形的时候，**取了第bit位最左边的值为符号**位。所以这个值就变成了`11111111111111111111111110000011`
在把他变成反码（减1 取反.符号位不变）`10000000000000000000000001111101`
打印出来也就是  **负的 125**

**再举个例子**

```csharp
int main()
{
char a= 0xb6;
short b = 0xb600;
int c= 0xb6000000;
	if(a == 0xb6)
		printf(“a");
	if(b == 0xb600)
		printf("b");
	if(c == 0xb6000000)
		printf("c");
return 0;
}
```

其中 char  short   字节是2 和4  那么他们都会进行整形提升 所以最后只会**输出c**

**再举个栗子**

```csharp
char c = 1;
// %u 是无符号整形数
prinft("%u\n",sizeof(c));
prinft("%u\n",sizeof(-c));
prinft("%u\n",sizeof(+c));
```

这里的结果是1  4  4  因为-c  +c  都进行了整形提升

**整形提升的意义：**

> 表达式的整型运算要在CPU的相应运算器件内执行，CPU内整型运算器(ALU)的操作数的字节长度-般就是int的字节长度，同时也是CPU的通用寄存器的长度。
因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。
通用CPU(general-purpose CPU)是难以直接实现两个8比特字节直接相加运算(虽然机器指令中可能有这种字节相加指令)。所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。
> 

### 算数转换

> long double
double
float
unsigned long int
long int
unsigned int
int
> 

如上表， 在进行运算的时候，排名低的会转换为排名高的类型，然后进行运算

double f  = 3.14;

int num = f //隐式转换， 会精度丢失

### 操作符的属性

复杂的表达式有三个影响因素

1. 操作符优先级：[C语言运算符优先级（超详细）-CSDN博客](https://blog.csdn.net/yuliying/article/details/72898132)
2. 操作符的结合性
3. 是否控制求值顺序

> 两个相邻的操作符先执行那个？取决于他们的**优先级。**如果两者的优先级相同，取决于他们的**结合性**
> 

不然在有相互影响的表达式时，就会存在问题

比如a*b + c*d + e*f

不管  1    3   2     5   4 

还是   1   4   2     5    3

的计算顺序，都复合我们的优先级和结合性、但是在复杂表达式中的计算结果是不一样的！**或者干脆在不同编译器下的结果是不同的**

> **在写代码的时候，一定要让表达式的计算有唯一路径的** 不然就是有问题的！！！
> 

## 写一个函数，输入两个数字。输出他们的二进制数有几位不同。异或法 和 移位对比法

> 写法1   按位比较
> 

```csharp
int	count_diff_bit(int a, int b)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) != ((b >> i) & 1))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = count_diff_bit(a, b);
	printf("%d", c);
	return 0;
}
```

> 写法2  异或比较
> 

```csharp

int	count_diff_bit(int a, int b)
{
	int n = a ^ b;//求出多少个位不一样（在二进制中为1）
	//找出1的个数
	int count = 0;
	while (n)
	{
		n = n & n - 1;
		count++;
	}
	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = count_diff_bit(a, b);
	printf("%d", c);
	return 0;
}
```

## 打印数字中二进制序列的奇数位和偶数位

偶数位从0开始

```csharp
//打印一个数字中的二进制序列中的奇数位和偶数位
//偶数位从0开始 
#include<stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);

	//打印偶数位。从左往右打印。
	//最左边需要想左直接移动31位数字
	int i = 0;
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}

	return	0;
}
```

## 打印可以根据输入动态变化的x

```csharp

//输出x。会根据n的输入而变换
#include <stdio.h>
int main()
{
	int n = 0; 
	while (scanf("%d", &n) == 1)
	{
		int i = 0; int j = 0; 
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j)
				{
					printf("*");
				}
				else if (i + j == n - 1)//由右上到左下
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
```

## 输入年份，月份，输出这个月天数

```csharp
//输入年份、月份输出这个月的天数
int is_leap_year(int y)
{
	return(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

int main()
{
	int y = 0; 
	int m = 0; 
	int d = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d %d", &y, &m) == 2)//正确输入两个则返回2
	{
		int d = days[m];
		if ((is_leap_year(y) == 1) && (m == 2))
		{
			d++;
		}
		printf("%d\n", d);
	}
}
```

# 指针

## 指针是什么

> **指针是内存中最小单元的一个编号**，也就是地址
平时口语中说的指针，通常指的是指针变量，是用来存放内存地址的变量
> 

针对`int a = 10` 运行时就会在内存中**开辟4个字节的内存**
而取a的地址时。`&a` 所拿出来的地址时第**一个字节的地址**
如果我们要把这个地址存起来，就要用`int* pa = &a;`
其中`pa`是指针变量，是**用来存放地址的**
本质上指针就是地址
口语中说的指针其实是指针变量，指针变量就是一个变量而已。
指针变量是用来存放地址的一个变量！
通过指针变量中存放的地址，可以找到一个内存单元

- 一个内存大小是1字节
- 编址空间

在一个32位的机器上，有32根地址线，就有2^32次方种可能。也就是2^32次方Byte经过换算，也就是4GB。而指针变量就是记录这32跟线的高低电平。对于32位的，就需要32Byte的空间，也就是4字节

同理64位的机器也是一样。他则需要8字节才能存储

> 综上：32位的电脑的指针变量的大小是4个字节。 64位的电脑的指针变量的大小为8个字节
> 

## 指针和指针类型

### 指针 +  - 整数

> int*
char*
double* 
…..
> 

这么多指针变量。他们在32位环境下都是存放4个字节。那为什么还要有这么多的分类呢？
他们能混用吗？

> 在这里拿int*和char*举个栗子
> 

如果我们定义了`int a = 0x11223344` 0x指的是16进制
此时我们通过监控窗口可以看到在a的地址下存放的4字节是`44 33 22 11`
注意这里是16进制的每个数字是都是用四个Byte来表示。
- 我们现在定义**`int*类型的`**指针变量**`pa`**赋值为`a`的地址   **`int*** pa = &a;`
在运行的过程中，我们可以看到`pa`和 `&a` 所取得的地址是一样的。
如果此时我们令`*pa` 赋值为 0， `*pa = 0；`  可以看到。变量a被赋值为 `00 00 00 00`
所有byte都被赋值为0，代表16进制的0

- 但是如果我们在这里用`char*` 来创建指针变量**`pc`** 来赋值为`a`的地址。编译器会报警告。
但我们如果强制把`&a`来转换为`int*`类型的指针类型。`cahr* pc =(int*)&a；` 
这次在运行的过程中，我们可以看到`pc`和 `&a` 所取得的地址是**仍然**一样的。
但是如果我们此时令`*pc`赋值为 0， `*pc = 0；`  可以看到。变量a被赋值为 `00 33 22 11` 
只有存储`44`的这1个字节被赋值为0。**因为`char*`类型的变量他操作的是一个字节！**

我们如果用`%p`打印`pc`和`pa`  所存储的地址会发现他们是相同的，都是a的地址&a
但是如果用`%p`打印`pc+1` 和`pa+1` 我们会看到**`int*`**类型的指针变量 `pa+1` 比`pa`大了**4个字节**
而**`char*`**类型的指针变量`pc+1`比`pc`只大了1个字节

> **总结：指针的类型决定了指针向前或向后的步长有多大
指针的类型决定了指针的权限（操作几个字节）**
> 

### 指针的解引用

！！注意，即使是类似int*和float*的字节大小一样的也不能混用。
因为不同的指针类型他们对字节内容的**解读是不一样的**。
比如`int* = 100`时。他在内存中存放的是`64 00 00 00`  
而`float* = 100.0`，他在内存中存放的是 `00 00 c8 42`

## 野指针

### 野指针的概念:

> 野指针就是指针指向的位置是不可知的(随机的、不正确的、没有明确限制的)
> 
1. 指针未初始化

```csharp
int* p;
*p = 10;
```

如上代码，p没有初始化，就意味着没有明确的指向
一个局部变量如果不初始化的话，放的是随机值
这里P就是野指针了，他非法访问内存

1. 指针越界访问

```csharp
		int arr[10] = { 0 };
		int* p = arr;//arr[0]
		int i = 0;
		for (i = 0; i <= 10; i++)
		{
			*p = i;
			p++;
		}
		//在p = 10 的一次*p = i时候，p就是野指针了。
		//他的访问超过了数组的范围
```

1. 指针指向的空间释放

这里放在动态的内存开辟的时候讲解，这里做一个简单的演示

```csharp
#include <stdio.h>
int* test()
{
	int a = 10;
	return &a;
}

int main()
{
	int* p = test();
	//如果此时打印*p所指向的空间，结果仍然是上一个局部变量的值，也就是10
	//因为这里的局部变量虽然已经被销毁，但是他的数据仍然还在。只是等待下次被覆盖
	//如果打印一下别的东西，当系统利用到这片空间后。它内部存储的值将发生改变
	//所以打印的也就不是10了
	return 0;
}
```

在这个演示中，p在接受a的地址后，因为a是局部变量。在函数结束后就被释放了。如果你在下面再用a的地址去找到这片区域时它并不能访问。那么p就是野指针了。

### 如何避免野指针的出现

当一个指针不知道初始化什么值的时候，
就把他赋值为空指针NULL
在下次使用的时候，添加if判断。这样就可以避免出现问题

```csharp
int* p = NULL;

if (p != NULL)
{
*p = 100;//如果不为空指针就对他所指向的对象进行赋值。
}
```

如果对空指针赋值，会程序报错

1. 指针初始化
2. 小心指针越界
3. 指针指向空间释放即使置NULL
4. 避免返回局部变量的地址
5. 指针使用之前检查有效性

## 指针的运算

### 指针的+-运算

```csharp
//指针的加减运算
#include <stdio.h>
#define N_VALUES 5
int main()
{
	float valueS[N_VALUES]; 
	float* vp;
	//指针+-整数;指针的关系运算
	for (vp = &valueS[0]; vp < &valueS[N_VALUES];)
	{
		*vp++ = 0;
	}
}
```

这个示例代码中。

`*vp++ = 0;` 为先使用后++所以第0 1 2 3 4 个指针都会被赋值为0 
这里的++指的是地址++
这里的++指的是地址++
并且这里的for循环在检测vp内存储的地址是否小于&valueS[N_VALUES]时。
**虽然看了一眼数组之外的数值**，但是实际并没有操作这块没有权限的空间，
 所以也不是野指针

### 指针-指针

```csharp

//指针减指针
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p1 = &arr[0];
	int* p2 = &arr[9];
	int a = p2 - p1;
	printf("%d", a);
	return 0;
}
```

在这个举例中。`p2` 为最后一个元素的地址，`p1`为第一个元素的地址。他们中间的元素有9个。所以`p2 - p1` 的值打印出来为9

指针-指针实现字符串求长度

```csharp
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return(str - start);
}
```

`start`指向的是第一个字符    在while循环之后`str`指向`’\0’`

### 指针的关系运算

```csharp
//指针的加减运算
#include <stdio.h>
#define N_VALUES 5
int main()
{
	float valueS[N_VALUES]; 
	float* vp;
	//指针+-整数;指针的关系运算
	for (vp = &valueS[N_VALUES]; vp > &valueS[0];)
	{
		*--vp = 0;
	}
}
```

这个代码也可以实现把数组中的五个元素赋值为0  这里的`--vp`是先--后解引用赋值为0,可以避免对下标 为5的没有权限控制的内存空间操作。避免野指针

可以简化一下如上代码。

```csharp
//指针的加减运算
#include <stdio.h>
#define N_VALUES 5
int main()
{
	float valueS[N_VALUES]; 
	float* vp;
	//指针+-整数;指针的关系运算
	for (vp = &valueS[N_VALUES - 1]; vp > &valueS[0];vp--;)
	{
		*vp = 0;
	}
}
```

这里是先判断。然后赋值为0.然后 --  **注意 vp的初始位置改了哈**

**实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。**
标准规定:
**允许**指向数组元素的指针与指向数组最后一个元素**后面的那个内存位置的指针**比较，
但是**不允许**与指向第一个元素**之前的那个内存位置的指针**进行比较。

## 指针和数组

```csharp
//指针和数组
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%p------%p\n", &arr[i], p + i);
	}
	//说明&arr[i], p + i 等价

	return 0;
}
```

## 二级指针

```csharp
//二级指针
#include<stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//pa是一级指针变量
	
	int** ppa = &pa;
	//ppa是指针的指针，是二级指针变量。他存放的是一级指针变量的地址
	//这里的最后边的 *是说明。ppa是指针
	//int* 说明ppa所指向的对象是int*类型
	**ppa = 20;//这样就解引用到了a
	return 0;
}
```

二级指针变量 是 用来存放一级指针变量的 地址

## 指针数组

指针数组可以存放多个变量的指针

```csharp
//指针数组
//存放指针的数组
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };

	int a = 10;
	int b = 20;
	int c = 30;
	int* parr[10] = {&a, &b, &c};
	
	//打印指针数组中的指针
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", * (parr[i]));
	}
	return 0;
}
```

指针数组可以把多个数组模拟为二维数组

```csharp

#include<stdio.h>
int main()
{
	int arr1[4] = { 1,2,3,4 }; 
	int arr2[4] = { 2,3,4,5 }; 
	int arr3[4] = { 3,4,5,6 };
	int* parr[3] = { arr1, arr2, arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d ",parr[i][j]);
			//这里的parr[i]不需要解引用。
			//parr[0]指的是指针变量中存储的第一个元素的地址。
			//也就是arr1的首地址，而arr1的地址等同于arr1。
			//所以parr[0]就等同于arr1
			//加上后面的[j] 则是访问arr1的下标为j的元素。等同于arr1[j]
		}
		printf("\n");

	}
	return 0;
}

```

# 结构体

## 1. 结构体的声明

### 1.1 结构的基础知识

> 结构是一些值的集合，这些值称为成员变量，每个成员可以是不同类型的变量
> 

### 1.2 结构体的声明

```csharp
struct Peo //创建结构体  此时只是一个模板，并没有内存空间
{
char name[20];
char tele[12];
char sex[5];//女男 保密
int high;
};

int main()
{
struct Peo p1 = { 0 };//创建结构体变量  此时才申请内存空间
return 0;
}
```

### 1.3 结构成员的类型

结构体的成员类型可以是标量，数组，指针。甚至是其他的结构体

```csharp
struct Peo //创建结构体  此时只是一个模板，并没有内存空间
{
	char name[20];
	char tele[12];
	char sex[5];//女男 保密
	int high;
};
struct St//结构体中可以有另一个结构体变量。这个结构体依赖于上个结构体
{
	struct peo p;
	int num;
	float f;
};
```

### 1.4 结构体的定义和初始化

> 结构体的创建
> 

结构体后面直接跟变量，则是用他创建了一个全局变量（因为一般结构体都是在`main`函数外边放着的。） 比如这里代码中的`p1,p2,p3,p4;` 就是创建结构体时**同时**创建的结构体变量。

```csharp
struct Peo //创建结构体  此时只是一个模板，并没有内存空间
{
	char name[20];
	char tele[12];
	char sex[5];//女男 保密
	int high;
}p1,p2,p3,p4;
```

也可以在`main`函数或者别的函数中 用`struct  Peo p5` 来创建新的**局部变量**

也可以在`main`函数外边 用`struct  Peo p5` 来创建新的**全局变量。**这些都是可以的

> 结构体的初始化
> 

对于一个结构体，我们在初始化的时候可以直接
`struct peo p5 = {”张三”，“123456789”，“男”，“181”}；`

对于嵌套了结构体的结构体。我们在初始化时需要把结构体的结构体括起来

```csharp
struct st
{
struct peo p;
int num;
float f;
};
```

`struct peo p5 = {{”李四”，“987654321”，“女”，“161”}, 100, 3.14}；`

## 2. 结构体的访问

结构体变量访问成员
结构变量的成员是通过点操作符`.`访问的。点操作符接受两个操作数。

`printf("%s %s %s %d\n",[pl.name](http://pl.name/), p1.tele, p1.sex, p.high);`
结构体变量.成员变量

如果我们接受的是**结构体的指针**。那么我们在访问的时候就需要用**箭头操作符 ->
`printf("%s %s %s %d\n",sp->name,sp->tele,sp->sex, sp->high);`**
结构体指针 -> 成员变量

## 3. 结构体传参

> 函数传参的时候，参数是需要**压栈**的。
如果传递一个结构体对象的时候，结构体过大，**参数压栈的的系统开销比较大，**所以会导致性能的下降。
所以结构体传参的时候尽量去传结构体的**地址**
>