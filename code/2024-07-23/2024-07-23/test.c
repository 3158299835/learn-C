#define _CRT_SECURE_NO_WARNINGS


////�ص�����
////���ú���ָ���ں����ڲ����ú���
////ʵ��һ�� + - * /������
//#include <stdio.h>
//
//void menu()
//{
//	printf("*************************************\n");
//	printf("********   1. add   2. sub   ********\n");
//	printf("********   3. mul   4. div   ********\n");
//	printf("*******    0. exit           ********\n");
//	printf("*************************************\n");
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void compute(int(*pf)(int, int))
////����compute�������������Ϊ int���͵ĺ���ָ�롢
//// ��ָ��ĺ������������Ϊint  int
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("���������>:");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//}
//
//
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("�����빦��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			compute(add);
//			break;
//		case 2:
//			compute(sub);
//			break;
//		case 3:
//			compute(mul);
//			break;
//		case 4:
//			compute(div);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("�����������������\n");
//			break;
//		}
//
//	} while (input);
//	
//
//	return 0;
//}

////���ú���ָ����������дһ��
// ///ת�Ʊ�
//#include <stdio.h>
//
//void menu()
//{
//	printf("*************************************\n");
//	printf("********   1. add   2. sub   ********\n");
//	printf("********   3. mul   4. div   ********\n");
//	printf("*******    0. exit           ********\n");
//	printf("*************************************\n");
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*pfArr[5])(int, int) = { 0, add,sub,mul,div };//��0��Ϊ������1Ϊadd
//	do
//	{
//		menu();
//		printf("�����빦��:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�������\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("������Ϊ:%d\n", ret);
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//
//	return 0;
//}

////����qsort��ʵ��int���������/��������
//
//
//#include<stdio.h>
//
////void qsort(void* base,//Ҫ��������ݵ���ʼλ��
////	size_t num,//�������Ԫ�ظ���
////	size_t width,//�������Ԫ�ش�С����λΪ�ֽڣ�
////	int(*cmp)(const void* e1, const void* e2)//����ָ��-�ȽϺ���
////	//���������Ҫ�Լ�д�����ش���0  ����0    С��0������
////);
//
//
//void cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e2 - *(int*)e1);//��ʱ�ǽ��򣬸���e1 ��e2 �Ϳ���ʵ������
//}
//// voidָ��ʽ������ָ�룬�����Խ����������͵�����
//// �������޷����н����ú� +  - �Ĳ����� ��ʹ��֮ǰ��Ҫ����ǿ������ת��
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]); 
//	int i = 0;
//
//	//����
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



////�Լ�дһ��qsort��Ȼ���жϡ�
//#include <stdlib.h>
//
////�Ƚ����ε�
//int cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//void test1()
//{
//	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	//0 1 2 3 4 5 6 7 8 9
//	//�������ų�����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
////����һ���ṹ��
//struct Stu
//{
//	char name[20];
//	int age;
//};
////��������Ԫ�صķ���
////char��Ϊ���ܹ�������ͬ��Ԫ�أ�����int��char��short�ȡ�
////���ݺ��������Ĳ����������ֽڡ�
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//
////�����Լ��ıȽϺ���������������ʼλ�á�Ԫ�س��ȡ��ֽڳ��ȡ��ȽϺ���
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	//����
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//�����������ź���
//		//һ��ð������Ĺ���
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//�����cmp����Ҫ�����д�ġ�
//			//��Ϊ����֪��ʹ����������������ж�float����iint�����Ǳ��
//			//���жԱȵ�ʱ�򡣴��͹�ȥ�Ķ���char���͵ĵ�ַ�����ǵĲ�����width�������������ֽ��ٴ��͵�ַ��
//			//�������Ǳ�д�ĶԱȺ����жԱ�֮���ٷ���ֵ�����ж�Ȼ�󽻻�
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//����
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				flag = 0;//���һ�˷���û��һ�η�����������ô���˳�����
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
////abbdef
////abbqwerttt
////ʹ��strcmp�Ա��ַ���ʱ���ǰ�λ�Աȡ�a=a��b=b ..d<q ��������Ĵ�
////Ҳ����˵������������ʱ��a��ͷ����ĸ������ǰ��z����� ��ͬ��Ƚ���һ����ĸ
////ע���ڶ����ʱ��ʵ�õ���const void*
////��Ϊvoid*���Խ����κ����͵�ָ�룬��ʹ�õ�ʱ��ֻ��Ҫ��������ת���Ϳ����ˡ�
////�ṹ��Ƚ��ַ�����С
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	//strcmp --> >0 ==0 <0
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
////�ڽ��нṹ��Ԫ�رȽϵ�ʱ����Ϊ�����ǵ�ַ���������ü�ͷ����������Ԫ�ء�
//
////�ṹ��Ƚ������С
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
////����ʹ��qsort������ṹ����
//void test2()
//{
//	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);//�����Լ�д�ıȽ�age��С�ĺ���
//}
////ʹ���Լ�д��ð����������int�������Ԫ������
//void test3()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	//���
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
////����ʹ���Լ�д��������������ṹ�����е��ַ���
//void test4()
//{
//
//	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//}
//
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	return 0;
//}



//
//�����������
//ָ��������ָ�����͵�����
//
//
//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//
//
//	printf("%d\n", sizeof(a));//16
//	//sizeof(������)����������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//	printf("%d\n", sizeof(a + 0));//4
//	//a���ǵ�������sizeof�ڲ���Ҳû��ȡ��ַ������a������Ԫ�صĵ�ַ��a+0������Ԫ�صĵ�ַ
//	//�ǵ�ַ����С����4/8���ֽ�
//	printf("%d\n", sizeof(*a));//4
//	//*a�е�a��������Ԫ�صĵ�ַ��*a���Ƕ���Ԫ�صĵ�ַ�����ã��ҵ��ľ�����Ԫ��
//	//��Ԫ�صĴ�С����4���ֽ�
//	printf("%d\n", sizeof(a + 1));
//	//�����a��������Ԫ�صĵ�ַ
//	//a+1�ǵڶ���Ԫ�صĵ�ַ
//	//sizeof(a+1)���ǵ�ַ�Ĵ�С
//	printf("%d\n", sizeof(a[1]));//4
//	//������ǵڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&a));//4/8
//	//&aȡ��������ĵ�ַ������ĵ�ַ��Ҳ���Ǹ���ַ
//	printf("%d\n", sizeof(*&a));//16
//	//&a----> int(*)[4]
//	//&a�õ������������ĵ�ַ�������� int(*)[4],��һ������ָ��
//	//����ָ��������ҵ���������
//	//*&a ---> a
//	//
//	//2.
//	//&��*������
//	//*&a ---> a
//	//
// //printf("%d\n", sizeof(&a + 1));//4/8
//	//&aȡ����������ĵ�ַ
//	//&a-->  int(*)[4]
//	//&a+1 �Ǵ�����a�ĵ�ַ���������һ����4������Ԫ�صģ�����Ĵ�С
//	//&a+1���ǵ�ַ���ǵ�ַ����4/8�ֽ�
//	//
//	printf("%d\n", sizeof(&a[0]));//4/8
//	//&a[0]���ǵ�һ��Ԫ�صĵ�ַ
//	//������ǵ�ַ�Ĵ�С
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	//&a[0]+1�ǵڶ���Ԫ�صĵ�ַ
//	//��С��4/8���ֽ�
//	//&a[0]+1 ---> &a[1]
//	//
//	return 0;
//}
//
//
//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));//6
//	//sizeof(������)
//	printf("%d\n", sizeof(arr + 0));//4/8
//	//arr + 0 ��������Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*arr));//1
//	//*arr�����������Ԫ�أ���С��1�ֽ�
//	//*arr --> arr[0]
//	//*(arr+0) --> arr[0]
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4/8
//	//&arr������ĵ�ַ���ǵ�ַ����4/8���ֽ�
//	printf("%d\n", sizeof(&arr + 1));//4/8
//	//&arr + 1�������ĵ�ַ
//	//
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8
//	//&arr[0] + 1�ǵڶ���Ԫ�صĵ�ַ
//	//
//	return 0;
//}
//
//
//
//
//
//#include <string.h>
//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//
//	printf("%d\n", strlen(arr));//���ֵ  û\0
//	printf("%d\n", strlen(arr + 0));//���ֵ
//
////	printf("%d\n", strlen(*arr));//--> strlen('a');-->strlen(97);//Ұָ��
////	printf("%d\n", strlen(arr[1]));//-->strlen('b')-->strlen(98);
//
//	printf("%d\n", strlen(&arr));//���ֵ
//	printf("%d\n", strlen(&arr + 1));//���ֵ-6
//	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1
//
//	return 0;
//}
//
//
//
//
//int main()
//{
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//
//	char arr[] = "abcdef";
//	//strlen�����ַ������ȵģ���ע�����ַ����е�\0���������\0֮ǰ���ֵ��ַ��ĸ���
//	//strlen�ǿ⺯����ֻ����ַ���
//	//sizeofֻ��עռ���ڴ�ռ�Ĵ�С�����ں��ڴ��зŵ���ʲô
//	//sizeof�ǲ�����
//	//
//	//[a b c d e f \0]
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//5
//
//
//	//[a b c d e f \0]
//	//printf("%d\n", sizeof(arr));//7
//	//printf("%d\n", sizeof(arr + 0));//4/8
//	//printf("%d\n", sizeof(*arr));//1
//	//printf("%d\n", sizeof(arr[1]));//1
//	//printf("%d\n", sizeof(&arr));//4/8
//	//printf("%d\n", sizeof(&arr + 1));//4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//4/8
//
//	return 0;
//}
//
//
//
//
//	char arr[] = "abcdef";
//	//strlen�����ַ������ȵģ���ע�����ַ����е�\0���������\0֮ǰ���ֵ��ַ��ĸ���
//	//strlen�ǿ⺯����ֻ����ַ���
//	//sizeofֻ��עռ���ڴ�ռ�Ĵ�С�����ں��ڴ��зŵ���ʲô
//	//sizeof�ǲ�����
//	//
//	//[a b c d e f \0]
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//5
//
//
//
//
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(p + 1));
//	printf("%d\n", sizeof(*p));
//	printf("%d\n", sizeof(p[0]));
//	printf("%d\n", sizeof(&p));
//	printf("%d\n", sizeof(&p + 1));
//	printf("%d\n", sizeof(&p[0] + 1));
//
//	printf("%d\n", strlen(p));
//	printf("%d\n", strlen(p + 1));
//	printf("%d\n", strlen(*p));
//	printf("%d\n", strlen(p[0]));
//	printf("%d\n", strlen(&p));
//	printf("%d\n", strlen(&p + 1));
//	printf("%d\n", strlen(&p[0] + 1));
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));
//	a[0]�ǵ�һ�����һά���������������������sizeof�ڲ���a[0]��ʾ��һ���������һά����
//	sizeof(a[0])����ľ��ǵ�һ�еĴ�С
//	printf("%d\n", sizeof(a[0] + 1));
//	a[0]��û�е�������sizeof�ڲ���Ҳûȡ��ַ��a[0]�ͱ�ʾ��Ԫ�صĵ�ַ
//	���ǵ�һ�����һά����ĵ�һ��Ԫ�صĵ�ַ��a[0] + 1���ǵ�һ�еڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*(a[0] + 1)));
//	a[0] + 1���ǵ�һ�еڶ���Ԫ�صĵ�ַ
//	*(a[0] + 1))���ǵ�һ�еڶ���Ԫ��
//	printf("%d\n", sizeof(a + 1));//4/8
//	a��Ȼ�Ƕ�ά����ĵ�ַ�����ǲ�û�е�������sizeof�ڲ���Ҳûȡ��ַ
//	a��ʾ��Ԫ�صĵ�ַ����ά�������Ԫ�������ĵ�һ�У�a���ǵ�һ�еĵ�ַ
//	a+1����������һ�У���ʾ�ڶ��еĵ�ַ
//	printf("%d\n", sizeof(*(a + 1)));//16
//	*(a + 1)�ǶԵڶ��е�ַ�Ľ����ã��õ����ǵڶ���
//	*(a+1)-->a[1]
//	sizeof(*(a+1))-->sizeof(a[1])
//	
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	&a[0] - �Ե�һ�е�������ȡ��ַ���ó����ǵ�һ�еĵ�ַ
//	&a[0]+1 - �õ����ǵڶ��еĵ�ַ
//	
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	a��ʾ��Ԫ�صĵ�ַ�����ǵ�һ�еĵ�ַ
//	*a���ǶԵ�һ�е�ַ�Ľ����ã��õ��ľ��ǵ�һ��
//	
//	printf("%d\n", sizeof(a[3]));//16
//	ֻ��ע���ͣ�����עֵ 
//	printf("%d\n", sizeof(a[0]));//16
//
//	int a = 10;
//	sizeof(int);
//	sizeof(a);
//
//
//	return 0;
//}



//
//#include <stdio.h>
//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 }; 
//	int* ptr = (int*)(&a + 1);
//	//ȡ��ַa������a�ĵ�ַ  +1  �� ���������һ��Ԫ�صĵ�ַ��+1
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//a+1  a����Ԫ�صĵ�ַ��+1�ǵڶ���Ԫ�صĵ�ַ���ٽ����þ��� 2     
//	//ptr -1 ������ָ��-1 Ҳ����  a�ĵ�ַ  �������Ϊ  2   5 
//	return 0;
//}
//
//
//
//
//
//
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p = (struct Test*)0x100000;   //�ѵ�ֵַǿ������ת��Ϊstruct
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
////��֪���ṹ��Test���͵ı�����С��20���ֽ�
////x86
//int main()
//{
//	printf("%p\n", p + 0x1);//����һ���ṹ�� 20���ֽ�
//	//0x100000+20-->0x100014
//	printf("%p\n", (unsigned long)p + 0x1);
//	//100000ת��Ϊ����λ1048576
//	//1,048,576+1 --> 1,048,577
//	//0x100001 
//	printf("%p\n", (unsigned int*)p + 0x1);//�����ĸ��ֽڡ� int��
//	//0x100000+4-->0x100004
//	return 0;
//}
//
//
//
//
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	//�������һ��Ԫ�صĵ�ַ+1��+4�ֽڣ�
//	int* ptr2 = (int*)((int)a + 1);
//	//aת��Ϊint���ͺ�+1  ֻ��+1 ����+���ֽ�
//	//Ȼ��ת��Ϊint* �ĵ�ַ��  �൱�� a�����һ��Ԫ�صĵ�ַ + һ���ֽڡ�
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}
//
//
//
//
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	//�����ű��ʽ�� �����Ч��(1, 3, 5);
//	int* p;
//	p = a[0];//�����ǵ�һ�еĵ�ַ������һ��Ԫ�صĵ�ַ  Ҳ���� 1
//	printf("%d", p[0]);
//	return 0;
//}
//
//
//
//
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	//int (*p)[4] ������ָ������������������
//	p = a;
//	//a����������������֣�������=��Ԫ�ص�ַ��=��һ�еĵ�ַ��
//	// ����������int (*) [5]
//	//��int(*p)[4]��ָ��������int (*) [4]
//	//��������ָ��p�ڴ�a����Ԫ�ص�ַ��ʱ���Ǿ�������������ĸ��ֽ�Ϊһ��ȥ���
//	//����˵�����ǣ������ʱ��p+1  ���Ĳ�����4���ֽڡ�
//
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//	&p [4][2] ����˼�Ƕ�ȡ��p�Ƕȵĵ����ŵڶ������֡�
//	// ��ʱpָ�����a����Ԫ�صĵ�ַ 0 ����ô[4][2] ������־�Ҫ����+4*4+2=18
//	//	Ҳ����&p [4][2] ȡ��������a�ĵ� 18 / 5 = 3 ...3 ��4�е�4��
//	// �� &a[4][2] �ǵ�5�е�3���� �м����4���ֽڡ�
//
//	//��ô��ַ���֮����� -4   ��%d��ӡ����-4
//	//������%p��ӡ��ַ������Ҫ��ӡ-4�Ĳ����16������
//	//-4��ԭ���� 10000000 00000000 00000000 00000100
//	//������     11111111 11111111 11111111 11111011
//	//������     11111111 11111111 11111111 11111100
//	//16������   F   F    F   F    F   F    F   C
//	
//	return 0;
//}