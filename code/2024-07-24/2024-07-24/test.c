//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1); 
//	//�����ַ+1����ȥ�� = aa���һ��Ԫ�صĵ�ַ+1�ĵ�ַ
//	//�����&aaȡ������aa����Ԫ�� ��һ������ĵ�ַ��
//	int* ptr2 = (int*)(*(aa + 1));
//	// �����aa����Ԫ�صĵ�ַ
//	//aa���ǵ�������������ģ� ���Դ�ʱ��aa�Ƕ�ά����ĵ�һ��Ԫ�صĵ�ַ��
//	// Ҳ���ǵ�һ�еĵ�ַ��Ȼ����+1 �õ����ǵڶ��е�һ��Ԫ�صĵ�ַ��
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	//ptr1 -1 �� ���һ��Ԫ�صĵ�ַ�� �ٽ�����  =   10
//	// ptr2 -1  �ǵڶ��е�һ����Ԫ�صĵ�ַ-1 ����һ�����һ��Ԫ�صĵ�ַ��   ��  10   5
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
// ���at  pa����ǵ�һ���׵�ַ��Ȼ��++ ��at
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
//	//��++ ������ ��-- ��++�������� 
//	printf("%s\n", *cpp[-2] + 3);  // ST
//	//  = **(cpp-2) +3 
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	//==  *(*(cp-1)-1)+1
//	//+1 �����Ų����ģ���������1�ֽ�
//	return 0;
//}


////дһ��strcp
//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//
//////����Ŀ��ռ����ʼ��ַ
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
////	*arr2 = '\0';//���һ��Ҫ��\��ֵ��ȥ
////	return p;
////}
//
//
////�򻯺�
//
//int my_strcpy(char* arr1, char* arr2)
//{
//	char* p = arr1;
//	assert(arr1 && arr2);
//	while (*arr1++ = *arr2++)//��ֵΪ\0�� asciiΪ0 �˳�ѭ��
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
////�ַ���׷��ģ��
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
////�ַ����ԱȺ��� strcmpģ��
////int my_strcmp(const char* str1, const char* str2)
////{
////	assert(str1 && str2);
////	while (*str1 == *str2)
////	{
////		if (*str1 == '\0')//����Ҷ�Ϊ\0�Ͳ�������Ƚ��ˡ�
////		{
////			return 0; 
////		}
////		str1++;
////		str2++;
////	}
////	//�������������ҵ���
////	if (*str1 > *str2)//��һȦ�ҵ�һ����һ���ģ��жϴ�СȻ�󷵻�ֵ
////	{
////		return 1;
////	}
////	else
////	{
////		return -1;
////	}
////}
////���ԸĽ�һ��
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//����Ҷ�Ϊ\0�Ͳ�������Ƚ��ˡ�
//		{
//			return 0; 
//		}
//		str1++;
//		str2++;
//	}
//	//�������������ҵ���
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





//KMP�㷨
//����㷨Ҳ������ʵ����һ���ַ����в������ַ�����
//Ч�ʸߣ�����ʵ���Ѷȴ�
//Bվ���������ش󲩸磬�����ҵ�KMP�㷨��ʵ��
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	//��֤������ֿ�ָ�����
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	//pΪ��������￪ʼ�����ҵ����ַ���
//	//���һ��û�Ҿ�+1�����ң�ֱ���ҵ� \0��λ��
//
//	while (*p)//��\0�����û�ҵ���
//	{
//		s1 = p;//��ָ��s1��ֵΪp��λ�ã�Ϊ������²������ַ�����׼����
//		s2 = str2;//���ô����ҵ��ַ�����ָ��
//		while (*s1!='\0' && *s2!='\0' && *s1 == *s2)//������ַ������ַ�����ָ�뵽\0 ��ͣ�£��ڴ˻����������Ⱦͼ�������һ����ȵ�
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//���ѭ������֮�󣬴����ҵ����ַ�����ָ�뵽\0�ʹ����Ѿ��ҵ��ˡ�
//		{
//			return (char*)p;//����p�ĵ�ַ��
//		}
//		p++;
//	}
//	return NULL;//û�ҵ��򷵻ؿ�ָ��
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
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//
//strtok
//�и��ַ��� 
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




////C���ԵĿ⺯������ִ��ʧ�ܵ�ʱ�򣬶������ô�����
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
//	//errno - C�������õ�һ��ȫ�ֵĴ������ŵı���
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