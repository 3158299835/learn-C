#define _CRT_SECURE_NO_WARNINGS

#include "3ziqi_game.h"


//---------------------------------------
//������
//---------------------------------------


int main()
{
	srand((unsigned int)time(NULL));//�����������
	int input = 0;
	do
	{
		//��ӡ�˵�
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 0:
			{
				break;//�˳���Ϸ
			}
			case 1: 
			{
				game(1);//��Ҷ�ս
				break;//�˳���Ϸ
			}
			case 2:
			{
				game(2);//�򵥵��Զ�ս
				break;//�˳���Ϸ
			}
			case 3:
			{
				game(3);//���ѵ��Զ�ս
				break;//�˳���Ϸ
			}
			default:
			{
				printf("�����������������\n");
			}
		}
	} while (input);//input = 0 ������Ϸ

	return 0;
}
