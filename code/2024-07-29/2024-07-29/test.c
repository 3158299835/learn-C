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

	//sprintf的使用
	//把s中格式化的数据转换成字符串放到buf中
	sprintf(buf, "%d %s %f", s.a, s.arr, s.b);
	printf("%s\n", buf);
	//sprintf的使用
	//从字符串buf中获得格式化的数据放到tmp中
	sscanf(buf, "%d %s %f", &(tmp.a), tmp.arr, &(tmp.b));
	printf("%d %s %f", tmp.a, tmp.arr, tmp.b);
	return 0;
}	



