#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//菜单
void menu()
{
	printf("*******************************************\n");
	printf("*****           0.退出游戏            *****\n");
	printf("*****           1.开始游戏            *****\n");
	printf("*****         2.开启透视模式          *****\n");
	printf("*****         3.游戏操作指南          *****\n");
	printf("*******************************************\n");
}


//初始化棋盘
//把两个棋盘都赋值为0  或者   '*'
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

//打印用户棋盘
void DispalyShow(char arrShow[ROWS][COLS], int row, int col)//显示show棋盘
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

//打印作弊棋盘
void DispalyBom(char arrBom[ROWS][COLS], int row, int col)//显示show棋盘
{
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
	for (j = 0; j < col; j++)
	{
		printf("|---");
	}
	printf("|\n");

	for (i = 0; i < row; i++)
	{

		printf(" %d ", i + 1);//打印行坐标
		for (j = 0; j < col; j++)
		{
			printf("| %c ", arrBom[i + 1][j + 1]);
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


//随机埋雷
void SetBom(char arrBom[ROWS][COLS], int rows, int cols, int num)
{
	int x = 0;
	int y = 0;
	int count = num;//定义雷的数量
	while (count)//一直埋雷，直到够数
	{
		x = rand() % (rows - 2) + 1;  //x范围是1 -  rows-2
		y = rand() % (rows - 2) + 1;  //y范围是1 -  rows-2
		//这个地方必须不是字符!才能埋雷
		if (arrBom[x][y] != '!')
		{
			arrBom[x][y] = '!';
			count--;
		}
	}
}

//输入坐标值，插旗或者查炸弹
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
//输入坐标值，插旗或者查炸弹
//插旗好弄，主要是查炸弹
//需要用到递归，思考一下怎么弄
//如果周围炸弹为0，则继续查周围八个格子是否有炸弹。有则继续递归。直到Show棋盘的字符为非0才行
//还要注意递归的范围不能超过范围，所以直接传送过来大棋盘。+2的
//字符0的ASCII码为48
// 查雷则显示附近的雷的数量。插旗则显示@，插旗后再插就是取消插旗
	int x = 0;
	int y = 0;
	int n = 0;
	printf("请输入坐标及操作:>");
	scanf("%d %d %d", &x, &y, &n);
	system("cls");//输入坐标后清屏
	if (1 <= x && x <= rows && 1 <= y && y <= cols && (n == 1 || n == 2))//判断坐标是否符合范围
	{
		if (n == 2)//旗部分
		{
			if (arrShow[x][y] == '*')//如果为*则插旗，如果为@则变为*，如果为数字0-8.则不能插旗 48 +8 = 56
			{
				printf("插旗成功，坐标为%d %d\n", x, y);
				arrShow[x][y] = '@';
			}
			else if (arrShow[x][y] == '@')
			{
				printf("取旗成功，坐标为%d %d\n", x, y);
				arrShow[x][y] = '*';
			}
			else if (48 <= arrShow[x][y] && arrShow[x][y] <= 56)//字符转ASCII码
			{
				printf("这个地方查过了，换一个地方插旗吧\n");
			}
		}
		if (n == 1)//炸弹部分  把坐标传过去，并且还要两个数组以及大棋盘的长和宽
		{
			if (arrBom[x][y] == '!')//被雷炸死了
			{
				printf("你被雷炸死了\n");
				return -1;
			}
			else
			{
				FindBom(arrBom, arrShow, rows, cols, x, y);//递归查找函数
			}
		}
	}
	else
	{
		printf("格式错误！\n");
		printf("格式为：行号 列号 1或2\n");
		printf("1为查雷，2为插旗\n");
	}
}

//递归查找函数
//停止条件：周围的炸弹和>=1
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols, int x, int y)
{
//查坐标周围八个的和是不是0 ，否则继续向八个坐标递归,并且把当前的坐标替换为他们的和
//因为是字符，' '的ascii是38     雷'！'的ascii是39  

// x-1,y-1   x-1,y     x-1,y+1
// x,y-1      x,y      x,y+1
// x+1,y-1   x+1,y     x+1,y+1

//如果查到的x y坐标为大棋盘的边界坐标，那么就停止查找
	if (x == 0 || x == rows || y == 0 || y == cols)
	{
		return;//停止
	}
	// 如果该单元格已经被揭露，则不再处理
	if (arrShow[x][y] == ' ') 
	{
		return;
	}
	//计算雷的个数
	int count = (arrBom[x - 1][y - 1] +
		arrBom[x - 1][y] +
		arrBom[x - 1][y + 1] +
		arrBom[x][y - 1] +
		arrBom[x][y + 1] +
		arrBom[x + 1][y - 1] +
		arrBom[x + 1][y] +
		arrBom[x + 1][y + 1]) - (8 * ' ');
	if (count != 0)//则有炸弹,显示炸弹个数
	{
		arrShow[x][y] = '0' + count;//注意show是字符，所以应该+ '0'
	}
	else//当前位置为0 则继续向下递归，并且把当前的字符换为' '
	{
		arrShow[x][y] = ' ';
		FindBom(arrBom, arrShow, rows, cols, x - 1, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x - 1, y);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x - 1, y + 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x, y + 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y - 1);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y);//递归继续查找
		FindBom(arrBom, arrShow, rows, cols, x + 1, y + 1);//递归继续查找
	}
}

//判断输赢
int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols)
{
	//如果show棋盘的*等于bom棋盘的!就代表剩下的都是雷，则胜利
	int showbom = 0;
	int bom = 0;

	int i = 0;
	int j = 0;
	//计算arrbom中的!
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
	if (showbom == bom)//则胜利
	{
		printf("你赢了\n");
		return 1;
	}
}