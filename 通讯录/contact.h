#define _CRT_SECURE_NO_WARNINGS 1
#define nameMax 20
#define addressMax 100
///#define contactMax 1000

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 struct peopleData //��ϵ����Ϣ�ṹ��
{
	char name [nameMax];
	char phoneNumber [12];
	char sex[5];
	char age[3];
	char address[addressMax];
	char birthday[11];
};
 struct contactData
{
	struct peopleData* peo; //��ϵ����Ϣ�ṹ������
	int useSpace;//��¼��ǰ��ʹ�ÿռ��С
	int capacity;//ͨѶ¼��ǰ�������	
};
 enum menu
 {
	 Exit,
	 add,
	 search,
	 modify,
	 delete,
	 print,
	 sort,
	 
 };
 //��������
 void initContact(struct contactData* ps);//��ʼ��ͨѶ¼
 void addContact(struct contactData* ps);//���
 void printContact(struct contactData* ps);//��ӡȫ��
 void deleteContact(struct contactData* ps);//ɾ����ϵ��
 void searchContact(struct contactData* ps);//������ϵ��
 void modifyContact(struct contactData* ps);//�޸���ϵ����Ϣ
 void sortContact(struct contactData* ps);//������ϵ��
 void destroyContsact(struct contactData* ps);//�ͷ��ڴ�

