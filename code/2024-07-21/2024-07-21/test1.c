//#define _CRT_SECURE_NO_WARNINGS
//
//
//
////
////#include<stdio.h>
////#include<assert.h>
////int my_strlen(const char* str)//���const ��֤���޸�
////{
////	int count = 0;
////	assert(str);//���assert��֤str��Ϊ��ָ������� != NULLʡ����
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
//////�ж�������
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
////				printf("���ǵȱ�������\n");
////			}
////			else if ((a == b && c != a)||(a == c && b != a)||(b == c && a != b))
////			{	
////				printf("���ǵ���������\n");
////			}
////			else
////			{
////				printf("������ͨ������\n");
////			}
////		}
////		else
////		{
////			printf("�ⲻ�����������\n");
////
////		}
////	}
////	return 0;
////}
//
//
//////���ײ���
//////����С��������������A��������B
//////��С��������ָ�ܱ�A��B��������С����������ֵ��
////
////#include<stdio.h>
////
////int min_gbs(int a, int b)
////{
////	int i = 1;
////	while (a * i % b)//����0��������
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
//////���ײ���2
////�����ַ�����������.�Ͳ�����
////���� i love beijing.  ��Ϊ beijing. love i
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
//    //����
//    //����
//    int len = strlen(arr);
//    //1. ���������ַ���
//    reverse(arr, arr + len - 1);
//    //2. ����ÿ������
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
//    //���
//    printf("%s\n", arr);
//
//    return 0;
//}
