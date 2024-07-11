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
### 计算求得体积
 **输入：**一个浮点值0-15
 **输出：**球的体积，小数点保留三位
这个题考察的是float和double的区别
float占4字节， double占8字节，所以double的精度会更高
float在初始化的时候是float = 0.0f：
double在初始化的时候是float = 0.0lf;或者 0.0   因为0.0默认使用的是double
代码如下：
···
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
···