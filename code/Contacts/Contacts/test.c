#define _CRT_SECURE_NO_WARNINGS

#include "Contacts.h"

int main()
{
	Contact con;//������һ��ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	int input = 0;
	do
	{
		menu();
		printf("�����빦��>:");	
		scanf("%d", &input);
		switch (input)
		{
		case 1://add��ϵ��
			AddContact(&con);
			break;
		case 2://ɾ����ϵ��
			DelContact(&con);
			break;
		case 3://�༭��ϵ��
			EditContact(&con);
			break;
		case 4://������ϵ��
			SearchContact(&con);
			break;
		case 5://��ʾͨѶ¼
			ShowContact(&con);
			break;
		case 6://ͨѶ¼������������
			SortContact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);

	return 0;
}