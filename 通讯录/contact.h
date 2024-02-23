#define _CRT_SECURE_NO_WARNINGS 1
#define nameMax 20
#define addressMax 100
///#define contactMax 1000

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 struct peopleData //联系人信息结构体
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
	struct peopleData* peo; //联系人信息结构体数组
	int useSpace;//记录当前已使用空间大小
	int capacity;//通讯录当前最大容量	
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
 //声明函数
 void initContact(struct contactData* ps);//初始化通讯录
 void addContact(struct contactData* ps);//添加
 void printContact(struct contactData* ps);//打印全部
 void deleteContact(struct contactData* ps);//删除联系人
 void searchContact(struct contactData* ps);//搜索联系人
 void modifyContact(struct contactData* ps);//修改联系人信息
 void sortContact(struct contactData* ps);//排序联系人
 void destroyContsact(struct contactData* ps);//释放内存

