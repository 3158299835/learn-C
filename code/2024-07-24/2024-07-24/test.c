//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1); 
//	//数组地址+1跳过去， = aa最后一个元素的地址+1的地址
//	//这里的&aa取出的是aa的首元素 即一个数组的地址。
//	int* ptr2 = (int*)(*(aa + 1));
//	// 这里的aa是首元素的地址
//	//aa不是单独放在这里面的， 所以此时的aa是二维数组的第一个元素的地址，
//	// 也就是第一行的地址，然后再+1 得到的是第二行第一个元素的地址，
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	//ptr1 -1 是 最后一个元素的地址。 再解引用  =   10
//	// ptr2 -1  是第二行第一个的元素的地址-1 即第一组最后一个元素的地址，   即  10   5
//	//  10    5 
//	return 0;
//}
//
//
//
//
//
//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//
//	pa++;
//	printf("%s\n", *pa);
// 输出at  pa存的是第一个首地址，然后++ 到at
//	return 0;
//}
//
//
//
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	//先++ 解引用 后-- 再++最后解引用 
//	printf("%s\n", *cpp[-2] + 3);  // ST
//	//  = **(cpp-2) +3 
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	//==  *(*(cp-1)-1)+1
//	//+1 是最后才操作的，。步长是1字节
//	return 0;
//}


////写一个strcp
//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//
//////返回目标空间的起始地址
////int my_strcpy(char* arr1, char* arr2)
////{
////	char* p = arr1;
////	assert(arr1);
////	assert(arr2);
////
////	while (*arr2 != '\0')
////	{
////		*arr1++ = *arr2++;
////	}
////	*arr2 = '\0';//最后一次要把\赋值上去
////	return p;
////}
//
//
////简化后
//
//int my_strcpy(char* arr1, char* arr2)
//{
//	char* p = arr1;
//	assert(arr1 && arr2);
//	while (*arr1++ = *arr2++)//赋值为\0后 ascii为0 退出循环
//		;
//	return p;
//}
//
//int main()
//{
//	char arr1[] = "woaini";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s", arr2);
//
//
//	return 0;
//}




//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////字符串追加模拟
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest&&src);
//	char* ret = dest; 
//	assert(dest && src);
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{	
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[20] = "woaini";
//	char arr2[] = "yuanzhiqi";
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//
//
//	return 0;
//}






//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////字符串对比函数 strcmp模拟
////int my_strcmp(const char* str1, const char* str2)
////{
////	assert(str1 && str2);
////	while (*str1 == *str2)
////	{
////		if (*str1 == '\0')//相等且都为\0就不用往后比较了。
////		{
////			return 0; 
////		}
////		str1++;
////		str2++;
////	}
////	//不相等了则代表找到了
////	if (*str1 > *str2)//找一圈找到一个不一样的，判断大小然后返回值
////	{
////		return 1;
////	}
////	else
////	{
////		return -1;
////	}
////}
////可以改进一下
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//相等且都为\0就不用往后比较了。
//		{
//			return 0; 
//		}
//		str1++;
//		str2++;
//	}
//	//不相等了则代表找到了
//	return (*str1 - *str2);
//}
//
//int main()
//{
//	char arr1[20] = "woaini";
//	char arr2[] = "x";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf(">");
//	}
//	else if(ret < 0)
//	{
//		printf("<");
//	}
//	else
//	{
//		printf("=");
//	}
//	return 0;
//}





//KMP算法
//这个算法也是用来实现在一个字符串中查找子字符串的
//效率高，但是实现难度大
//B站搜索：比特大博哥，可以找到KMP算法的实现
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	//保证不会出现空指针访问
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	//p为假设从这里开始可以找到子字符串
//	//如果一次没找就+1继续找，直到找到 \0的位置
//
//	while (*p)//到\0则代表没找到。
//	{
//		s1 = p;//把指针s1赋值为p的位置，为这次重新查找子字符串做准备。
//		s2 = str2;//重置待查找的字符串的指针
//		while (*s1!='\0' && *s2!='\0' && *s1 == *s2)//如果子字符串和字符串的指针到\0 就停下，在此基础上如果相等就继续找下一个相等的
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//如果循环完了之后，待查找的子字符串的指针到\0就代表已经找到了。
//		{
//			return (char*)p;//返回p的地址，
//		}
//		p++;
//	}
//	return NULL;//没找到则返回空指针
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "def";
//	char* ret = my_strstr(arr1, arr2);
//
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//
//strtok
//切割字符串 
//
// zhangpengwei@bitejiuyeke.com

//
//int main()
//{
//	const char* sep = "@.";
//	char email[] = "zhangpengwei@bitejiuyeke.com.net";
//	char cp[40] = { 0 };//"zhangpengwei@bitejiuyeke.com"
//	strcpy(cp, email);
//
//	char* ret = NULL;
//	for (ret = strtok(cp, sep);
//		ret != NULL;
//		ret = strtok(NULL, sep))
//	{
//		printf("%s\n", ret);
//	}
//
//	//char* ret = strtok(cp, sep);
//	//if(ret != NULL)
//	//	printf("%s\n", ret);
//
//	//ret = strtok(NULL, sep);
//	//if (ret != NULL)
//	//	printf("%s\n", ret);
//
//	//ret = strtok(NULL, sep);
//	//if (ret != NULL)
//	//	printf("%s\n", ret);
//
//	//ret = strtok(NULL, sep);
//	//if (ret != NULL)
//	//	printf("%s\n", ret);
//
//	return 0;
//}




////C语言的库函数，在执行失败的时候，都会设置错误码
////0 1 2 3 4 5 6 7 8 
////
//
//#include <errno.h>
//
//int main()
//{
//	//printf("%s\n", strerror(0));
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(3));
//	//printf("%s\n", strerror(4));
//	//printf("%s\n", strerror(5));
//
//	//errno - C语言设置的一个全局的错误码存放的变量
//
//	FILE* pf = fopen("C:\\Users\\zpeng\\Desktop\\test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		//
//	}
//	return 0;
//}