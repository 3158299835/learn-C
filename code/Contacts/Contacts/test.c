#define _CRT_SECURE_NO_WARNINGS

#include "Contacts.h"


int main()
{
	Contact con;//创建了一个通讯录
	InitContact(&con);//初始化通讯录
	int input = 0;
	do
	{
		menu();
		printf("请输入功能>:");	
		scanf("%d", &input);
		switch (input)
		{
		case ADD://add联系人
			system("cls");
			AddContact(&con);
			break;
		case DLE://删除联系人
			system("cls");
			DelContact(&con);
			break;
		case EDIT://编辑联系人
			system("cls");
			EditContact(&con);
			break;
		case SEARCH://搜索联系人
			system("cls");
			SearchContact(&con);
			break;
		case SHOW://显示通讯录
			system("cls");
			ShowContact(&con);
			break;
		case SORT://通讯录按照名字升序
			system("cls");
			SortContact(&con);
			break;
		case EXIT:
			system("cls");
			SaveContacts(&con);
			printf("已保存通讯录\n");
			DestructionCapacity(&con);
			printf("已退出通讯录\n");
			break;
		default:
			system("cls");
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}