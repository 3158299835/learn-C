#define _CRT_SECURE_NO_WARNINGS
//
//#include
//
//int main()
//{
//	{
//		int arr[10] = { 0 };
//		int* p = arr;//arr[0]
//		int i = 0;
//		for (i = 0; i <= 10; i++)
//		{
//			*p = i;
//			p++;
//		}
//		//��p = 10 ��һ��*p = iʱ��p����Ұָ���ˡ�
//		//���ķ��ʳ���������ķ�Χ
//
//		return 0;
//	}
//
//#include <stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int* p = test();
//	return 0;
//}
//�������ʾ�У�p�ڽ���a�ĵ�ַ��
// ��Ϊa�Ǿֲ��������ں���������ͱ��ͷ��ˡ�
// ���������������a�ĵ�ַȥ�ҵ���Ƭ����ʱ�������ܷ��ʡ�
// ��ôp����Ұָ���ˡ�
	//�����ʱ��ӡ*p��ָ��Ŀռ䣬�����Ȼ����һ���ֲ�������ֵ��Ҳ����10
	//��Ϊ����ľֲ�������Ȼ�Ѿ������٣���������������Ȼ���ڡ�ֻ�ǵȴ��´α�����
	//�����ӡһ�±�Ķ�������ϵͳ���õ���Ƭ�ռ�����ڲ��洢��ֵ�������ı�
	//���Դ�ӡ��Ҳ�Ͳ���10��


//#include <stdio.h> 
//
////��һ��ָ���㲻֪����ʼ��ʲôֵ��ʱ��
//// �Ͱ�����ֵΪ��ָ��NULL
//int* p = NULL;
////���´�ʹ�õ�ʱ��Ϊ�˱�����������������д
//if (p != NULL)
//{
//	*p = 100;//�����Ϊ��ָ��Ͷ�����ָ��Ķ�����и�ֵ
//	//����Կ�ָ�븳ֵ������򱨴�
//}
//
// 
// 
////ָ��ļӼ�����
//#include <stdio.h>
//#define N_VALUES 5
//int main()
//{
//	float valueS[N_VALUES]; float* vp;
//	//ָ��+-����;ָ��Ĺ�ϵ����
//	for (vp = &valueS[0]; vp < &valueS[N_VALUES];)
//	{
//		*vp++ = 0;
//	}
//}
////���ʾ�������С�
////`*vp++ = 0; ` Ϊ��ʹ�ú�++���Ե�0 1 2 3 4 ��ָ�붼�ᱻ��ֵΪ0
////�����++ָ���ǵ�ַ++
////���������forѭ���ڼ��vp�ڴ洢�ĵ�ַ�Ƿ�С��&valueS[N_VALUES]ʱ��
////��Ȼ����һ������֮�����ֵ������ʵ�ʲ�û�в������û��Ȩ�޵Ŀռ䣬
//// ����Ҳ����Ұָ��

//

//
////ָ���ָ��
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p1 = &arr[0];
//	int* p2 = &arr[9];
//	int a = p2 - p1;
//	printf("%d", a);
//	return 0;
//}

////ָ��-ָ��ʵ���ַ����󳤶�
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return(str - start);
//}

////ָ�������
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p------%p\n", &arr[i], p + i);
//	}
//	//˵��&arr[i], p + i �ȼ�
//
//	return 0;
//}

////����ָ��
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa��һ��ָ�����
//	
//	int** ppa = &pa;//ppa��ָ���ָ�룬�Ƕ���ָ�����
//	//��������ߵ� *��˵����ppa��ָ��
//	//int* ˵��ppa��ָ��Ķ�����int*����
//	**ppa = 20;//�����ͽ����õ���a
//
//	return 0;
//}

////ָ������
////���ָ�������
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* parr[10] = {&a, &b, &c};
//	
//	//��ӡָ�������е�ָ��
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", * (parr[i]));
//	}
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int arr1[4] = { 1,2,3,4 }; 
//	int arr2[4] = { 2,3,4,5 }; 
//	int arr3[4] = { 3,4,5,6 };
//	int* parr[3] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ",parr[i][j]);
//			//�����parr[i]����Ҫ�����á�
//			//parr[0]ָ����ָ������д洢�ĵ�һ��Ԫ�صĵ�ַ��
//			//Ҳ����arr1���׵�ַ����arr1�ĵ�ַ��ͬ��arr1��
//			//����parr[0]�͵�ͬ��arr1
//			//���Ϻ����[j] ���Ƿ���arr1���±�Ϊj��Ԫ�ء���ͬ��arr1[j]
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//struct Peo //�����ṹ��  ��ʱֻ��һ��ģ�壬��û���ڴ�ռ�
//{
//	char name[20];
//	char tele[12];
//	char sex[5];//Ů�� ����
//	int high;
//};
//struct St//�ṹ���п�������һ���ṹ�����������ṹ���������ϸ��ṹ��
//{
//	struct peo p;
//	int num;
//	float f;
//};

//дһ�����������ز����ж���������1�ĸ�����һ������Ľⷨ
//#include <stdio.h>
//int count_num_of_1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & n - 1;
//		count++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	
//	printf("%d", count_num_of_1(n));
//	return 0;
//}



///дһ�������������������֡�������ǵĶ��������м�λ��ͬ
//д��1   ��λ�Ƚ�
#include<stdio.h>

//int	count_diff_bit(int a, int b)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((a >> i) & 1) != ((b >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = count_diff_bit(a, b);
//	printf("%d", c);
//	return 0;
//}

////д��2  ��������   ��ͬΪ0 ����Ϊ1
////
//int	count_diff_bit(int a, int b)
//{
//	int n = a ^ b;//������ٸ�λ��һ�����ڶ�������Ϊ1��
//	//�ҳ�1�ĸ���
//	int count = 0;
//	while (n)
//	{
//		n = n & n - 1;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = count_diff_bit(a, b);
//	printf("%d", c);
//	return 0;
//}

////��ӡһ�������еĶ����������е�����λ��ż��λ
////ż��λ��0��ʼ 
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//
//	//��ӡż��λ���������Ҵ�ӡ��
//	//�������Ҫ����ֱ���ƶ�31λ����
//	int i = 0;
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//
//	return	0;
//}

////���x�������n��������任
//#include <stdio.h>
//int main()
//{
//	int n = 0; 
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0; int j = 0; 
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//				{
//					printf("*");
//				}
//				else if (i + j == n - 1)//�����ϵ�����
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


////������ݡ��·��������µ�����
//int is_leap_year(int y)
//{
//	return(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
//}
//
//int main()
//{
//	int y = 0; 
//	int m = 0; 
//	int d = 0;
//	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (scanf("%d %d", &y, &m) == 2)//��ȷ���������򷵻�2
//	{
//		int d = days[m];
//		if ((is_leap_year(y) == 1) && (m == 2))
//		{
//			d++;
//		}
//		printf("%d\n", d);
//	}
//}