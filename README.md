#### 介绍
学习C语言可以联系的一些题目

### printf打印小飞机
2024-07-09
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
2024-07-09
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
2024-07-09
```
#include <stdio.h>
int main() {
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33);
    return 0;
}
```
- 输出时常用到的如下：
-  **%c**  字符型格式符，作用是读入一个字符。
-  **%d**  表示输出十进制有符号的整数。
-  **%u**  十进制无符号整数。
-  **%f**  表示输出浮点数。
- **%s** 表示输出 字符串。
- **%c** 表示输出单个字符。
- **%p** 表示输出指针的值。
- **%e** 表示输出指数形式的浮点数。
- **%0x** 表示输出无符号以十六进制表示的整数。 
- **.%0** 表示输出无符号以八进制表示的整数。
### 出生日期输入输出
 **输入描述：** 输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
 **输出描述：** 三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。
2024-07-09
```
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
### 学生基本信息输入输出
 **输入描述：** 学号以及3科成绩，学号和成绩之间用英文分号隔开，成绩之间用英文逗号隔开。
 **输出描述：** 学号，3科成绩，保留两位小数
2024-07-09
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
- 格式字符串 "%d;%f,%f,%f" 规定了输入数据的格式，&num、&x、&y、&z 分别表示将输入的值存储到对应的变量地址中。
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
### 输出printf的返回值
2024-07-11
```
#include <stdio.h>

int main() {

    int a = printf("Hello World!");
    printf("\n");
    printf("%d",a);
    return 0;
}
```
printf会打印出字符的个数，\n 等等也算一个字符。
也可以使用
```
printf("\n%d",n);直接打印这样也能换行。
```
### 输出printf("hello world\n");
2024-07-11
这个题考验的是转义字符"\"的运用
```
#include <stdio.h>

int main() {

    printf("printf(\"Hello World!\\n\");\n");
    

}
```
题中的\  “  都需要\转义字符\把他们变成普通的字符.
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
### 计算球得体积
 **输入：**一个浮点值0-15
 **输出：**球的体积，小数点保留三位
这个题考察的是float和double的区别
float占4字节， double占8字节，所以double的精度会更高
float在初始化的时候是float = 0.0f：
double在初始化的时候是float = 0.0lf;或者 0.0   因为0.0默认使用的是double
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
### 计算n的阶乘
2024-07-11
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
比如数组为{1,2，3,4,5,6,7,8,9,10,11,12，13,14,15,16,17,18,19,20}
 **二分查找的应用范围是：**被查找的数组是一个有序的数组，上数组符合要求
 **过程如下** 
1. 二分查找要定义 左范围值（ **下标为0** ） 和 右范围值（ **下标为元素-1** ） 和 查到的找值（下标为左值与右值中间）
2. 通过备查找到的值与待找到值比较。
- 如果查找到的值 **大于**待找到的值，也就表示 **待查找值** 在 **左范围值和查找到的值之间** 。即 **此次查找到的值的下标就是新的右范围值** 
- 如果查找到的值 **小于**待找到的值，也就表示 **待查找值** 在 **查找到的值和右范围值之间** 。即 **此次查找到的值的下标就是新的左范围值**
3.定义新的左值或者右值，再算出新的中间值之后，继续回到第二步，直到找到为止（通过left和right来判断是否没找到）。
当然，如果是倒着的数组要另说，方法同上
2024-07-11
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
        int mid = (left + right)/2; //计算范围内中间下标
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
例如：
##############
h############!
hel#########!!
.....
hello world!!!
char arr[] = "hello world!!!"
- 这个 **属于字符串** ，可以用到 **strlen** 来计算字符串的长度
- 当然也可以继续使用sizeof来计算字符串的长度，即 sz = sizeof(arr)/sizeof(arr[0])。但是计算出的长度不是字符串的长度，他需要减去1。因为 **字符串的结尾处有\0** 。会多计算一个字符。

他们的下标则是计算出的长度-1
- 使用strlen函数时，right的下标为 strlen（arr）-1
- 使用sizeof函数时，right的下标为 sizeof(arr)/sizeof(arr[0]) - 2
下面是实现的方法
```
#include <stdio.h>
 **#include <windows.h>//使用Sleep函数需要包含<windows>头文件，Sleep的单位为ms.** 
 **#include <string.h>  //使用strlen函数需要包含<string.h>头文件，用来计算字符串字符个数** 
 **#include <stdlib.h>  //使用system函数需要包含<stdlib.h>头文件，用来执行系统命令** 
int main()
{
    char arr1[] = "hello world!!!";
    char arr2[] = "##############";
    
    int left = 0;
    int right = strlen(arr1) - 1;

    while(left <= right)
    {
        arr1[left] = arr2[left];
        arr1[right] = arr2[right];//把#填充到原字符对应的地址中
        Sleep(1000)

        left++;
        right--; //缩小范围，继续填充
         **Sleep(1000);** //延迟1秒
         **system("cls");//system是一个库函数，可以执行系统命令,cls是请清屏指令**    //加上这两行可以在一行上显示出来这中向中间聚拢的效果
    }
        printf("%s",arr1); //清理后再打印出来
    return 0;
}
```

