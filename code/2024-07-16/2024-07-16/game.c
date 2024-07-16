#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//�˵�
void menu()
{
	printf("*******************************************\n");
	printf("*****           0.�˳���Ϸ            *****\n");
	printf("*****           1.��ʼ��Ϸ            *****\n");
	printf("*****         2.����͸��ģʽ          *****\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}


//��ʼ������
//���������̶���ֵΪ0  ����   ' '
void InitBoard(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			if (arrBom[0][0] == 0)
			{
				arrBom[i][j] = 0;
			}
			if (arrShow[0][0] == '*')
			{
				arrShow[i][j] = '*';
			}
		}
	}
}




void DispalyShow(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int row, int col)//��ʾshow����
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