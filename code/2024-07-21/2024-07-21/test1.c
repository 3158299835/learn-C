//#define _CRT_SECURE_NO_WARNINGS
//
//
//
////
////#include<stdio.h>
////#include<assert.h>
////int my_strlen(const char* str)//添加const 保证不修改
////{
////	int count = 0;
////	assert(str);//添加assert保证str不为空指针这里吧 != NULL省略了
////	while (*str != '\0')
////	{
////		count++;
////		str++;
////	}
////	return count;
////}
////
////int main()
////{
////	char arr[] = "hello world";
////	int len = my_strlen(arr);
////	printf("%d\n", len);
////	return 0;
////}
//
//
//
//////判断三角形
////#include<stdio.h>
////
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int c = 0;
////	while (scanf("%d %d %d", &a, &b, &c) == 3)
////	{
////		if (a + b > c && a + c > b && b + c > a)
////		{
////			if (a == b && b == c)
////			{
////				printf("这是等边三角形\n");
////			}
////			else if ((a == b && c != a)||(a == c && b != a)||(b == c && a != b))
////			{	
////				printf("这是等腰三角形\n");
////			}
////			else
////			{
////				printf("这是普通三角形\n");
////			}
////		}
////		else
////		{
////			printf("这不能组成三角形\n");
////
////		}
////	}
////	return 0;
////}
//
//
//////初阶测试
//////求最小公倍数、正整数A和正整数B
//////最小公倍数是指能被A和B整除的最小正整数的数值。
////
////#include<stdio.h>
////
////int min_gbs(int a, int b)
////{
////	int i = 1;
////	while (a * i % b)//等于0则能整除
////	{
////		i++;
////	}
////	return i;
////}
////
////int main()
////{
////	int a = 0;
////	int b = 0;
////	scanf("%d %d", &a, &b);
////	int i = min_gbs(a, b);
////	printf("%d", i * a);
////	return 0;
////}
//
//
//////初阶测试2
////倒置字符串但是遇到.就不倒置
////例如 i love beijing.  变为 beijing. love i
//
//
//#include <stdio.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)
//{
//    assert(left);
//    assert(right);
//
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//
//int main()
//{
//    char arr[101] = { 0 };
//    //输入
//    //逆置
//    int len = strlen(arr);
//    //1. 逆序整个字符串
//    reverse(arr, arr + len - 1);
//    //2. 逆序每个单词
//    char* start = arr;
//
//    while (*start)
//    {
//        char* end = start;
//        while (*end != ' ' && *end != '\0')
//        {
//            end++;
//        }
//        reverse(start, end - 1);
//        if (*end != '\0')
//            end++;
//        start = end;
//    }
//
//    //输出
//    printf("%s\n", arr);
//
//    return 0;
//}
