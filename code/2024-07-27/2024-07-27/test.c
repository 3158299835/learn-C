#define _CRT_SECURE_NO_WARNINGS

//
//#include<stdio.h>
////�����������С��������С�Ȼ���������еķ�ʽ�Ѵ�ӡ
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



////�ṹ�崵���ε����ַ���
//struct S
//{
//	int data[1000];
//	int num;
//};
////����һ�����
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
////���ݵ�ַ
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
//	print1(s);  //��ֵ����
//	print2(&s); //��ַ����
//
//	return 0;
//}







