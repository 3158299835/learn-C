# 学习C语言

#### 介绍
记录我学习C语言所研究的小项目

###printf打印小飞机
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
2024-07-09

###输入两个数，输出商和余数
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
