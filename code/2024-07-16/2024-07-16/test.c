#define _CRT_SECURE_NO_WARNINGS




//写一个扫雷游戏
//我自己想加一些扩展
//功能1：自适应棋盘，可以随意修改棋盘大小
//功能2：扫雷，扫到雷就炸，否则判断周围有无雷
//没有雷就继续扫，扫到附近有雷才停。然后显示有几个雷
//递归实现
//带插旗的功能
//每次输入完可以清屏，然后显示画面
//具有调试功能(作弊)
//输入 (x，y,1为炸弹 2为插旗)   
//棋盘1   BOM是存放炸弹的   1为炸弹，  0为空气
//棋盘2   SHOW是用来显示给玩家看的 





#include "game.h"

int main()
{
	int input = 0;
	int arrBom[ROWS][COLS] = { 0 };
	char arrShow[ROWS][COLS] = { '*' };
	do
	{
		menu();
		printf("请输入游戏模式");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				InitBoard(arrBom, arrShow, ROWS, COLS);//初始化棋盘
				DispalyShow(arrBom, arrShow, ROW, COL);//显示show棋盘
			}


		}

	} while (input);



	return 0;
}