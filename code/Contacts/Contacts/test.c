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
		case ADD://add��ϵ��
			system("cls");
			AddContact(&con);
			break;
		case DLE://ɾ����ϵ��
			system("cls");
			DelContact(&con);
			break;
		case EDIT://�༭��ϵ��
			system("cls");
			EditContact(&con);
			break;
		case SEARCH://������ϵ��
			system("cls");
			SearchContact(&con);
			break;
		case SHOW://��ʾͨѶ¼
			system("cls");
			ShowContact(&con);
			break;
		case SORT://ͨѶ¼������������
			system("cls");
			SortContact(&con);
			break;
		case EXIT:
			system("cls");
			SaveContacts(&con);
			printf("�ѱ���ͨѶ¼\n");
			DestructionCapacity(&con);
			printf("���˳�ͨѶ¼\n");
			break;
		default:
			system("cls");
			printf("�����������������\n");
			break;
		}

	} while (input);

	return 0;
}