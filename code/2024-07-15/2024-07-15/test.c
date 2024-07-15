#define _CRT_SECURE_NO_WARNINGS

// ----------------------------------------------------------

//题目名称:
//  字符串逆序(递归实现)
//  题目内容:
//  编写一个函数reverse_string(char* string)(递归实现)
//  将参数字符串中的字符反向排列，不是逆序打印。实现 : 要求 : 不能使用C函数库中的字符串操作函数.
//  比如 :
//	char arr[] = "abcdef"
//	逆序之后数组的内容变成 : fedcba
// ----------------------------------------------------------
#include <stdio.h>

//
//void reverse_string(char* string)
//{
//
//	
//}
//
//int main()
//{
//	//解决思路是直接把函数两两交换，从两边开始
//	//代码可以借鉴一下之前学过的二分查找
//	char arr[] = "abcdef";
//	//记录一下字符串的下标位置
//	int lift = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 2;
//	//注意哦，这里我是用的sizeof，他会把字符串后边的\0也计算在内 要计算拿下标就需要-2 
//	// 如果你用的是字符串求长函数'strlen'就是字符的个数啦~   -1就OK了
//	while (lift < right)
//	{
//		char temp = '0';
//		temp = arr[lift];
//		arr[lift] = arr[right];
//		arr[right] = temp;
//
//		lift++;
//		right--;
//	}
//	printf("%s", arr);
//
//
//	return 0;
//
//}

////函数方法解决
//#include <stdio.h>
//#include <string.h>
//void reverse_string(char arr[])
//{
//	int lift = 0;
//	int right = strlen(arr) - 1;  //strlen可以在函数中求长度， 不像那个sizeof
//
//	while (lift < right)
//	{
//		char temp = arr[lift];
//		arr[lift] = arr[right];
//		arr[right] = temp;
//
//		lift++;
//		right--;
//	}
//}
//
//int main()
//{
//
//	char arr[] = "abcdef";
//	reverse_string(arr);
//
//
//	printf("%s", arr);
//
//	return 0;
//
//}


////递归解决方法
//
////思考
////abcdef
////先交换a和f 再交换bcde
////bcde先交换d和e，再交换
////*str 就是第一个元素的地址
////*(str+1) 就是第二个元素的地址
////目的是让每次进去之后的长度变小。这样就可以一直交换了
////把最后一位填成 \0
//#include <stdio.h>
////要求：不能使用函数
//不能更改传参
//int my_strlen(char* str)//我的求长函数
//{
//	int count = 0;
//	while (*str != '\0')    //数到\0停下
//	{
//		count++;
//		str++;
// 	}
//
//	return count;
//}
////要保证每次传入的时候，第一个元素和最后一个元素的下标变化
//void reverse_string(char* str) //存是整个字符串的地址  地址是首元素的地址  
//{
//	//先把最后一个放到第一个的位置
//	int right = my_strlen(str) - 1; //求最后一个元素的下标 
//	printf("现在的字符长度%d\n", right);
//	char temp = *str;//临时储存第一位元素
//	*str = *(str + right);//把最后一个元素赋值给第一个元素
//	*(str + right) = '\0';//把最后一位元素填充为‘\0’
//	//开始下一轮
//	if (my_strlen(str + 1) > 1)//停止递归的条件：当下一次递归如果就剩一个数字了，就不用递归了.这个要提前算一下
//	{
//		reverse_string(str + 1); //能保证下一次str往右移动一位
//	}
//	*(str + right) = temp;//然后依此把临时变量放到他们的最后一个元素
//}
//
//int main()
//{
//
//	char arr[] = "abcdef";
//
//	reverse_string(arr);
//
//	printf("%s", arr);
//	return 0;
//
//}
//

//
////-----------------------------------
////计算一个数的所有数字之和
////使用递归
//
////1234
////123+4
////12+3
////1+2
//
////输入正整数
//
//#include <stdio.h>
//
//
//int DogitSum(unsigned int n)
//{
//
//	if (n > 9)
//	{
//		return DogitSum(n / 10) + n % 10;
//	}
//	return n;
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	int sum = DogitSum(n);
//	printf("%d", sum);
//	return 0;
//
//}




//-----------------------------
//实现输入n的k次方
//
//
//#include <stdio.h>
//
//
//double cf(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k > 0)
//	{
//		return n * cf(n, k - 1);
//	}
//	else if (k < 0)
//	{
//		return 1.0 / cf(n, -k);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double num = cf(n, k);
//	printf("%lf", num);
//	return 0;
//}


//
//
////数组的类型是 int [10]
//#include <stdio.h>
//
//int main()
//{
//	int num = 10;
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(num));//4
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(arr));  //40
//	printf("%d\n", sizeof(int [10]));  //40
//
//	return 0;
//}