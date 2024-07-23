#define _CRT_SECURE_NO_WARNINGS


////回调函数
////利用函数指针在函数内部引用函数
////实现一个 + - * /计算器
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
////定义compute函数的输入参数为 int类型的函数指针、
//// 且指向的函数的输入参数为int  int
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("输入操作数>:");
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
//		printf("请输入功能:>");
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
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//
//	} while (input);
//	
//
//	return 0;
//}

////利用函数指针数组来改写一下
// ///转移表
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
//	int (*pfArr[5])(int, int) = { 0, add,sub,mul,div };//补0是为了输入1为add
//	do
//	{
//		menu();
//		printf("请输入功能:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("计算结果为:%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}

////利用qsort来实现int数组的升序/降序排列
//
//
//#include<stdio.h>
//
////void qsort(void* base,//要排序的数据的起始位置
////	size_t num,//待排序的元素个数
////	size_t width,//待排序的元素大小（单位为字节）
////	int(*cmp)(const void* e1, const void* e2)//函数指针-比较函数
////	//这个函数需要自己写，返回大于0  等于0    小于0的数字
////);
//
//
//void cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e2 - *(int*)e1);//此时是降序，更改e1 和e2 就可以实现升序
//}
//// void指针式无类型指针，它可以接受任意类型的数据
//// 但是它无法进行解引用和 +  - 的操作。 在使用之前需要进行强制类型转换
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]); 
//	int i = 0;
//
//	//排序
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



////自己写一个qsort。然后判断。
//#include <stdlib.h>
//
////比较整形的
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
//	//把数组排成升序
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
////定义一个结构体
//struct Stu
//{
//	char name[20];
//	int age;
//};
////交换两个元素的方法
////char是为了能够交换不同的元素，比如int、char、short等、
////根据函数传来的步长来交换字节。
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
////定义自己的比较函数，。。输入起始位置、元素长度、字节长度、比较函数
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//假设数组是排好序
//		//一趟冒泡排序的过程
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//这里的cmp是需要另外编写的。
//			//因为并不知道使用这个函数的人是判断float还是iint或者是别的
//			//进行对比的时候。传送过去的都是char类型的地址。他们的步长有width决定跳过几个字节再传送地址。
//			//会在我们编写的对比函数中对比之后再返回值进行判断然后交换
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				flag = 0;//如果一趟发现没有一次发生交换。那么就退出排序
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
////使用strcmp对比字符串时。是按位对比。a=a、b=b ..d<q 所以下面的大
////也就是说，在升序排列时，a开头的字母会在最前。z在最后 相同则比较下一个字母
////注意在定义的时候，实用的是const void*
////因为void*可以接受任何类型的指针，在使用的时候只需要进行类型转换就可以了。
////结构体比较字符串大小
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	//strcmp --> >0 ==0 <0
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
////在进行结构体元素比较的时候，因为传的是地址，。所以用箭头符号来引出元素。
//
////结构体比较年龄大小
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
////测试使用qsort来排序结构数据
//void test2()
//{
//	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);//传入自己写的比较age大小的函数
//}
////使用自己写的冒泡排序来对int型数组的元素排序
//void test3()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	//输出
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
////测试使用自己写的排序函数来排序结构数据中的字符串
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
//数组名的理解
//指针的运算和指针类型的意义
//
//
//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//
//
//	printf("%d\n", sizeof(a));//16
//	//sizeof(数组名)，数组名表示整个数组，计算的是整个数组的大小，单位是字节
//	printf("%d\n", sizeof(a + 0));//4
//	//a不是单独放在sizeof内部，也没有取地址，所以a就是首元素的地址，a+0还是首元素的地址
//	//是地址，大小就是4/8个字节
//	printf("%d\n", sizeof(*a));//4
//	//*a中的a是数组首元素的地址，*a就是对首元素的地址解引用，找到的就是首元素
//	//首元素的大小就是4个字节
//	printf("%d\n", sizeof(a + 1));
//	//这里的a是数组首元素的地址
//	//a+1是第二个元素的地址
//	//sizeof(a+1)就是地址的大小
//	printf("%d\n", sizeof(a[1]));//4
//	//计算的是第二个元素的大小
//	printf("%d\n", sizeof(&a));//4/8
//	//&a取出的数组的地址，数组的地址，也就是个地址
//	printf("%d\n", sizeof(*&a));//16
//	//&a----> int(*)[4]
//	//&a拿到的是数组名的地址，类型是 int(*)[4],是一种数组指针
//	//数组指针解引用找到的是数组
//	//*&a ---> a
//	//
//	//2.
//	//&和*抵消了
//	//*&a ---> a
//	//
// //printf("%d\n", sizeof(&a + 1));//4/8
//	//&a取出的是数组的地址
//	//&a-->  int(*)[4]
//	//&a+1 是从数组a的地址向后跳过了一个（4个整型元素的）数组的大小
//	//&a+1还是地址，是地址就是4/8字节
//	//
//	printf("%d\n", sizeof(&a[0]));//4/8
//	//&a[0]就是第一个元素的地址
//	//计算的是地址的大小
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	//&a[0]+1是第二个元素的地址
//	//大小是4/8个字节
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
//	//sizeof(数组名)
//	printf("%d\n", sizeof(arr + 0));//4/8
//	//arr + 0 是数组首元素的地址
//	printf("%d\n", sizeof(*arr));//1
//	//*arr就是数组的首元素，大小是1字节
//	//*arr --> arr[0]
//	//*(arr+0) --> arr[0]
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4/8
//	//&arr是数组的地址，是地址就是4/8个字节
//	printf("%d\n", sizeof(&arr + 1));//4/8
//	//&arr + 1是数组后的地址
//	//
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8
//	//&arr[0] + 1是第二个元素的地址
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
//	printf("%d\n", strlen(arr));//随机值  没\0
//	printf("%d\n", strlen(arr + 0));//随机值
//
////	printf("%d\n", strlen(*arr));//--> strlen('a');-->strlen(97);//野指针
////	printf("%d\n", strlen(arr[1]));//-->strlen('b')-->strlen(98);
//
//	printf("%d\n", strlen(&arr));//随机值
//	printf("%d\n", strlen(&arr + 1));//随机值-6
//	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
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
//	//strlen是求字符串长度的，关注的是字符串中的\0，计算的是\0之前出现的字符的个数
//	//strlen是库函数，只针对字符串
//	//sizeof只关注占用内存空间的大小，不在乎内存中放的是什么
//	//sizeof是操作符
//	//
//	//[a b c d e f \0]
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//随机值
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
//	//strlen是求字符串长度的，关注的是字符串中的\0，计算的是\0之前出现的字符的个数
//	//strlen是库函数，只针对字符串
//	//sizeof只关注占用内存空间的大小，不在乎内存中放的是什么
//	//sizeof是操作符
//	//
//	//[a b c d e f \0]
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//随机值
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
//	a[0]是第一行这个一维数组的数组名，单独放在sizeof内部，a[0]表示第一个整个这个一维数组
//	sizeof(a[0])计算的就是第一行的大小
//	printf("%d\n", sizeof(a[0] + 1));
//	a[0]并没有单独放在sizeof内部，也没取地址，a[0]就表示首元素的地址
//	就是第一行这个一维数组的第一个元素的地址，a[0] + 1就是第一行第二个元素的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));
//	a[0] + 1就是第一行第二个元素的地址
//	*(a[0] + 1))就是第一行第二个元素
//	printf("%d\n", sizeof(a + 1));//4/8
//	a虽然是二维数组的地址，但是并没有单独放在sizeof内部，也没取地址
//	a表示首元素的地址，二维数组的首元素是它的第一行，a就是第一行的地址
//	a+1就是跳过第一行，表示第二行的地址
//	printf("%d\n", sizeof(*(a + 1)));//16
//	*(a + 1)是对第二行地址的解引用，拿到的是第二行
//	*(a+1)-->a[1]
//	sizeof(*(a+1))-->sizeof(a[1])
//	
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	&a[0] - 对第一行的数组名取地址，拿出的是第一行的地址
//	&a[0]+1 - 得到的是第二行的地址
//	
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	a表示首元素的地址，就是第一行的地址
//	*a就是对第一行地址的解引用，拿到的就是第一行
//	
//	printf("%d\n", sizeof(a[3]));//16
//	只关注类型，不关注值 
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
//	//取地址a是数组a的地址  +1  后 是数组最后一个元素的地址再+1
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//a+1  a是首元素的地址，+1是第二个元素的地址，再解引用就是 2     
//	//ptr -1 是数组指针-1 也就是  a的地址  所以输出为  2   5 
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
//}* p = (struct Test*)0x100000;   //把地址值强制类型转换为struct
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
////x86
//int main()
//{
//	printf("%p\n", p + 0x1);//跳过一个结构体 20个字节
//	//0x100000+20-->0x100014
//	printf("%p\n", (unsigned long)p + 0x1);
//	//100000转换为整数位1048576
//	//1,048,576+1 --> 1,048,577
//	//0x100001 
//	printf("%p\n", (unsigned int*)p + 0x1);//跳过四个字节。 int型
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
//	//数组最后一个元素的地址+1（+4字节）
//	int* ptr2 = (int*)((int)a + 1);
//	//a转换为int类型后+1  只是+1 不是+四字节
//	//然后转换为int* 的地址。  相当于 a数组第一个元素的地址 + 一个字节。
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
//	//考逗号表达式， 这里等效于(1, 3, 5);
//	int* p;
//	p = a[0];//这里是第一行的地址，即第一个元素的地址  也就是 1
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
//	//int (*p)[4] 是数组指针变量，用来存放数组
//	p = a;
//	//a在这里是数组的名字，数组名=首元素地址，=第一行的地址，
//	// 它的类型是int (*) [5]
//	//而int(*p)[4]的指针类型是int (*) [4]
//	//所以数组指针p在存a的首元素地址的时候。是觉得这个数组以四个字节为一组去存的
//	//换个说法就是，如果此时对p+1  它的步长是4个字节。
//
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//	&p [4][2] 的意思是读取以p角度的第四排第二个数字。
//	// 此时p指向的是a的首元素的地址 0 。那么[4][2] 这个数字就要往右+4*4+2=18
//	//	也就是&p [4][2] 取的是数组a的第 18 / 5 = 3 ...3 第4行第4个
//	// 而 &a[4][2] 是第5行第3个。 中间差了4个字节。
//
//	//那么地址相减之后就是 -4   以%d打印就是-4
//	//但是以%p打印地址。就需要打印-4的补码的16进制了
//	//-4的原码是 10000000 00000000 00000000 00000100
//	//反码是     11111111 11111111 11111111 11111011
//	//补码是     11111111 11111111 11111111 11111100
//	//16进制是   F   F    F   F    F   F    F   C
//	
//	return 0;
//}