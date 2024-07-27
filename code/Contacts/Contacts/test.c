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
		case 1://add联系人
			AddContact(&con);
			break;
		case 2://删除联系人
			DelContact(&con);
			break;
		case 3://编辑联系人
			EditContact(&con);
			break;
		case 4://搜索联系人
			SearchContact(&con);
			break;
		case 5://显示通讯录
			ShowContact(&con);
			break;
		case 6://通讯录按照名字升序
			SortContact(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}