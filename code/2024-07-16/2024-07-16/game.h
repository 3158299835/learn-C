#define _CRT_SECURE_NO_WARNINGS


//�������̴�С
#define ROW 9
#define COL 9
//����������ΧһȦ��С
#define ROWS ROW+2
#define COLS COL+2

//������������
#define SetBomNum 10
#include <stdio.h>
#include <windows.h>//��������ͷ�ļ�
#include <stdlib.h> //�������ͷ�ļ�
#include <time.h>//ʱ��ͷ�ļ�
//�˵�
void menu();

//��ʼ������
void InitBoard(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);

//��ʾshow����
void DispalyShow(char arrShow[ROWS][COLS], int row, int col);

//��ʾBom����
void DispalyBom(char arrBom[ROWS][COLS], int row, int col);

//�������
void SetBom(char arrBom[ROWS][COLS], int row, int col, int num);

//��������ֵ��������߲�ը��
int Boardinput(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);
//�ݹ����ը��
void FindBom(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols ,int x, int y);


int Win(char arrBom[ROWS][COLS], char arrShow[ROWS][COLS], int rows, int cols);