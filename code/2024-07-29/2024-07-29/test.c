#define _CRT_SECURE_NO_WARNINGS




#include<stdio.h>

struct S
{
	int a;
	char arr[10];
	float b;
}s;

int main()
{

	struct S s = { 10,"nihao",13.14f };
	struct S tmp = { 0 };
	char buf[100] = { 0 };

	//sprintf��ʹ��
	//��s�и�ʽ��������ת�����ַ����ŵ�buf��
	sprintf(buf, "%d %s %f", s.a, s.arr, s.b);
	printf("%s\n", buf);
	//sprintf��ʹ��
	//���ַ���buf�л�ø�ʽ�������ݷŵ�tmp��
	sscanf(buf, "%d %s %f", &(tmp.a), tmp.arr, &(tmp.b));
	printf("%d %s %f", tmp.a, tmp.arr, tmp.b);
	return 0;
}	



