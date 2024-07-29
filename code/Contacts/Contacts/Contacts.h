#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>
#include<errno.h>

#define MAX 100			//ͨѶ¼ ��� �洢����
#define NAME 20			//ͨѶ�� ���� ����ַ�������
#define GENDER 10		//ͨѶ¼ �Ա� ����ַ�������
#define PHONE 12		//ͨѶ¼ �绰 ����ַ�������
#define ADDRESS 20		//ͨѶ¼ ��ַ ����ַ�������
#define DEFAULT_SZ 3	//ͨѶ¼ ���� Ĭ��ֵ
#define DEFAULT_ADD 2	//ͨѶ¼ �������� Ĭ��ֵ

//�Ѳ˵���ѡ����ö��
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

//ͨѶ¼�˵�
void menu();

//����ͨѶ¼���˵���Ϣ�Ľṹ��
typedef struct peo
{
	char name[NAME];
	int age;
	char gender[GENDER];
	char phone[PHONE];
	char address[ADDRESS];
}peoinfo;


//��̬�汾
////����ͨѶ¼�Ľṹ��
//typedef struct Contact
//{
//	peoinfo date[MAX];//MAX���˵�����
//	int count;//����
//}Contact;
//��̬�汾ͨѶ¼
typedef struct Contact
{
	peoinfo* data;//MAX���˵����ݡ�����
	int count;//��ǰͨѶ¼��ϵ�˸���
	int capacity;//��ǰͨѶ¼������
}Contact;

//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

//�����ļ��е�ͨѶ¼
void LoadContact(Contact* pc);

//����ͨѶ¼
void DestructionCapacity(Contact* pc);

//����ͨѶ¼���ļ�
void SaveContacts(const Contact* pc);

//�����ϵ��
void AddContact(Contact* pc);

//��ʾ��ϵ��
void ShowContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//�༭��ϵ��
void EditContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//ͨѶ¼����
void SortContact(Contact* pc);
