#include"contact.h"
 void menu()
{
	printf("__________________________________________\n");
	printf("\n");
	printf("ͨѶ¼2.0����̬�ڴ�棩\n");
	printf("\n");
	printf("1.�����ϵ��                2.������ϵ�� \n");
	printf("\n");
	printf("3.������Ϣ                  4.ɾ����ϵ�� \n");
	printf("\n");
	printf("5.�鿴ȫ����ϵ��            6.���� \n");
	printf("\n");
	printf("0.�˳� \n");
	printf("__________________________________________\n");
	printf("\n");
}

int main()
{
	int input = 0;
	struct contactData con;//����ͨѶ
	initContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ����Ҫʹ�õĹ���:");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("��������\n\n");
			break;
		}
	} while (input);
	
	return 0;
}