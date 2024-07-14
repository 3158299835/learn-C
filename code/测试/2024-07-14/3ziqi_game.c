#define _CRT_SECURE_NO_WARNINGS

#include "3ziqi_game.h"




int game(int a)
{

	//定义棋盘
	char Board[ROW][COL] = { 0 };

	//初始化棋盘
	InitBoard(Board, ROW, COL);
	
	int Power = 1;//用来控制是否循环
	int role = 0; // 0为电脑  1为玩家
	while (Power)
	{	
		switch (a)
		{
			case 0:
			{
				Power = 0;
				break;//退出游戏
			}
			case 1://玩家对战
			{
				role = 1;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL,role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//玩家2输入
				Player2_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 2://电脑对战
			{
				role = 0;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//电脑输入
				Easy_Computer_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 3:
			{
				role = 0;
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//玩家1输入
				Player1_input(Board, ROW, COL);
				//打印棋盘
				DisplayBoard(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//电脑输入
				Hard_Computer_input(Board, ROW, COL);
				//输入完检测
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}
		}
	}

}

//游戏菜单
void menu()
{
	printf("\n***************************************\n");
	printf("*****         1. 玩家对战         *****\n");
	printf("*****         2. 简单电脑         *****\n");
	printf("*****         3. 困难电脑         *****\n");
	printf("*****         0. 离开游戏         *****\n");
	printf("***************************************\n");
}

//初始化棋盘
void InitBoard(char Board[ROW][COL],int row,int col)//注意区分大小写
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			Board[i][j] = ' ';  //把这么多的行和列都赋值为空格
		}
	}
}

//打印棋盘---------------------------------------------------------------------
//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |    
// 
//把这个当成一次
//   |   |   
//---|---|---
//
//那么只需要少打印一次|和---|---|---即可
//再把---|当成一次，主需要少打印一次|就可以实现对列的自适应
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++) //打印一次
		{
			//打印初始化棋盘的第i行j列的字符
			printf(" %c ", Board[i][j]);
			//打印 | COL-1次
			if (j < row - 1)  //少打印一次 |
			{
				printf("|");
			}
		}
		//换行
		printf("\n");
		if (i < col - 1)//少打印一次---|---|---
		{
			int k = 0;
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)//少打印一次 |
				{
					printf("|");
				}
			}
		}
		printf("\n");//打印完一行
	}
}

//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------

//输入

//规则
//只能落子在未被放置的区域
//注意程序中的坐标和玩家输入坐标不一致需要-1.
//注意不要让他输入出棋盘范围



//----------------------------------
//玩家输入1
//玩家输入坐标1-ROW 1-COL 来落子，落子符号为*
void Player1_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("玩家1落子>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '*';
			break;//跳出
		}
		else //否则不符合要求，
		{
			printf("\n坐标不符合要求，请重新输入。\n输入范围应是(1-%d 1-%d)\n且不要在已有棋子的情况下落子\n\n", row, col);
		}
	}
}
//----------------------------------



//----------------------------------
//玩家输入2
//玩家输入坐标1-ROW 1-COL 来落子，落子符号为#
void Player2_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("玩家2落子>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '#';
			break;//跳出
		}
		else //否则不符合要求，
		{
			printf("\n坐标不符合要求，请重新输入。\n输入范围应是(1-%d 1-%d)\n且不要在已有棋子的情况下落子\n\n", row, col);
		}
	}
}
//----------------------------------



//----------------------------------
//电脑输入(简单)
//玩家自动落子，落子符号为#
//随机输入- 
// srand <stdlib.h>
void Easy_Computer_input(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑落子\n");
	while (1)
	{
		//设置一个随机值，让电脑在棋盘范围内随机下棋
		x = rand() % row;
		y = rand() % col;
		//填进去，如果填的进去就退出循环、注意这里的x和y他是0-row-1的范围 不用像玩家输入一样-1
		if (Board[x][y] != '*' && Board[x][y] != '#' && 0 <= x && x <= row - 1 && 0 <= y && y <= col - 1)
		{
			Board[x][y] = '#';
			break;//跳出
		}
		continue;
	}
}

//----------------------------------



//----------------------------------
// 高级电脑输入
void Hard_Computer_input(char Board[ROW][COL], int row, int col)
{
	printf("电脑落子\n");

	// 检查是否有立即获胜的走法
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '#', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// 如果没有立即获胜的走法，检查是否能阻止对手获胜
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '*', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// 如果以上两种情况都不满足，选择一个空位放置棋子
	int x, y;
	do
	{
		x = rand() % row;
		y = rand() % col;
	} while (Board[x][y] != ' ');

	Board[x][y] = '#';
}

// 辅助函数用于检测给定位置是否会导致立即获胜
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col)
{
	Board[x][y] = symbol; // 假设在这个位置放棋子

	// 检查行
	int count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && Board[x - i][y] == symbol) ++count;
		if (x + i < row && Board[x + i][y] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查列
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (y - i >= 0 && Board[x][y - i] == symbol) ++count;
		if (y + i < col && Board[x][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查对角线
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y - i >= 0 && Board[x - i][y - i] == symbol) ++count;
		if (x + i < row && y + i < col && Board[x + i][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// 检查反向对角线
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y + i < col && Board[x - i][y + i] == symbol) ++count;
		if (x + i < row && y - i >= 0 && Board[x + i][y - i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	Board[x][y] = ' '; // 撤销假设
	return 0;
}


//----------------------------------


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
//三子棋检测函数
//判断行，列，左对角和右对角是否有三个相同
//反馈类型有 *  #   P   C  分别表示 玩家1赢，玩家或电脑赢，平局，继续
//我是第一个想到冒泡排序的技巧
int Detection(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)  // 一行一行检测有无三个相同
	{
		for (j = 0; j < col - 2; j++)  // 列两两对比有无数据是否相同。可以少循环 2 次 1 = 2 & 2 = 3 同时相等时，行有三连
		{
			if (Board[i][j] == Board[i][j + 1] && Board[i][j + 1] == Board[i][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 列检测
	for (i = 0; i < col; i++)  // 一列一列检测有无三个相同
	{
		for (j = 0; j < row - 2; j++)  // 行两两对比有无数据是否相同。可以少循环 2 次 1 = 2 & 2 = 3 同时相等时，列有三连
		{
			if (Board[j][i] == Board[j + 1][i] && Board[j + 1][i] == Board[j + 2][i])
			{
				if (Board[j][i] == '*')
				{
					return '*';
				}
				else if (Board[j][i] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 从左上角开始向右下角的对角线检测
	for (i = 0; i < row - 2; i++)  // 控制行的起始位置
	{
		for (j = 0; j < col - 2; j++)  // 控制列的起始位置
		{
			if (Board[i][j] == Board[i + 1][j + 1] && Board[i + 1][j + 1] == Board[i + 2][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// 从右上角开始向左下角的对角线检测
	for (i = 0; i < row - 2; i++)  // 控制行的起始位置
	{
		for (j = col - 1; j >= 2; j--)  // 控制列的起始位置
		{
			if (Board[i][j] == Board[i + 1][j - 1] && Board[i + 1][j - 1] == Board[i + 2][j - 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}
	// 判断是否为平局
	for (i = 0; i < row ; i++)  // 遍历每一行每一列是否不等于' '
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 'C';//有一个还是空格就返回继续
			}
		}

	}
	return 'P';//否则为平局
}
//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
//检测返回值并打印数据
int Detprintf(char Board[ROW][COL], int row, int col, int role)
{
	//检测
	switch (Detection(Board, ROW, COL))
	{
	case '*':
	{
		if (role = 1)
		{
			printf("玩家1获得胜利\n");
			return 0;
		}
		if (role = 0)
		{
			printf("玩家获得胜利\n");
			return 0;
		}
	}
	case '#':
	{
		if (role == 1)
		{
			printf("玩家2获得胜利\n");
			return 0;
		}
		if (role == 0)
		{
			printf("电脑获得胜利\n");
			return 0;
		}
	}
	case 'P':
	{
		printf("平局\n");
		return 0;
	}
	case 'C':
	{
		return 1;
	}
	}
}
//-----------------------------------------------------------------------------