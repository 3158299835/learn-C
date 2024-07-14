#pragma once

//包含必要头文件
#include <stdio.h>
#include <stdlib.h>//随机头文件
//宏定义
#define ROW 10  //定义行为3。为了以后能更好的修改参数
#define COL 10 //定义列为3

//打印游戏菜单
void menu();

//进入游戏
int game(int a);

//初始化棋盘
void InitBoard(char Board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char Board[ROW][COL], int row, int col);

//玩家1输入
void Player1_input(char Board[ROW][COL], int row, int col);

//玩家2输入
void Player2_input(char Board[ROW][COL], int row, int col);

//easy电脑输入
void Easy_Computer_input(char Board[ROW][COL], int row, int col);

//hard电脑输入
void Hard_Computer_input(char Board[ROW][COL], int row, int col);
// 辅助函数用于检测给定位置是否会导致立即获胜
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col);

//检测输赢或继续或平局
int Detection(char Board[ROW][COL], int row, int col);

//根据检测值打印
int Detprintf(char Board[ROW][COL], int row, int col,int role);
