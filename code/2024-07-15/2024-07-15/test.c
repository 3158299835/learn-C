#define _CRT_SECURE_NO_WARNINGS

// ----------------------------------------------------------

//��Ŀ����:
//  �ַ�������(�ݹ�ʵ��)
//  ��Ŀ����:
//  ��дһ������reverse_string(char* string)(�ݹ�ʵ��)
//  �������ַ����е��ַ��������У����������ӡ��ʵ�� : Ҫ�� : ����ʹ��C�������е��ַ�����������.
//  ���� :
//	char arr[] = "abcdef"
//	����֮����������ݱ�� : fedcba
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
//	//���˼·��ֱ�ӰѺ������������������߿�ʼ
//	//������Խ��һ��֮ǰѧ���Ķ��ֲ���
//	char arr[] = "abcdef";
//	//��¼һ���ַ������±�λ��
//	int lift = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 2;
//	//ע��Ŷ�����������õ�sizeof��������ַ�����ߵ�\0Ҳ�������� Ҫ�������±����Ҫ-2 
//	// ������õ����ַ����󳤺���'strlen'�����ַ��ĸ�����~   -1��OK��
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

////�����������
//#include <stdio.h>
//#include <string.h>
//void reverse_string(char arr[])
//{
//	int lift = 0;
//	int right = strlen(arr) - 1;  //strlen�����ں������󳤶ȣ� �����Ǹ�sizeof
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


////�ݹ�������
//
////˼��
////abcdef
////�Ƚ���a��f �ٽ���bcde
////bcde�Ƚ���d��e���ٽ���
////*str ���ǵ�һ��Ԫ�صĵ�ַ
////*(str+1) ���ǵڶ���Ԫ�صĵ�ַ
////Ŀ������ÿ�ν�ȥ֮��ĳ��ȱ�С�������Ϳ���һֱ������
////�����һλ��� \0
//#include <stdio.h>
////Ҫ�󣺲���ʹ�ú���
//���ܸ��Ĵ���
//int my_strlen(char* str)//�ҵ��󳤺���
//{
//	int count = 0;
//	while (*str != '\0')    //����\0ͣ��
//	{
//		count++;
//		str++;
// 	}
//
//	return count;
//}
////Ҫ��֤ÿ�δ����ʱ�򣬵�һ��Ԫ�غ����һ��Ԫ�ص��±�仯
//void reverse_string(char* str) //���������ַ����ĵ�ַ  ��ַ����Ԫ�صĵ�ַ  
//{
//	//�Ȱ����һ���ŵ���һ����λ��
//	int right = my_strlen(str) - 1; //�����һ��Ԫ�ص��±� 
//	printf("���ڵ��ַ�����%d\n", right);
//	char temp = *str;//��ʱ�����һλԪ��
//	*str = *(str + right);//�����һ��Ԫ�ظ�ֵ����һ��Ԫ��
//	*(str + right) = '\0';//�����һλԪ�����Ϊ��\0��
//	//��ʼ��һ��
//	if (my_strlen(str + 1) > 1)//ֹͣ�ݹ������������һ�εݹ������ʣһ�������ˣ��Ͳ��õݹ���.���Ҫ��ǰ��һ��
//	{
//		reverse_string(str + 1); //�ܱ�֤��һ��str�����ƶ�һλ
//	}
//	*(str + right) = temp;//Ȼ�����˰���ʱ�����ŵ����ǵ����һ��Ԫ��
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
////����һ��������������֮��
////ʹ�õݹ�
//
////1234
////123+4
////12+3
////1+2
//
////����������
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
//ʵ������n��k�η�
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
////����������� int [10]
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