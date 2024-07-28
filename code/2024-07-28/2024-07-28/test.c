#define _CRT_SECURE_NO_WARNINGS

////使用联合体来判断你大小端
//
//#include <stdio.h>
//
//int check_sys()
//{
//	union  //匿名类型也可以，反正我就用一次 不用命名
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
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}


////malloc的使用
//
//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	//动态内存开辟
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//使用开辟的内存
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//使用完之后没有还，没有用free。
//	//但是在程序关闭的时候，分配的空间也是会还回去的，
//	//但倘若程序在一直走，并且没有还空间。他还不用。
//	//那么这个空间 就叫做内存溢出了， 别人也用不了。	
//	//在C语言初阶笔记中，有这么一句话
//	//堆区：它是由操作系统管理的，
//	// 但分配和释放操作由程序员通过代码显式完成，
//	// 通常使用malloc()、calloc()分配内存，使用free()释放内存。
//	// 堆内存地址由低到高增长，适合存储大数据或生命周期长的对象，
//	// 但需注意内存泄漏问题。
//	//释放空间用free(p);
//	free(p);//但是p内存的地址是不会变的。
//	p = NULL;//把p赋值为空指针。
//	return 0;
//}


////calloc的使用
//#include<stdio.h>
//#include<stdlib.h>
//#include<errno.h>
//int main()
//{
//	//开辟空间
//	int* p = calloc(10, sizeof(int));//开辟10个int型的空间
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//打印
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//打印出0 0 0 0 0 0 0 0 0 0 
//	}
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}



////relloc的使用
//#include<stdio.h>
//#include<stdlib.h>
//#include<errno.h>
//
//int main()
//{
//	int* p = (int*)malloc(40);//申请40个字节大小的空间
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	//赋值
//	//赋值40个字节为1 2 3 4 5 6 7 8 9 10
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//扩容
//	int* ptr = (int*)realloc(p, 80);//把p所指向的空间调整为80个字节
//	if (ptr != NULL)//保护p的地址不为空
//	{
//		p = ptr;
//	}
//	//使用
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p == NULL;
//	return 0;
//}



////动态内存的错误示范
//1. 对NULL进行解引用操作
//void test()
//{
//	int* p = (int*)ma110c(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}


////2. 对动态开辟空间的越界访问
//int main()
//{
//int* p = (int*)malloc(40); 
//if (p == NULL)
//{
//	printf("%s\n", strerror(errno));
//	return 1;
//}
//	//方式
//	int i =0;
//	for (i = 0; i <= 10; i++)
//	{
//		p[i] = i;
//	}
//	free(p);
//	p = NULL;
//return 0;
//}


////对非动态开辟内存使用free释放
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


////使用free释放一块动态开辟内存的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p = i;
//		p++;
//	}
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}


////对同一块的动态内存多次释放
// 对同一块的动态内存多次释放
//释放再次释放就会报错！所以在释放空间后，应该把p赋值为空指针， 如果不弄成空指针，p就是野指针！
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
	//打开文件
	FILE* pf = fopen("test.txt", "rb");
	// w 写文件。没则创建、会销毁已有的东西
	// r 读文件。只是读。
	// a 追加。往后追加
	// wb 是二进制写入
	// rb 是二进制读
	if (pf == NULL)//如果打开失败会返回空指针，那么我们就报错然后停止
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	////写文件的一个字符
	//// fputc
	////第一个参数是int类型的输入、第二个是文件指针
	////因为字符的本质是ASCII码
	//int i = 0;
	//for (i = 'a'; i <= 'z'; i++)//输入a...z
	//{
	//	fputc(i, pf);
	//}

	////读文件的一个字符
	//// fgetc
	////参数为文件指针
	////返回读到的指针类型为int
	//int c = 0;
	//while ((c = fgetc(pf)) != EOF)//我读到的东西不等于EOF则继续
	//{
	//	printf("%c ", c);
	//}
	//printf("%c\n",c);


	////写一行数据
	//fputs("woaini,hahhaha\n", pf);
	//fputs("woaini,hahhaha\n", pf);


	////格式化输出函数
	//int a = 100;
	//char arr[10] = "nihaoa";
	//float b = 13.14f;
	//fprintf(pf,"%d %s %f", a, arr, b);


	////格式化输入函数
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

	////二进制输出
	//fwrite(&s, sizeof(s), 1, pf);

	//二进制输入
	fread(&s, sizeof(s), 1, pf);
	printf("%d %s %f\n", s.a, s.arr, s.b);
	//关闭文件
	fclose(pf);
	pf = NULL;//防止野指针

	return 0;
}

//关闭文件


