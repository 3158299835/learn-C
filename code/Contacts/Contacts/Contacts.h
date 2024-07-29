#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>
#include<errno.h>

#define MAX 100			//通讯录 最大 存储人数
#define NAME 20			//通讯里 姓名 最大字符串长度
#define GENDER 10		//通讯录 性别 最大字符串长度
#define PHONE 12		//通讯录 电话 最大字符串长度
#define ADDRESS 20		//通讯录 地址 最大字符串长度
#define DEFAULT_SZ 3	//通讯录 容量 默认值
#define DEFAULT_ADD 2	//通讯录 增加容量 默认值

//把菜单的选项用枚举
enum Options
{
    EXIT,
    ADD,
    DLE,
    EDIT,
    SEARCH,
    SHOW,
    SORT
};

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


//静态版本
////定义通讯录的结构体
//typedef struct Contact
//{
//	peoinfo date[MAX];//MAX个人的数据
//	int count;//计数
//}Contact;
//动态版本通讯录
typedef struct Contact
{
	peoinfo* data;//MAX个人的数据。方便
	int count;//当前通讯录联系人个数
	int capacity;//当前通讯录的容量
}Contact;

//初始化通讯录
int InitContact(Contact* pc);

//加载文件中的通讯录
void LoadContact(Contact* pc);

//销毁通讯录
void DestructionCapacity(Contact* pc);

//保存通讯录到文件
void SaveContacts(const Contact* pc);

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
