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
//���� (x��y,1Ϊը�� 2Ϊ����)   
//����1   BOM�Ǵ��ը����   1Ϊը����  0Ϊ����
//����2   SHOW��������ʾ����ҿ��� 





#include "game.h"

int main()
{
	int input = 0;
	int arrBom[ROWS][COLS] = { 0 };
	char arrShow[ROWS][COLS] = { '*' };
	do
	{
		menu();
		printf("��������Ϸģʽ");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				InitBoard(arrBom, arrShow, ROWS, COLS);//��ʼ������
				DispalyShow(arrBom, arrShow, ROW, COL);//��ʾshow����
			}


		}

	} while (input);



	return 0;
}