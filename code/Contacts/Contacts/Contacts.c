#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
//ʵ��һ��ͨѶ¼
//����˵���Ϣ
//�˵���Ϣ�У����������䡢�绰����ַ
// ���ܣ����100���˵���Ϣ��������ϵ�ˡ�
// ɾ��ָ����ϵ�ˡ�������ϵ�ˡ�
// �޸���ϵ�ˡ�������ʾ��ϵ��


//�˵�
void menu()
{
	printf("*****************************************\n");
	printf("*****  1. add            2. dle     *****\n");
	printf("*****  3. edit           4. search  *****\n");
	printf("*****  5. show           6. sort    *****\n");
	printf("*****************************************\n");
}

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//ʹ��memset�����õ�λ�ֽ�Ϊ0
}

//�����ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//���˾�ͣ
	{
		printf("��ϵ���������޷����\n");
		return;
	}
	else
	{
		//���±�Ϊcount��λ�����
		printf("����������:>");
		scanf("%s", pc->date[pc->count].name);
		printf("����������:>");
		scanf("%d", &pc->date[pc->count].age);//������Ҫȡ��ַ��age��int�ͣ�����Ϊ����
		printf("�������Ա�:>");
		scanf("%s", pc->date[pc->count].gender);
		printf("������绰:>");
		scanf("%s", pc->date[pc->count].phone);
		printf("�������ַ:>");
		scanf("%s", pc->date[pc->count].address);
	}
	pc->count++;
	printf("¼��ɹ�\n");

}

//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		if (strcmp(name, pc->date[i].name) == 0)//���=0�ʹ����±�Ϊi�Ľṹ�������������Ҫ���һ��
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc ->count == 0)
	{
		printf("ͨѶ¼��û����Ϣ,����ɾ��\n");
		return;
	}
	else//����������ɾ��
	{
		printf("������Ҫɾ�����˵�����:>");
		scanf("%s", name);
		int i = 0;

		//��0��count����һ�£���������
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("��Ҫ�ҵ��˲�����\n");
			return;
		}

		//ɾ��:ֱ���ú���һλ����ǰ��
		//��Ҫ���ǵ���һλ��ʼ��i���ö�
		for (i = ret; i < pc ->count - 1; i++)//������Ȼ���һλû�������������ֲ��ÿ���
		{
			pc->date[i] = pc->date[i + 1];
		}
		pc->count--;

		printf("ɾ���ɹ�\n");
	}
}


//�༭��ϵ��
void EditContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("ͨѶ¼��û����Ϣ,���ܱ༭\n");
		return;
	}
	else//����������ɾ��
	{
		//����
		printf("������Ҫ�༭���˵�����:>");
		scanf("%s", name);
		int i = 0;
		//����
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("��Ҫ�ҵ��˲�����\n");
			return;
		}
		printf("��ǰ��ϵ����Ϣ\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
												pc->date[ret].name,
												pc->date[ret].age,
												pc->date[ret].gender,
												pc->date[ret].phone,
												pc->date[ret].address);
		//�༭
		printf("�������޸ĺ������:>");
		scanf("%s", pc->date[ret].name);
		printf("�������޸ĺ������:>");
		scanf("%d", &pc->date[ret].age);
		printf("�������޸ĺ���Ա�:>");
		scanf("%s", pc->date[ret].gender);
		printf("�������޸ĺ�ĵ绰:>");
		scanf("%s", pc->date[ret].phone);
		printf("�������޸ĺ�ĵ�ַ:>");
		scanf("%s", pc->date[ret].address);

		printf("�༭�ɹ�\n");
	}
}


//������ϵ��
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("ͨѶ¼��û����Ϣ,��������\n");
		return;
	}
	else//����������ɾ��
	{
		//����
		printf("������Ҫ�������˵�����:>");
		scanf("%s", name);
		int i = 0;
		//����
		int ret = FindByName(pc, name);
		if (ret == -1)
		{
			printf("��Ҫ�ҵ��˲�����\n");
			return;
		}
		printf("�����õ���ϵ����Ϣ���£�\n");
		printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	//�Ա��˵���Ϣ�ṹ��������Ԫ�ص�ascii��Ȼ����������
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
	//���ش���0��С��0������0��
}

//ͨѶ¼��������
void SortContact(Contact* pc)
{
	//ʹ��qsort������
	//�������ݵ���ʼλ�á�Ԫ�ظ�����Ԫ�ش�С�Լ��Զ���ıȽϺ���ָ�롣
	qsort(pc->date, pc->count, sizeof(peoinfo), cmp_peo_by_name);
	printf("����ɹ�����ǰΪ����");
}
