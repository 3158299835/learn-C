#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//�˵�
void menu()
{
	printf("*******************************************\n");
	printf("*****           0.�˳���Ϸ            *****\n");
	printf("*****           1.��ʼ��Ϸ            *****\n");
	printf("*****         2.����͸��ģʽ          *****\n");
	printf("*****         3.��Ϸ����ָ��          *****\n");
	printf("*******************************************\n");
}


//��ʼ������
//���������̶���ֵΪ0  ����   '*'
void InitBoard(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			if (arrBom[0][0] == ' ')
			{
				arrBom[i][j] = ' ';
			}
			if (arrShow[0][0] == '*')
			{
				arrShow[i][j] = '*';
			}
		}
	}
}

//��ӡ�û�����
void DispalyShow(char arrShow[ROWS][COLS], int row, int col)//��ʾshow����
{

//ʵ���ϵ�����
//   |   |   |   |   |   |
//---|---|---|---|---|---|---
//   | * | * |   |   | * |
//---|---|---|---|---|---|---
//   | * |   |   |   |   |
//---|---|---|---|---|---|---
//   |   |   |   |   |   |

//��Ҫ��ӡ������
//	5�д�ӡ���"|---" 6��|
//                
//   |---|---|---|---|---|
//   | * | * |   |   | * |
//   |---|---|---|---|---|
//   | * |   |   |   |   |
//   |---|---|---|---|---|
	int i = 0;
	int j = 0;


	//��ӡ������
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	//��ӡ��һ��
	printf("   ");
	for (j = 0; j < col ; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//��ӡ������
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrShow[i + 1][j + 1]);
		}
		printf("|\n");
		//����
		printf("   ");
		for (j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}

//��ӡ��������
void DispalyBom(char arrBom[ROWS][COLS], int row, int col)//��ʾshow����
{
	int i = 0;
	int j = 0;
	//��ӡ������
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	//��ӡ��һ��
	printf("   ");
	for (j = 0; j < col; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//��ӡ������
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrBom[i + 1][j + 1]);
		}
		printf("|\n");
		//����
		printf("   ");
		for (j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}


//�������
void SetBom(char arrBom[ROWS][COLS], int rows, int cols, int num)
{
	int x = 0;
	int y = 0;
	int count = num;//�����׵�����
	while (count)//һֱ���ף�ֱ������
	{
		x = rand() % (rows - 2) + 1;  //x��Χ��1 -  rows-2
		y = rand() % (rows - 2) + 1;  //y��Χ��1 -  rows-2
		//����ط����벻���ַ�!��������
		if (arrBom[x][y] != '!')
		{
			arrBom[x][y] = '!';
			count--;
		}
	}
}

//��������ֵ��������߲�ը��
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
//��������ֵ��������߲�ը��
//�����Ū����Ҫ�ǲ�ը��
//��Ҫ�õ��ݹ飬˼��һ����ôŪ
//�����Χը��Ϊ0�����������Χ�˸������Ƿ���ը������������ݹ顣ֱ��Show���̵��ַ�Ϊ��0����
//��Ҫע��ݹ�ķ�Χ���ܳ�����Χ������ֱ�Ӵ��͹��������̡�+2��
//�ַ�0��ASCII��Ϊ48
// ��������ʾ�������׵���������������ʾ@��������ٲ����ȡ������
	int x = 0;
	int y = 0;
	int n = 0;
	printf("���������꼰����:>");
	scanf("%d %d %d", &x, &y, &n);
	system("cls");//�������������
	if (1 <= x && x <= rows && 1 <= y && y <= cols && (n == 1 || n == 2))//�ж������Ƿ���Ϸ�Χ
	{
		if (n == 2)//�첿��
		{
			if (arrShow[x][y] == '*')//���Ϊ*����죬���Ϊ@���Ϊ*�����Ϊ����0-8.���ܲ��� 48 +8 = 56
			{
				printf("����ɹ�������Ϊ%d %d\n", x, y);
				arrShow[x][y] = '@';
			}
			else if (arrShow[x][y] == '@')
			{
				printf("ȡ��ɹ�������Ϊ%d %d\n", x, y);
				arrShow[x][y] = '*';
			}
			else if (48 <= arrShow[x][y] && arrShow[x][y] <= 56)//�ַ�תASCII��
			{
				printf("����ط�����ˣ���һ���ط������\n");
			}
		}
		if (n == 1)//ը������  �����괫��ȥ�����һ�Ҫ���������Լ������̵ĳ��Ϳ�
		{
			if (arrBom[x][y] == '!')//����ը����
			{
				printf("�㱻��ը����\n");
				return -1;
			}
			else
			{
				FindBom(arrBom, arrShow, rows, cols, x, y);//�ݹ���Һ���
			}
		}
	}
	else
	{
		printf("��ʽ����\n");
		printf("��ʽΪ���к� �к� 1��2\n");
		printf("1Ϊ���ף�2Ϊ����\n");
	}
}

//�ݹ���Һ���
//ֹͣ��������Χ��ը����>=1
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols, int x, int y)
{
//��������Χ�˸��ĺ��ǲ���0 �����������˸�����ݹ�,���Ұѵ�ǰ�������滻Ϊ���ǵĺ�
//��Ϊ���ַ���' '��ascii��38     ��'��'��ascii��39  

// x-1,y-1   x-1,y     x-1,y+1
// x,y-1      x,y      x,y+1
// x+1,y-1   x+1,y     x+1,y+1

//����鵽��x y����Ϊ�����̵ı߽����꣬��ô��ֹͣ����
	if (x == 0 || x == rows || y == 0 || y == cols)
	{
		return;//ֹͣ
	}
	// ����õ�Ԫ���Ѿ�����¶�����ٴ���
	if (arrShow[x][y] == ' ') 
	{
		return;
	}
	//�����׵ĸ���
	int count = (arrBom[x - 1][y - 1] +
		arrBom[x - 1][y] +
		arrBom[x - 1][y + 1] +
		arrBom[x][y - 1] +
		arrBom[x][y + 1] +
		arrBom[x + 1][y - 1] +
		arrBom[x + 1][y] +
		arrBom[x + 1][y + 1]) - (8 * ' ');
	if (count != 0)//����ը��,��ʾը������
	{
		arrShow[x][y] = '0' + count;//ע��show���ַ�������Ӧ��+ '0'
	}
	else//��ǰλ��Ϊ0 ��������µݹ飬���Ұѵ�ǰ���ַ���Ϊ' '
	{
		arrShow[x][y] = ' ';
		FindBom(arrBom, arrShow, rows, cols, x - 1, y - 1);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x - 1, y);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x - 1, y + 1);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x, y - 1);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x, y + 1);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x + 1, y - 1);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x + 1, y);//�ݹ��������
		FindBom(arrBom, arrShow, rows, cols, x + 1, y + 1);//�ݹ��������
	}
}

//�ж���Ӯ
int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	//���show���̵�*����bom���̵�!�ʹ���ʣ�µĶ����ף���ʤ��
	int showbom = 0;
	int bom = 0;

	int i = 0;
	int j = 0;
	//����arrbom�е�!
	for (i = 1; i < rows - 2; i++)
	{
		for (j = 1; j < cols - 2; j++)
		{
			if (arrBom[i][j] == '!')
			{
				bom++;
			}
			if (arrShow[i][j] == '*')
			{
				showbom++;
			}
		}
	}
	if (showbom == bom)//��ʤ��
	{
		printf("��Ӯ��\n");
		return 1;
	}
}