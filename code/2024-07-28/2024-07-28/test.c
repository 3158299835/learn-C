#define _CRT_SECURE_NO_WARNINGS

////ʹ�����������ж����С��
//
//#include <stdio.h>
//
//int check_sys()
//{
//	union  //��������Ҳ���ԣ������Ҿ���һ�� ��������
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//
//int main()
//{
//
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��");
//	}
//	else
//	{
//		printf("���");
//	}
//	return 0;
//}


////malloc��ʹ��
//
//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	//��̬�ڴ濪��
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//ʹ�ÿ��ٵ��ڴ�
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//ʹ����֮��û�л���û����free��
//	//�����ڳ���رյ�ʱ�򣬷���Ŀռ�Ҳ�ǻỹ��ȥ�ģ�
//	//������������һֱ�ߣ�����û�л��ռ䡣�������á�
//	//��ô����ռ� �ͽ����ڴ�����ˣ� ����Ҳ�ò��ˡ�	
//	//��C���Գ��ױʼ��У�����ôһ�仰
//	//�����������ɲ���ϵͳ����ģ�
//	// ��������ͷŲ����ɳ���Աͨ��������ʽ��ɣ�
//	// ͨ��ʹ��malloc()��calloc()�����ڴ棬ʹ��free()�ͷ��ڴ档
//	// ���ڴ��ַ�ɵ͵����������ʺϴ洢�����ݻ��������ڳ��Ķ���
//	// ����ע���ڴ�й©���⡣
//	//�ͷſռ���free(p);
//	free(p);//����p�ڴ�ĵ�ַ�ǲ����ġ�
//	p = NULL;//��p��ֵΪ��ָ�롣
//	return 0;
//}


////calloc��ʹ��
//#include<stdio.h>
//#include<stdlib.h>
//#include<errno.h>
//int main()
//{
//	//���ٿռ�
//	int* p = calloc(10, sizeof(int));//����10��int�͵Ŀռ�
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//��ӡ
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//��ӡ��0 0 0 0 0 0 0 0 0 0 
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}



////relloc��ʹ��
//#include<stdio.h>
//#include<stdlib.h>
//#include<errno.h>
//
//int main()
//{
//	int* p = (int*)malloc(40);//����40���ֽڴ�С�Ŀռ�
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	//��ֵ
//	//��ֵ40���ֽ�Ϊ1 2 3 4 5 6 7 8 9 10
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//����
//	int* ptr = (int*)realloc(p, 80);//��p��ָ��Ŀռ����Ϊ80���ֽ�
//	if (ptr != NULL)//����p�ĵ�ַ��Ϊ��
//	{
//		p = ptr;
//	}
//	//ʹ��
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p == NULL;
//	return 0;
//}



////��̬�ڴ�Ĵ���ʾ��
//1. ��NULL���н����ò���
//void test()
//{
//	int* p = (int*)ma110c(INT_MAX / 4);
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	free(p);
//}


////2. �Զ�̬���ٿռ��Խ�����
//int main()
//{
//int* p = (int*)malloc(40); 
//if (p == NULL)
//{
//	printf("%s\n", strerror(errno));
//	return 1;
//}
//	//��ʽ
//	int i =0;
//	for (i = 0; i <= 10; i++)
//	{
//		p[i] = i;
//	}
//	free(p);
//	p = NULL;
//return 0;
//}


////�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//int main()
//{
//	int a = 10;
//	int* p = &a; 
//	//....
//	free(p);
//	p = NULL; 
//	
//	return 0;
//}


////ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	//ʹ��
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p = i;
//		p++;
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//	return 0;
//}


////��ͬһ��Ķ�̬�ڴ����ͷ�
// ��ͬһ��Ķ�̬�ڴ����ͷ�
//�ͷ��ٴ��ͷžͻᱨ���������ͷſռ��Ӧ�ð�p��ֵΪ��ָ�룬 �����Ū�ɿ�ָ�룬p����Ұָ�룡
//int main()
//{
//	int* p = (int*)malloc(40);
//	//..
//	free(p);
//	//..
//	free(p);
//	return 0;
//}


//FILE
#include <stdio.h>
#include <errno.h> 

int main()
{
	//���ļ�
	FILE* pf = fopen("test.txt", "rb");
	// w д�ļ���û�򴴽������������еĶ���
	// r ���ļ���ֻ�Ƕ���
	// a ׷�ӡ�����׷��
	// wb �Ƕ�����д��
	// rb �Ƕ����ƶ�
	if (pf == NULL)//�����ʧ�ܻ᷵�ؿ�ָ�룬��ô���Ǿͱ���Ȼ��ֹͣ
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	////д�ļ���һ���ַ�
	//// fputc
	////��һ��������int���͵����롢�ڶ������ļ�ָ��
	////��Ϊ�ַ��ı�����ASCII��
	//int i = 0;
	//for (i = 'a'; i <= 'z'; i++)//����a...z
	//{
	//	fputc(i, pf);
	//}

	////���ļ���һ���ַ�
	//// fgetc
	////����Ϊ�ļ�ָ��
	////���ض�����ָ������Ϊint
	//int c = 0;
	//while ((c = fgetc(pf)) != EOF)//�Ҷ����Ķ���������EOF�����
	//{
	//	printf("%c ", c);
	//}
	//printf("%c\n",c);


	////дһ������
	//fputs("woaini,hahhaha\n", pf);
	//fputs("woaini,hahhaha\n", pf);


	////��ʽ���������
	//int a = 100;
	//char arr[10] = "nihaoa";
	//float b = 13.14f;
	//fprintf(pf,"%d %s %f", a, arr, b);


	////��ʽ�����뺯��
	//int a = 0;
	//char arr[10] = { 0 };
	//float b = 0.0f;
	//fscanf(pf, "%d %s %f", &a, arr, &b);
	//printf("%d %s %f\n", a, arr, b);


	struct S
	{
		int a;
		char arr[10];
		float b;
	};
	struct S s = { 100,"woaini",13.14f };

	////���������
	//fwrite(&s, sizeof(s), 1, pf);

	//����������
	fread(&s, sizeof(s), 1, pf);
	printf("%d %s %f\n", s.a, s.arr, s.b);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;//��ֹҰָ��

	return 0;
}

//�ر��ļ�


