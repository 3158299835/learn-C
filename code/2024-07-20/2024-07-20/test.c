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
//		//在p = 10 的一次*p = i时候，p就是野指针了。
//		//他的访问超过了数组的范围
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
//在这个演示中，p在接受a的地址后，
// 因为a是局部变量。在函数结束后就被释放了。
// 如果你在下面再用a的地址去找到这片区域时它并不能访问。
// 那么p就是野指针了。
	//如果此时打印*p所指向的空间，结果仍然是上一个局部变量的值，也就是10
	//因为这里的局部变量虽然已经被销毁，但是他的数据仍然还在。只是等待下次被覆盖
	//如果打印一下别的东西，当系统利用到这片空间后。它内部存储的值将发生改变
	//所以打印的也就不是10了


//#include <stdio.h> 
//
////当一个指着你不知道初始化什么值的时候，
//// 就把他赋值为空指针NULL
//int* p = NULL;
////在下次使用的时候，为了避免出现问题可以这样写
//if (p != NULL)
//{
//	*p = 100;//如果不为空指针就对他所指向的对象进行赋值
//	//如果对空指针赋值，会程序报错
//}
//
// 
// 
////指针的加减运算
//#include <stdio.h>
//#define N_VALUES 5
//int main()
//{
//	float valueS[N_VALUES]; float* vp;
//	//指针+-整数;指针的关系运算
//	for (vp = &valueS[0]; vp < &valueS[N_VALUES];)
//	{
//		*vp++ = 0;
//	}
//}
////这个示例代码中。
////`*vp++ = 0; ` 为先使用后++所以第0 1 2 3 4 个指针都会被赋值为0
////这里的++指的是地址++
////并且这里的for循环在检测vp内存储的地址是否小于&valueS[N_VALUES]时。
////虽然看了一眼数组之外的数值，但是实际并没有操作这块没有权限的空间，
//// 所以也不是野指针

//

//
////指针减指针
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

////指针-指针实现字符串求长度
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return(str - start);
//}

////指针和数组
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
//	//说明&arr[i], p + i 等价
//
//	return 0;
//}

////二级指针
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa是一级指针变量
//	
//	int** ppa = &pa;//ppa是指针的指针，是二级指针变量
//	//这里的最后边的 *是说明。ppa是指针
//	//int* 说明ppa所指向的对象是int*类型
//	**ppa = 20;//这样就解引用到了a
//
//	return 0;
//}

////指针数组
////存放指针的数组
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
//	//打印指针数组中的指针
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
//			//这里的parr[i]不需要解引用。
//			//parr[0]指的是指针变量中存储的第一个元素的地址。
//			//也就是arr1的首地址，而arr1的地址等同于arr1。
//			//所以parr[0]就等同于arr1
//			//加上后面的[j] 则是访问arr1的下标为j的元素。等同于arr1[j]
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//struct Peo //创建结构体  此时只是一个模板，并没有内存空间
//{
//	char name[20];
//	char tele[12];
//	char sex[5];//女男 保密
//	int high;
//};
//struct St//结构体中可以有另一个结构体变量。这个结构体依赖于上个结构体
//{
//	struct peo p;
//	int num;
//	float f;
//};

//写一个函数，返回参数中二进制数中1的个数的一道很妙的解法
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



///写一个函数，输入两个数字。输出他们的二进制数有几位不同
//写法1   按位比较
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

////写法2  异或操作符   相同为0 相异为1
////
//int	count_diff_bit(int a, int b)
//{
//	int n = a ^ b;//求出多少个位不一样（在二进制中为1）
//	//找出1的个数
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

////打印一个数字中的二进制序列中的奇数位和偶数位
////偶数位从0开始 
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//
//	//打印偶数位。从左往右打印。
//	//最左边需要想左直接移动31位数字
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

////输出x。会根据n的输入而变换
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
//				else if (i + j == n - 1)//由右上到左下
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


////输入年份、月份输出这个月的天数
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
//	while (scanf("%d %d", &y, &m) == 2)//正确输入两个则返回2
//	{
//		int d = days[m];
//		if ((is_leap_year(y) == 1) && (m == 2))
//		{
//			d++;
//		}
//		printf("%d\n", d);
//	}
//}