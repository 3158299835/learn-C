#define _CRT_SECURE_NO_WARNINGS


//�������̴�С
#define ROW 9
#define COL 9
//����������ΧһȦ��С
#define ROWS ROW+2
#define COLS COL+2

#include <stdio.h>

//�˵�
void menu();

//��ʼ������
void InitBoard(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);

//��ʾshow����
void DispalyShow(int arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int row, int col);
