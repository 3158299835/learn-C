#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//菜单
void menu()
{
	printf("*******************************************\n");
	printf("*****           0.退出游戏            *****\n");
	printf("*****           1.开始游戏            *****\n");
	printf("*****         2.开启透视模式          *****\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}


//初始化棋盘
//把两个棋盘都赋值为0  或者   ' '
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




void DispalyShow(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int row, int col)//显示show棋盘
{

//实际上的数组
//   |   |   |   |   |   |
//---|---|---|---|---|---|---
//   | * | * |   |   | * |
//---|---|---|---|---|---|---
//   | * |   |   |   |   |
//---|---|---|---|---|---|---
//   |   |   |   |   |   |

//需要打印的数组
//	5列打印五次"|---" 6次|
//                
//   |---|---|---|---|---|
//   | * | * |   |   | * |
//   |---|---|---|---|---|
//   | * |   |   |   |   |
//   |---|---|---|---|---|
	int i = 0;
	int j = 0;


	//打印列坐标
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	//打印第一行
	printf("   ");
	for (j = 0; j < col ; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//打印行坐标
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrShow[i + 1][j + 1]);
		}
		printf("|\n");
		//兜底
		printf("   ");
		for (j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}