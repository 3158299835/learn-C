//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);//����
//	void* ret = dest;//��һ�¡�
//
//	while (num--)  // 4   3   2   1   1--Ϊ��
//	{
//		*(char*)dest = *(char*)src;//һ���ֽ�һ���ֽڿ�������Ȼ�����27��G��
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//
//	return ret;//����Ŀ���ڴ�ĵ�ַ
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//1,2,1,2,3,4,5,8,9,10
////int arr2[10] = { 0 };
////my_memcpy(arr2, arr1, 28);
//	my_memcpy(arr1 + 2, arr1, 20);
//	//memcoy�Ƕ����������ڴ�ռ���в�����
//	//memcpy ���𿽱���������ռ��е�����
//	//�ص��ڴ�Ŀ�������memmove ����
//
//	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
//	//float arr4[10] = { 0.0 };
//	//memcpy(arr4, arr3, 20);
//
//	return 0;
//}




////memmove��ģ��ʵ��
////��memcpy�����У�����ص����ڴ�ռ�ͻ᲻��ȷ�ķ�����ֵ�������
////�������ǿ��Ը���Դ��ַ��Ŀ���ַ��λ��������ж��ô�ǰ�����ƣ����ǴӺ���ǰ����
////Ŀ��ռ��Դ�ռ��ָ���ַ�ص���ʱ���������ˡ�
////���Ŀ��ռ����ʼ��ַС��Դ�ռ�ĵ�ַ����ô�ʹ�ǰ���� ����
////��֮����Ӻ���ǰ
////Ŀ����Ϊ���ڿ����Ĺ�����  �ڿ���ǰ���ı��������ֵ��
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);//����
//	void* ret = dest;//��һ�¡�
//	
//	if (dest < src)
//	{
//		//��ǰ������
//		while (num--)  // 4   3   2   1   1--Ϊ�� //������ֽ��Ǵ�ǰ���󿽱���
//		{
//			*(char*)dest = *(char*)src;//һ���ֽ�һ���ֽڿ�������Ȼ�����27��G��
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//�Ӻ���ǰ���ơ�Ҫ�����ҵ����һ����
//		while (num--)  // 4   3   2   1   1--Ϊ�� //������ֽ��Ǵ�ǰ���󿽱���
//		{
//			*((char*)dest + num) = *((char*)src + num);//��Դͷ�ã�����һ���ֽ�һ���ֽڿ�������Ȼ�����27��G��
//		}
//	}
//
//	return ret;//����Ŀ���ڴ�ĵ�ַ
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//1,2,1,2,3,4,5,8,9,10
////int arr2[10] = { 0 };
////my_memcpy(arr2, arr1, 28);
//	my_memmove(arr1 + 2, arr1, 20);
//	//memcoy�Ƕ����������ڴ�ռ���в�����
//	//memcpy ���𿽱���������ռ��е�����
//	//�ص��ڴ�Ŀ�������memmove ����
//
//	//float arr3[5] = { 1.0, 2.5,3.0,5.0,6.0 };
//	//float arr4[10] = { 0.0 };
//	//memcpy(arr4, arr3, 20);
//
//	return 0;
//}



//��������1  ��ż���� 0
//1 2 3   =  1 0 1
//22222   =  0

//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int intput = 0;
//	int sum = 0��
//	scanf("%d", &intput);
//	int i = 0;
//	while (intput)
//	{
//		int a = intput % 10;//���input����λ��
//		if (a % 2 == 1) //��Ϊ����
//		{
//			//���Ӧ��1��ӵ�sum�ĸ���ʮ����...��
//			sum += 1 * pow(10, i);
//			i++;//׼��Ϊ10λ�ϸ�ֵ��׼����
//		}
//		else//����Ϊż��
//		{
//			//���Ӧ��0��ӵ�sum�ĸ���ʮ����...��
//			sum += 0 * pow(10, i);
//			i++;//׼��Ϊ10λ�ϸ�ֵ��׼����
//		}
//		intput /= 10; 
//	}
//	return 0;
//
//}


////ʵ��һ�����������������ַ�����k���ַ�
//#include <stdio.h>
//#include <string.h>
//
//
////ʵ��һ�����������������ַ����е�k���ַ���
////����1
//void left_rotate(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	k %= len;
//	//��ʡ��Դ��ֱ��%�ַ�����
//	for (i = 0; i < k; i++)//����k��
//	{
//		char tmp = arr[0]; //�ѵ�һ���ַ�������
//		int j = 0;  
//		for (j = 0; j < len - 1; j++)//��ʣ�µ��ַ���������һ�Ρ�
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;//�ѸղŴ������ķŵ����һ��Ԫ�ص�λ�á�
//		//���ϣ�Ϊһ������
//	}
//}
//
////����2
//#include <assert.h>
//
////��ת������ַ֮���Ԫ��
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
////ͨ��revese�������������η�ת  
//// ������תn�κ�ĵ�λ����߽��з�ת���ұ߽��з�ת
////Ȼ��������з�ת
//void left_rotate(char arr[], int k)
//{
//	int len = strlen(arr);
//	k %= len;
//	//��ʡ��Դ��ֱ��%�ַ�����
//
//	reverse(arr, arr + k - 1);//��
//	reverse(arr + k, arr + len - 1);//��
//	reverse(arr, arr + len - 1);//��
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




////���Ͼ���
////��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
////���д�����������ľ����в���ĳ�������Ƿ���ڡ�
////Ҫ��ʱ�临�Ӷ�С��O(N);
////ʱ�临�Ӷȣ����оŸ�����������Ҫ��9�Σ������ҵ�����ô9����ʱ�临�Ӷ�n
//
////1 2 3
////4 5 6
////7 8 9
//
////�����������ұߵ��С����С���С���ô�϶�������һ���ˡ�
//// ��������С���ô���������ң��ҵ�С�ڵ������
//// ����ҵ��к�2��С��0�ˡ������ж�������2 �ˣ��ʹ���û��
//int find_num(int arr[3][3], int r, int c, int k)
//{
//	int x = 0;//��ʼ����
//	int y = c - 1;//��ʼ���С� �����Ͻ�
//	while (x<=r-1 && y>=0)//����ֹͣ������
//	{
//		if (k < arr[x][y])//���С�����ڵ���  ���Ͻ�
//		{ 
//			y--; //��ô�������ߡ���Ϊ�ղ���һ�п϶���û��
//		}
//		else if (k > arr[x][y])//������ڣ������������
//		{
//			x++;//������
//		}
//		else//�������������������㣬ֻ���ǵ����ˡ�
//		{
//			return 1;//�����Щ�����������㡣//Ȼ��ͷ���1���������ҵ���
//		}
//	}
//	return 0;//�Ҳ���
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
//			p.x = x;//�ѷ���ֵ���͵�ȫ�ֱ����Ľṹ����
//			p.y = y;
//			return p;//���ؽṹ��
//		}
//	}
//	return p;//�Ҳ���
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
////�����Ͳ���
//
//int find_num(int arr[3][3], int *px, int*py, int k)//���������ɺ�����ı����ĵ�ַ
//{
//	int x = 0;
//	int y = *py - 1;//���ݴ�����к������������Ͻ�
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
//			*px = x;//���ҵ������괫��x ��y
//			*py = y;
//			return 1;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;//�Ҳ���
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//	int a = 3;//��
//	int b = 3;//��
//	int ret = find_num(arr, &a, &b, k);
//	if (ret == 1)
//		printf("%d %d\n", a, b);
//	else
//		printf("�Ҳ���\n");
//
//
//	scanf("%d", &k);//�ٴ�������Ҫ���³�ʼ���к��С���Ȼ�ᴫ�������к���
//	a = 3;
//	b = 3;
//	ret = find_num(arr, &a, &b, k);
//	if (ret == 1)
//		printf("%d %d\n", a, b);
//	else
//		printf("�Ҳ���\n");
//	return 0;
//}
//
//
//
//
//
