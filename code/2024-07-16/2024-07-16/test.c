#define _CRT_SECURE_NO_WARNINGS




//дһ��ɨ����Ϸ
//���Լ����һЩ��չ
//����1������Ӧ���̣����������޸����̴�С
//����2��ɨ�ף�ɨ���׾�ը�������ж���Χ������
//û���׾ͼ���ɨ��ɨ���������ײ�ͣ��Ȼ����ʾ�м�����
//�ݹ�ʵ��
//������Ĺ���
//ÿ�����������������Ȼ����ʾ����
//���е��Թ���(����)
//���� (x��y,1Ϊ��ը�� 2Ϊ����)   
//����1   BOM�Ǵ��ը����   1Ϊը����  0Ϊ����
//����2   SHOW��������ʾ����ҿ��� 





#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));//�����������
	int input = 0;
	char arrBom[ROWS][COLS] = { ' '};
	char arrShow[ROWS][COLS] = { '*' };
	do
	{
		menu();
		printf("��������Ϸģʽ:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				system("cls");//����ģʽ������
				InitBoard(arrBom, arrShow, ROWS, COLS);//��ʼ������
				SetBom(arrBom, ROWS, COLS, SetBomNum);//�������
				DispalyShow(arrShow, ROW, COL);//��ʾshow����
				//DispalyBom(arrBom, ROW, COL);//��ʾbom����
				while (1)
				{
					int a = Boardinput(arrBom, arrShow, ROWS, COLS);//����
					if (a == -1)//����-1��ը�����������
					{
						DispalyBom(arrBom, ROW, COL);//��ʾbom����
						break;
					}
					int win = Win(arrBom, arrShow, ROWS, COLS);//�ж���Ӯ
					if (win == 1)
					{
						DispalyBom(arrBom, ROW, COL);//��ʾbom����
						break;
					}
					DispalyShow(arrShow, ROW, COL);//��ʾshow����
					//DispalyBom(arrBom, ROW, COL);//��ʾbom����
				}
				break;
			}
			case 2:
			{
				system("cls");//����ģʽ������
				printf("�ѿ�������ģʽ\n");
				InitBoard(arrBom, arrShow, ROWS, COLS);//��ʼ������
				SetBom(arrBom, ROWS, COLS, SetBomNum);//�������
				DispalyShow(arrShow, ROW, COL);//��ʾshow����
				DispalyBom(arrBom, ROW, COL);//��ʾbom����
				while (1)
				{
					int a = Boardinput(arrBom, arrShow, ROWS, COLS);//����
					if (a == -1)//����-1��ը�����������
					{
						DispalyBom(arrBom, ROW, COL);//��ʾbom����
						break;
					}
					int win = Win(arrBom, arrShow, ROWS, COLS);//�ж���Ӯ
					if (win == 1)
					{
						DispalyBom(arrBom, ROW, COL);//��ʾbom����
						break;
					}
					DispalyShow(arrShow, ROW, COL);//��ʾshow����
					DispalyBom(arrBom, ROW, COL);//��ʾbom����
				}
			}
			break;
		}

	} while (input);
	return 0;
}