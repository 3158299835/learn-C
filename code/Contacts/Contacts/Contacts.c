#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
//ʵ��һ��ͨѶ¼
//����˵���Ϣ
//�˵���Ϣ�У����������䡢�绰����ַ
// ���ܣ����100���˵���Ϣ��������ϵ�ˡ�
// ɾ��ָ����ϵ�ˡ�������ϵ�ˡ�
// �޸���ϵ�ˡ�������ʾ��ϵ��
//ʹ��ö�٣��г�ѡ���
//ʹ��realloc��ʵ�ֶ�̬�����ڴ�


////��̬�汾
////�����ϵ��
//void AddContact(Contact* pc)
//{
// 
//	assert(pc);
//	if (pc->count == MAX)//���˾�ͣ
//	{
//		printf("��ϵ���������޷����\n");
//		return;
//	}
//	else
//	{
//		//���±�Ϊcount��λ�����
//		printf("����������:>");
//		scanf("%s", pc->date[pc->count].name);
//		printf("����������:>");
//		scanf("%d", &pc->date[pc->count].age);//������Ҫȡ��ַ��age��int�ͣ�����Ϊ����
//		printf("�������Ա�:>");
//		scanf("%s", pc->date[pc->count].gender);
//		printf("������绰:>");
//		scanf("%s", pc->date[pc->count].phone);
//		printf("�������ַ:>");
//		scanf("%s", pc->date[pc->count].address);
//	}
//	pc->count++;
//	printf("¼��ɹ�\n");
//
//}

//��̬�汾
//���ݺ���
void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)//��ϵ��=����
	{
		//����ʼλֵΪdata�ĵ�ַ��������DEFAULT_ADD��sizeof(peoinfo)��С���ڴ�ռ�
		//��¼��ϵ�˵���Ϣ������ֵ��peoinfo���͵�.
		peoinfo* ptr = (peoinfo*)realloc(pc->data, (pc->capacity + DEFAULT_ADD) * sizeof(peoinfo));
		if (ptr != NULL)
		{
			//�����ؿ�ָ��Ű�ԭ���ĵ�ַ��ֵ�����ܻ����µĵ�ַ
			pc->data = ptr;
			//�����ٳɹ��󣬰���������+DEFAULT_ADD.
			pc->capacity += DEFAULT_ADD;
		}
		else//������ڿ�ָ���򱨴�
		{
			//��ǰ�����ǰ׺��������֪�������ﱨ���ˡ�
			printf("AddContact:%s\n", strerror(errno));
			return;//������˳�
		}
		printf("���ݳɹ�����ǰ����Ϊ%d����ǰ��ϵ�˸���Ϊ%d\n", pc->capacity, pc->count);
	}
}




//�˵�
void menu()
{
	printf("*****************************************\n");
	printf("*****  1. add            2. dle     *****\n");
	printf("*****  3. edit           4. search  *****\n");
	printf("*****  5. show           6. sort    *****\n");
	printf("*****  0. exit                      *****\n");
	printf("*****************************************\n");
}

//��̬�İ汾
////��ʼ��ͨѶ¼
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));//ʹ��memset�����õ�λ�ֽ�Ϊ0
//}
//��̬�İ汾
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	//��dataָ���¿��ٳ����Ŀռ�
	//���������ռ�,ÿ���ռ�Ĵ�С���˵���Ϣ�Ľṹ����ռ�ڴ��С
	//calloc��������ڴ�ռ��ʼ��Ϊ0
	pc->data = calloc(DEFAULT_SZ, sizeof(peoinfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;//������Ĭ��ֵ������

	printf("�ѳ�ʼ��Ŀ¼\n");
	//�����ļ���Ϣ��ͨѶ¼
	LoadContact(pc);
	printf("�Ѽ����ļ�\n");

	return 0;
}

void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("Contacts.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	//���ļ�
	peoinfo tmp = { 0 };
	//���û����������ֹͣ
	while (fread(&tmp, sizeof(peoinfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);//����Ƿ���Ҫ����
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//����ͨѶ¼
void SaveContacts(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("Contacts.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContacts");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->count ; i++)
	{
		fwrite(pc->data + i, sizeof(peoinfo), 1, pfWrite);
	}
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;

}


//����ͨѶ¼
void DestructionCapacity(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	printf("ͨѶ¼������\n");
}



//�����ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	//����Ƿ�Ҫ����
	CheckCapacity(pc);
	//���±�Ϊcount��λ�����
	printf("����������:>");
	scanf("%s", pc->data[pc->count].name);
	printf("����������:>");
	scanf("%d", &pc->data[pc->count].age);//������Ҫȡ��ַ��age��int�ͣ�����Ϊ����
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->count].gender);
	printf("������绰:>");
	scanf("%s", pc->data[pc->count].phone);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->count].address);

	pc->count++;
	printf("¼��ɹ�\n");

}

//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼��û����ϵ��\n");
		return;
	}
	int i = 0;
	printf("��ǰ��ϵ����Ϣ:\n");
	printf("%-20s\t%-10s\t%-10s%-12s%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-10d\t%-10s%-12s%-20s\n",
										pc->data[i].name,
										pc->data[i].age,
										pc->data[i].gender,
										pc->data[i].phone,
										pc->data[i].address);
	}
	printf("��ǰ����Ϊ%d����ǰ��ϵ�˸���Ϊ%d\n", pc->capacity, pc->count);
}

int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)//���=0�ʹ����±�Ϊi�Ľṹ�������������Ҫ���һ��
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
			pc->data[i] = pc->data[i + 1];
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
		ShowContact(pc);
		//�༭
		printf("�������޸ĺ������:>");
		scanf("%s", pc->data[ret].name);
		printf("�������޸ĺ������:>");
		scanf("%d", &pc->data[ret].age);
		printf("�������޸ĺ���Ա�:>");
		scanf("%s", pc->data[ret].gender);
		printf("�������޸ĺ�ĵ绰:>");
		scanf("%s", pc->data[ret].phone);
		printf("�������޸ĺ�ĵ�ַ:>");
		scanf("%s", pc->data[ret].address);

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
												pc->data[ret].name,
												pc->data[ret].age,
												pc->data[ret].gender,
												pc->data[ret].phone,
												pc->data[ret].address);
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
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼��û����ϵ�ˣ���������\n");
		return;
	}
	//ʹ��qsort������
	//�������ݵ���ʼλ�á�Ԫ�ظ�����Ԫ�ش�С�Լ��Զ���ıȽϺ���ָ�롣
	qsort(pc->data, pc->count, sizeof(peoinfo), cmp_peo_by_name);
	printf("����ɹ�����ǰΪ����\n");
}
