# 学习C语言

#### 介绍
记录我学习C语言所研究的小项目

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
