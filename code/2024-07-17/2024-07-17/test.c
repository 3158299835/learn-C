#define _CRT_SECURE_NO_WARNINGS



//写一个程序，能求出整数在内存中的1的个数
//也就是求补码的1的个数
//思路，用到左移和按位与。相同为1，不同为0
//比如7的补码是000....111
//而1的补码是0000.....001
//那么第一次7&1的结果是1
//那么将7右移，再次与还是1
//再次右移，还是1
// 再次右移时，就为0了。

#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d", &a);
	//求出这个数在内存中站多少个bit
	int bit = sizeof(a) * 8;

	int count = 0;//计数

	int i = 0;
	int j = 0;
	//有多少个bit 就移动bit-1次
	for (i = 0; i < bit - 1; i++)
	{
		if (((a >> i) & 1) == 1)//向右移动啊！
		{
			count++;
		}
	}

	printf("%d", count);
	return 0;
}