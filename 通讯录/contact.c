#include "contact.h"
void checkCapacity(struct contactData* ps)
{
	if(ps->useSpace == ps->capacity)
	{
		//��������
		struct peopleData* ptr = realloc(ps->peo, (ps->capacity + 1) * sizeof(struct peopleData));
		if (ptr != NULL)
		{
			ps->peo = ptr;
			ps->capacity += 1;
			printf("��������\n");
		}
		else
			printf("����ʧ��\n");
	}
}
int findByName(struct contactData* ps, char input[nameMax])
{
	for (int i = 0;i<ps->useSpace;i++)
	{
		if (0 == strcmp(ps->peo[i].name, input))
		{
			return i;
		}
	}
	return -1;
}

//��ʼ��ͨѶ¼
void initContact(struct contactData* ps)
{
	//memset(ps->peo, 0, sizeof(ps->peo));//ͨѶ¼���ݳ�ʼ��Ϊ��
	ps->peo = (struct peopleData*)malloc(3 * sizeof(struct peopleData));//����1��struct peopleData�Ĵ�С
	if(ps->peo==NULL)
	{
		return;
	}
	ps->useSpace = 0;//ͨѶ¼��ʹ�ÿռ��С��ʼ��Ϊ��
	ps->capacity = 3;//ͨѶ¼��ʼ�ռ��СΪ
}

//�����ϵ��
void addContact(struct contactData* ps)
{
	checkCapacity(ps);
	printf("����������:");
	scanf("%s", ps->peo[ps->useSpace].name);
	printf("������绰:");
	scanf("%s", ps->peo[ps->useSpace].phoneNumber);
	printf("�������Ա�:");
	scanf("%s", ps->peo[ps->useSpace].sex);
	printf("����������:");
	scanf("%s", ps->peo[ps->useSpace].age);
	printf("�������ַ:");
	scanf("%s", ps->peo[ps->useSpace].address);
	printf("����������:");
	scanf("%s", ps->peo[ps->useSpace].birthday);
	ps->useSpace++;
	printf("��ӳɹ�\n\n");
	//if (ps->useSpace == ps->capacity)//����
	//{
	//	struct peopleData* ptr = realloc(ps->peo, sizeof(struct peopleData));
	//	if (ptr != NULL)
	//	{
	//		ps->peo = ptr;
	//		ps->capacity++;//������һ
	//	}
	//	else
	//		printf("����ʧ��");
	//}
	/*if (ps->useSpace == contactMax)
	{
		printf("��");
	}*/
	/*else
	{
		printf("����������:");
		scanf("%s", ps->peo[ps->useSpace].name);
		printf("������绰:");
		scanf("%s", ps->peo[ps->useSpace].phoneNumber);
		printf("�������Ա�:");
		scanf("%s", ps->peo[ps->useSpace].sex);
		printf("����������:");
		scanf("%s", ps->peo[ps->useSpace].age);
		printf("�������ַ:");
		scanf("%s", ps->peo[ps->useSpace].address);
		printf("����������:");
		scanf("%s", ps->peo[ps->useSpace].birthday);
		ps->useSpace++;
		printf("��ӳɹ�\n\n");
	}*/

}

//��ӡȫ����ϵ��
void printContact(struct contactData* ps)
{
	if (ps->useSpace == 0)
	{
		printf("����ϵ����Ϣ\n");
	}
	else
	{
		printf("%-10s\t%-12s\t%-3s\t%-3s\t%-50s\t%-11s\t\n","����" ,"�绰", "�Ա�" ,"����" ,"��ַ" ,"����");
		for (int i = 0; i < (ps->useSpace); i++)
		{
			printf("%-10s\t", ps->peo[i].name);
			printf("%-12s\t", ps->peo[i].phoneNumber);
			printf("%-3s\t", ps->peo[i].sex);
			printf("%-3s\t", ps->peo[i].age);
			printf("%-50s\t", ps->peo[i].address);
			printf("%-11s\t\n", ps->peo[i].birthday);
	
		}
	}
}

//ɾ����ϵ��
void deleteContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax] = "0";
	printf("��������Ҫɾ������ϵ��������");
	scanf("%s",&input);
	//����ϵ��λ��
	ret = findByName(ps, input);
		//û�ҵ�
		if(ret == -1)
		{
			printf("û�д���ϵ��\n");
		}
		//�ҵ�ɾ��
		else
		{
			int j =0;
			for (j=ret;j<ps->useSpace-1;j++)
			{
				ps->peo[j] = ps->peo[j + 1];

			}
			printf("ɾ���ɹ�\n");
			ps->useSpace--;
		}
	
}

//������ϵ��
void searchContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax];
	printf("��������Ҫ���ҵ���ϵ��������");
	scanf("%s", &input);
	//����ϵ��λ��
	ret = findByName(ps, input);
	if (ret == -1)
	{
		printf("û�д���ϵ��\n");
	}
	else
	{
		printf("�ҵ���\n");
		printf("%-10s\t%-12s\t%-3s\t%-3s\t%-50s\t%-11s\t\n", "����", "�绰", "�Ա�", "����", "��ַ", "����");
		printf("%-10s\t", ps->peo[ret].name);
		printf("%-12s\t", ps->peo[ret].phoneNumber);
		printf("%-3s\t", ps->peo[ret].sex);
		printf("%-3s\t", ps->peo[ret].age);
		printf("%-50s\t", ps->peo[ret].address);
		printf("%-11s\t\n", ps->peo[ret].birthday);
	}
}

//������Ϣ
void modifyContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax] = "0";
	printf("��������Ҫ������Ϣ����ϵ������:");
	scanf("%s", &input);
	ret = findByName(ps, input);
	if (ret == -1)
	{
		printf("û�д���ϵ��\n");

	}
	else
	{
		printf("�������µ���Ϣ");
		printf("����������:");
		scanf("%s", ps->peo[ret].name);
		printf("������绰:");
		scanf("%s", ps->peo[ret].phoneNumber);
		printf("�������Ա�:");
		scanf("%s", ps->peo[ret].sex);
		printf("����������:");
		scanf("%s", ps->peo[ret].age);
		printf("�������ַ:");
		scanf("%s", ps->peo[ret].address);
		printf("����������:");
		scanf("%s", ps->peo[ret].birthday);
		printf("���ĳɹ�\n\n");
	}
}

//������ϵ��
void sortContact(struct contactData* ps)
{

}

//�ͷ��ڴ�
void destroyContsact(struct contactData* ps) 
{
	free(ps->peo);
	ps->peo = NULL;
}

