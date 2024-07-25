//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);//断言
//	void* ret = dest;//存一下。
//
//	while (num--)  // 4   3   2   1   1--为非
//	{
//		*(char*)dest = *(char*)src;//一个字节一个字节拷贝，不然分享个27就G了
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//
//	return ret;//返回目标内存的地址
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//1,2,1,2,3,4,5,8,9,10
////int arr2[10] = { 0 };
////my_memcpy(arr2, arr1, 28);
//	my_memcpy(arr1 + 2, arr1, 20);
//	//memcoy是对两个独立内存空间进行操作。
//	//memcpy 负责拷贝两块独立空间中的数据
//	//重叠内存的拷贝。是memmove ！！
//
//	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
//	//float arr4[10] = { 0.0 };
//	//memcpy(arr4, arr3, 20);
//
//	return 0;
//}




////memmove的模拟实现
////在memcpy函数中，面对重叠的内存空间就会不正确的发生赋值的情况。
////所以我们可以根据源地址和目标地址的位置情况来判断用从前往后复制，还是从后往前复制
////目标空间和源空间的指针地址重叠的时候不用讨论了。
////如果目标空间的起始地址小于源空间的地址，那么就从前往后 拷贝
////反之，则从后往前
////目的是为了在拷贝的过程中  在拷贝前不改变待拷贝的值。
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);//断言
//	void* ret = dest;//存一下。
//	
//	if (dest < src)
//	{
//		//从前往后复制
//		while (num--)  // 4   3   2   1   1--为非 //这里的字节是从前往后拷贝。
//		{
//			*(char*)dest = *(char*)src;//一个字节一个字节拷贝，不然分享个27就G了
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后往前复制。要想先找到最后一个。
//		while (num--)  // 4   3   2   1   1--为非 //这里的字节是从前往后拷贝。
//		{
//			*((char*)dest + num) = *((char*)src + num);//从源头拿！！！一个字节一个字节拷贝，不然分享个27就G了
//		}
//	}
//
//	return ret;//返回目标内存的地址
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//1,2,1,2,3,4,5,8,9,10
////int arr2[10] = { 0 };
////my_memcpy(arr2, arr1, 28);
//	my_memmove(arr1 + 2, arr1, 20);
//	//memcoy是对两个独立内存空间进行操作。
//	//memcpy 负责拷贝两块独立空间中的数据
//	//重叠内存的拷贝。是memmove ！！
//
//	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
//	//float arr4[10] = { 0.0 };
//	//memcpy(arr4, arr3, 20);
//
//	return 0;
//}



//把奇数变1  把偶数变 0
//1 2 3   =  1 0 1
//22222   =  0

//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int intput = 0;
//	int sum = 0：
//	scanf("%d", &intput);
//	int i = 0;
//	while (intput)
//	{
//		int a = intput % 10;//求出input各个位。
//		if (a % 2 == 1) //则为奇数
//		{
//			//则对应的1添加到sum的个、十、百...上
//			sum += 1 * pow(10, i);
//			i++;//准备为10位上赋值做准备。
//		}
//		else//否则为偶数
//		{
//			//则对应的0添加到sum的个、十、百...上
//			sum += 0 * pow(10, i);
//			i++;//准备为10位上赋值做准备。
//		}
//		intput /= 10; 
//	}
//	return 0;
//
//}


////实现一个函数。可以左旋字符串中k个字符
//#include <stdio.h>
//#include <string.h>
//
//
////实现一个函数，可以左旋字符串中的k个字符。
////方法1
//void left_rotate(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	k %= len;
//	//节省资源。直接%字符长度
//	for (i = 0; i < k; i++)//左移k次
//	{
//		char tmp = arr[0]; //把第一个字符存起来
//		int j = 0;  
//		for (j = 0; j < len - 1; j++)//把剩下的字符整体左移一次。
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;//把刚才存起来的放到最后一个元素的位置。
//		//综上，为一次左移
//	}
//}
//
////方法2
//#include <assert.h>
//
////反转两个地址之间的元素
//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
////通过revese函数来进行三次反转  
//// 以左旋转n次后的点位的左边进行反转、右边进行反转
////然后整体进行反转
//void left_rotate(char arr[], int k)
//{
//	int len = strlen(arr);
//	k %= len;
//	//节省资源。直接%字符长度
//
//	reverse(arr, arr + k - 1);//左
//	reverse(arr + k, arr + len - 1);//右
//	reverse(arr, arr + len - 1);//整
//}
//
//int main()
//{
//	char arr[] = "abcdef";//cdefab
//	int k = 0;
//	scanf("%d", &k);//2
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//
//	return 0;
//}




////杨氏矩阵
////有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
////请编写程序在这样的矩阵中查找某个数字是否存在。
////要求：时间复杂度小于O(N);
////时间复杂度，。有九个东西，至多要找9次，才能找到。那么9就是时间复杂度n
//
////1 2 3
////4 5 6
////7 8 9
//
////采用先找最右边的列、如果小于列。那么肯定不在这一列了。
//// 如果大于列。那么继续向下找，找到小于的情况。
//// 如果找到行号2都小于0了、或者列都大于列2 了，就代表没有
//int find_num(int arr[3][3], int r, int c, int k)
//{
//	int x = 0;//初始的行
//	int y = c - 1;//初始的列。 在右上角
//	while (x<=r-1 && y>=0)//定义停止的条件
//	{
//		if (k < arr[x][y])//如果小于现在的列  右上角
//		{ 
//			y--; //那么就往左走。因为刚才那一列肯定都没有
//		}
//		else if (k > arr[x][y])//如果大于，则继续往下找
//		{
//			x++;//往下找
//		}
//		else//上面两个条件都不满足，只能是等于了。
//		{
//			return 1;//如果这些条件都不满足。//然后就返回1告诉他我找到了
//		}
//	}
//	return 0;//找不到
//}
//
//struct Point
//{
//	int x;
//	int y;
//};
//
//struct Point find_num(int arr[3][3], int r, int c, int k)
//{
//	int x = 0;
//	int y = c - 1;
//	struct Point p = { -1, -1 };
//	while (x <= r - 1 && y >= 0)
//	{
//		if (k < arr[x][y])
//		{
//			y--;
//		}
//		else if (k > arr[x][y])
//		{
//			x++;
//		}
//		else
//		{
//			p.x = x;//把返回值发送到全局变量的结构体中
//			p.y = y;
//			return p;//返回结构体
//		}
//	}
//	return p;//找不到
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//	struct Point ret = find_num(arr, 3, 3, k);
//	printf("%d %d\n", ret.x, ret.y);
//	return 0;
//}
//
//
//
////返回型参数
//
//int find_num(int arr[3][3], int *px, int*py, int k)//输入参数变成函数外的变量的地址
//{
//	int x = 0;
//	int y = *py - 1;//根据传入的行和列来定义右上角
//	while (x <= *px - 1 && y >= 0)
//	{
//		if (k < arr[x][y])
//		{
//			y--;
//		}
//		else if (k > arr[x][y])
//		{
//			x++;
//		}
//		else
//		{
//			*px = x;//把找到的坐标传给x 和y
//			*py = y;
//			return 1;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;//找不到
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//	int a = 3;//行
//	int b = 3;//列
//	int ret = find_num(arr, &a, &b, k);
//	if (ret == 1)
//		printf("%d %d\n", a, b);
//	else
//		printf("找不到\n");
//
//
//	scanf("%d", &k);//再次输入需要重新初始化行和列。不然会传入错误的行和列
//	a = 3;
//	b = 3;
//	ret = find_num(arr, &a, &b, k);
//	if (ret == 1)
//		printf("%d %d\n", a, b);
//	else
//		printf("找不到\n");
//	return 0;
//}
//
//
//
//
//
