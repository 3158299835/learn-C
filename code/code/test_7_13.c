#define _CRT_SECURE_NO_WARNINGS
//测试把vs 项目推送到仓库

////---------------------------------------------------------------------------------
//#include <stdio.h>
//
////交换函数
//void swap(int* px, int* py)
//{
//    int temp = *px;
//    *px = *py;
//    *py = temp;
//}
//
////冒泡排序函数从小到大
//void bubble_sort_max(int arr[], int len)
//{
//    for (int i = 0; i < len - 1; i++)
//    {
//        for (int j = 0; j < len - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                swap(&arr[j], &arr[j + 1]);
//            }
//        }
//    }
//}
//
//int main()
//{
//    int arr[10];    //输入
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    int len = sizeof(arr) / sizeof(arr[0]);//求长度
//
//    bubble_sort_max(arr, len); //排序
//
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]); //输出
//    }
//
//        return 0;
//}
////---------------------------------------------------------------------------------




////---------------------------------------------------------------------------------

////打印1-100的3 的倍数的数字
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d \n", i);
//		}
//	}
//
//	return 0;
//}
////---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------

//求两个数的最大公约数
//
//
////暴力求解
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = (a < b) ? a : b;
//	while (min)
//	{
//		if (a % min == 0 && b % min == 0)
//		{
//			printf("%d", min);
//			break;
//		}
//		min--;
//	}
//	return 0;
//}
////--------------------------------------
//
//辗转相除法
//24%18 = 6
//18%6  = 0
//此时6为最大公约数
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	while (a % b)//%到0停止
//	{
//		int c = a % b;
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//
//	return 0;
//}
//---------------------------------------------------------------------------------

////---------------------------------------------------------------------------------
//
////输出0-114514数字中带有9的数字
////分析 
//// 个位 把数字%10就可以
//// 十位 除10再%10
//// 百位 除100...
////........
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for ( i = 1; i <= 114514; i++)
//	{
//		if (i % 10 == 9 || (i / 10) % 10 == 9 || (i / 100) % 10 == 9 || (i / 1000) % 10 == 9 || (i / 10000) % 10 == 9 || (i / 100000) % 10 == 9)
//		{
//			printf("%d \n", i);
//		}
//	}
//	return 0;
//}
//---------------------------------------------------------------------------------

////---------------------------------------------------------------------------------
//
////计算1/1 -1/2 +1/3 -1/4 +1/5 …+1/99-1/100  的值，打印出结果
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int flat = 1;
//	double num = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		num = num + flat * 1.0 / i;	//注意是1.0
//		flat = -flat;
//
//		printf("%d \t", flat);//观察flat的值
//		printf(" %lf\n", 1.0 / i);//观察当前加值
//
//
//	}
//	printf("%lf", num);//观察num的计算结果
//
//	return 0;
//}
//
////---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------

////打印99加法表
//
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d + %d = %2d    ", j, i, i + j); //-2d是左对齐
//		}
//		printf("\n");
//	}
//	return 0;
//
//}
//
////---------------------------------------------------------------------------------
//
////打印99乘法表
//
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %2d    ", j, i, i * j); //-2d是左对齐
//		}
//		printf("\n");
//	}
//	return 0;
//
//}
//
////---------------------------------------------------------------------------------


////再次理解下地址
//#include <stdio.h>
//
//int main()
//{	
//	int a = 10;
//	printf("%p\n", &a);
//	int* b = &a;
//	printf("%p\n", *b);
//	printf("%p\n", b);
//	*b = 3;
//	printf("%d\n", a);
//	return 0;
//
//}



//---------------------------------------------------------------------------------

//一维数组
//略掉

//二维数组的初始化
#include <stdio.h>

int main()
{	
//	行 列
	int arr[2][3] = { 1,2,3,4,5 };
	int arr[3][4] = { {1,2},{3,4},{5,6 } };

	return 0;

}

//---------------------------------------------------------------------------------
