#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100		//ͨѶ¼ ��� �洢����
#define NAME 20		//ͨѶ�� ���� ����ַ�������
#define GENDER 10	//ͨѶ¼ �Ա� ����ַ�������
#define PHONE 12	//ͨѶ¼ �绰 ����ַ�������
#define ADDRESS 20	//ͨѶ¼ ��ַ ����ַ�������

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

//����ͨѶ¼�Ľṹ��
typedef struct Contact
{
	peoinfo date[MAX];//MAX���˵�����
	int count;//����
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

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
