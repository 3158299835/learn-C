#define _CRT_SECURE_NO_WARNINGS


//定义棋盘大小
#define ROW 9
#define COL 9
//定义棋盘外围一圈大小
#define ROWS ROW+2
#define COLS COL+2

#include <stdio.h>

//菜单
void menu();

//初始化棋盘
void InitBoard(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);

//显示show棋盘
void DispalyShow(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int row, int col);
