#define _CRT_SECURE_NO_WARNINGS

#include "3ziqi_game.h"


//---------------------------------------
//三子棋
//---------------------------------------


int main()
{
	srand((unsigned int)time(NULL));//设置随机种子
	int input = 0;
	do
	{
		//打印菜单
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 0:
			{
				break;//退出游戏
			}
			case 1: 
			{
				game(1);//玩家对战
				break;//退出游戏
			}
			case 2:
			{
				game(2);//简单电脑对战
				break;//退出游戏
			}
			case 3:
			{
				game(3);//困难电脑对战
				break;//退出游戏
			}
			default:
			{
				printf("输入错误，请重新输入\n");
			}
		}
	} while (input);//input = 0 结束游戏

	return 0;
}
