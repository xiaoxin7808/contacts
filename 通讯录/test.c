#include"contact.h"
 void menu()
{
	printf("__________________________________________\n");
	printf("\n");
	printf("通讯录2.0（动态内存版）\n");
	printf("\n");
	printf("1.添加联系人                2.查找联系人 \n");
	printf("\n");
	printf("3.更改信息                  4.删除联系人 \n");
	printf("\n");
	printf("5.查看全部联系人            6.排序 \n");
	printf("\n");
	printf("0.退出 \n");
	printf("__________________________________________\n");
	printf("\n");
}

int main()
{
	int input = 0;
	struct contactData con;//创建通讯
	initContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择需要使用的功能:");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addContact(&con);
			break;
		case search:
			searchContact(&con);
			break;
		case modify:
			modifyContact(&con);
			break;
		case delete:
			deleteContact(&con);
			break;
		case print:
			printContact(&con);
			break;
		case sort:
			sortContact(&con);
			break;
		case Exit:
			destroyContsact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入有误\n\n");
			break;
		}
	} while (input);
	
	return 0;
}