#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100		//通讯录 最大 存储人数
#define NAME 20		//通讯里 姓名 最大字符串长度
#define GENDER 10	//通讯录 性别 最大字符串长度
#define PHONE 12	//通讯录 电话 最大字符串长度
#define ADDRESS 20	//通讯录 地址 最大字符串长度

//通讯录菜单
void menu();

//定义通讯录的人的信息的结构体
typedef struct peo
{
	char name[NAME];
	int age;
	char gender[GENDER];
	char phone[PHONE];
	char address[ADDRESS];
}peoinfo;

//定义通讯录的结构体
typedef struct Contact
{
	peoinfo date[MAX];//MAX个人的数据
	int count;//计数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//编辑联系人
void EditContact(Contact* pc);

//搜索联系人
void SearchContact(Contact* pc);

//通讯录排序
void SortContact(Contact* pc);
