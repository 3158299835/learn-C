#define _CRT_SECURE_NO_WARNINGS

//
//#include<stdio.h>
////先输入矩阵的列、在输入行、然后按照行再列的方式已打印
//int main()
//{
//	int arr[2][3] = {0};
//	int j = 0;
//	int i = 0;
//	for (j = 0; j < 3; j++)
//	{
//		 for (i = 0; i < 2; i++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	for (j = 0; j < 3; j++)
//	{
//		for (i = 0; i < 2; i++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//
//	}
//
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



////结构体吹传参的两种方法
//struct S
//{
//	int data[1000];
//	int num;
//};
////拷贝一遍变量
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
////传递地址
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->data[i]);
//	}
//	printf("%d\n", ps->num);
//}
//
//int main()
//{
//	struct S s = { {1,2,3}, 100 };
//	print1(s);  //传值调用
//	print2(&s); //传址调用
//
//	return 0;
//}







