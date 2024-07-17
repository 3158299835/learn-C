#define _CRT_SECURE_NO_WARNINGS


//定义棋盘大小
#define ROW 9
#define COL 9
//定义棋盘外围一圈大小
#define ROWS ROW+2
#define COLS COL+2

//定义埋雷数量
#define SetBomNum 10
#include <stdio.h>
#include <windows.h>//清屏所用头文件
#include <stdlib.h> //随机函数头文件
#include <time.h>//时间头文件
//菜单
void menu();

//初始化棋盘
void InitBoard(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);

//显示show棋盘
void DispalyShow(char arrShow[ROWS][COLS], int row, int col);

//显示Bom棋盘
void DispalyBom(char arrBom[ROWS][COLS], int row, int col);

//随机埋雷
void SetBom(char arrBom[ROWS][COLS], int row, int col, int num);

//输入坐标值，插旗或者查炸弹
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);
//递归查找炸弹
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols ,int x, int y);


int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);