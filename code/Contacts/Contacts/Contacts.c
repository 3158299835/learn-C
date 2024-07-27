#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
//实现一个通讯录
//存放人的信息
//人的信息有：姓名、年龄、电话、地址
// 功能：存放100个人的信息、增加联系人、
// 删除指定联系人、查找联系人、
// 修改联系人、排序、显示联系人


//菜单
void menu()
{
	printf("*****************************************\n");
	printf("*****  1. add            2. dle     *****\n");
	printf("*****  3. edit           4. search  *****\n");
	printf("*****  5. show           6. sort    *****\n");
	printf("*****************************************\n");
}

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//使用memset来设置单位字节为0
}

//添加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//满了就停
	{
		printf("联系人已满。无法添加\n");
		return;
	}
	else
	{
		//在下标为count的位置添加
		printf("请输入姓名:>");
		scanf("%s", pc->date[pc->count].name);
		printf("请输入年龄:>");
		scanf("%d", &pc->date[pc->count].age);//这里需要取地址，age是int型，其余为数组
		printf("请输入性别:>");
		scanf("%s", pc->date[pc->count].gender);
		printf("请输入电话:>");
		scanf("%s", pc->date[pc->count].phone);
		printf("请输入地址:>");
		scanf("%s", pc->date[pc->count].address);
	}
	pc->count++;
	printf("录入成功\n");

}

//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
										pc->date[i].name,
										pc->date[i].age,
										pc->date[i].gender,
										pc->date[i].phone,
										pc->date[i].address);
	}
}

int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)//如果=0就代表下标为i的结构体数组的名字与要查的一样
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc ->count == 0)
	{
		printf("通讯录中没有信息,不能删除\n");
		return;
	}
	else//输入名字来删除
	{
		printf("请输入要删除的人的名字:>");
		scanf("%s", name);
		int i = 0;

		//从0到count遍历一下，查找名字
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}

		//删除:直接让后面一位覆盖前面
		//从要覆盖的哪一位开始。i不用动
		for (i = ret; i < pc ->count - 1; i++)//这里虽然最后一位没动，但是我们又不用看它
		{
			pc->date[i] = pc->date[i + 1];
		}
		pc->count--;

		printf("删除成功\n");
	}
}


//编辑联系人
void EditContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录中没有信息,不能编辑\n");
		return;
	}
	else//输入名字来删除
	{
		//输入
		printf("请输入要编辑的人的名字:>");
		scanf("%s", name);
		int i = 0;
		//查找
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}
		printf("当前联系人信息\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
												pc->date[ret].name,
												pc->date[ret].age,
												pc->date[ret].gender,
												pc->date[ret].phone,
												pc->date[ret].address);
		//编辑
		printf("请输入修改后的姓名:>");
		scanf("%s", pc->date[ret].name);
		printf("请输入修改后的年龄:>");
		scanf("%d", &pc->date[ret].age);
		printf("请输入修改后的性别:>");
		scanf("%s", pc->date[ret].gender);
		printf("请输入修改后的电话:>");
		scanf("%s", pc->date[ret].phone);
		printf("请输入修改后的地址:>");
		scanf("%s", pc->date[ret].address);

		printf("编辑成功\n");
	}
}


//搜索联系人
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录中没有信息,不能搜索\n");
		return;
	}
	else//输入名字来删除
	{
		//输入
		printf("请输入要搜索的人的名字:>");
		scanf("%s", name);
		int i = 0;
		//查找
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("你要找的人不存在\n");
			return;
		}
		printf("搜索得到联系人信息如下：\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
												pc->date[ret].name,
												pc->date[ret].age,
												pc->date[ret].gender,
												pc->date[ret].phone,
												pc->date[ret].address);
	}
}



int cmp_peo_by_name(const void* e1, const void* e2)
{
	//对比人的信息结构体中名字元素的ascii码然后升序排序
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
	//返回大于0、小于0、等于0；
}

//通讯录升序排序
void SortContact(Contact* pc)
{
	//使用qsort来排序
	//排序数据的起始位置、元素个数、元素大小以及自定义的比较函数指针。
	qsort(pc->date, pc->count, sizeof(peoinfo), cmp_peo_by_name);
	printf("排序成功。当前为升序");
}
