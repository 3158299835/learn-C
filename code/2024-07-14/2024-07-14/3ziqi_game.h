#pragma once

//������Ҫͷ�ļ�
#include <stdio.h>
#include <stdlib.h>//���ͷ�ļ�
//�궨��
#define ROW 10  //������Ϊ3��Ϊ���Ժ��ܸ��õ��޸Ĳ���
#define COL 10 //������Ϊ3

//��ӡ��Ϸ�˵�
void menu();

//������Ϸ
int game(int a);

//��ʼ������
void InitBoard(char Board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char Board[ROW][COL], int row, int col);

//���1����
void Player1_input(char Board[ROW][COL], int row, int col);

//���2����
void Player2_input(char Board[ROW][COL], int row, int col);

//easy��������
void Easy_Computer_input(char Board[ROW][COL], int row, int col);

//hard��������
void Hard_Computer_input(char Board[ROW][COL], int row, int col);
// �����������ڼ�����λ���Ƿ�ᵼ��������ʤ
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col);

//�����Ӯ�������ƽ��
int Detection(char Board[ROW][COL], int row, int col);

//���ݼ��ֵ��ӡ
int Detprintf(char Board[ROW][COL], int row, int col,int role);
