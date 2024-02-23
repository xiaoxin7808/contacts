#include "contact.h"
void checkCapacity(struct contactData* ps)
{
	if(ps->useSpace == ps->capacity)
	{
		//增加容量
		struct peopleData* ptr = realloc(ps->peo, (ps->capacity + 1) * sizeof(struct peopleData));
		if (ptr != NULL)
		{
			ps->peo = ptr;
			ps->capacity += 1;
			printf("容量增加\n");
		}
		else
			printf("增容失败\n");
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

//初始化通讯录
void initContact(struct contactData* ps)
{
	//memset(ps->peo, 0, sizeof(ps->peo));//通讯录内容初始化为零
	ps->peo = (struct peopleData*)malloc(3 * sizeof(struct peopleData));//开辟1个struct peopleData的大小
	if(ps->peo==NULL)
	{
		return;
	}
	ps->useSpace = 0;//通讯录已使用空间大小初始化为零
	ps->capacity = 3;//通讯录初始空间大小为
}

//添加联系人
void addContact(struct contactData* ps)
{
	checkCapacity(ps);
	printf("请输入姓名:");
	scanf("%s", ps->peo[ps->useSpace].name);
	printf("请输入电话:");
	scanf("%s", ps->peo[ps->useSpace].phoneNumber);
	printf("请输入性别:");
	scanf("%s", ps->peo[ps->useSpace].sex);
	printf("请输入年龄:");
	scanf("%s", ps->peo[ps->useSpace].age);
	printf("请输入地址:");
	scanf("%s", ps->peo[ps->useSpace].address);
	printf("请输入生日:");
	scanf("%s", ps->peo[ps->useSpace].birthday);
	ps->useSpace++;
	printf("添加成功\n\n");
	//if (ps->useSpace == ps->capacity)//扩容
	//{
	//	struct peopleData* ptr = realloc(ps->peo, sizeof(struct peopleData));
	//	if (ptr != NULL)
	//	{
	//		ps->peo = ptr;
	//		ps->capacity++;//容量加一
	//	}
	//	else
	//		printf("扩容失败");
	//}
	/*if (ps->useSpace == contactMax)
	{
		printf("满");
	}*/
	/*else
	{
		printf("请输入姓名:");
		scanf("%s", ps->peo[ps->useSpace].name);
		printf("请输入电话:");
		scanf("%s", ps->peo[ps->useSpace].phoneNumber);
		printf("请输入性别:");
		scanf("%s", ps->peo[ps->useSpace].sex);
		printf("请输入年龄:");
		scanf("%s", ps->peo[ps->useSpace].age);
		printf("请输入地址:");
		scanf("%s", ps->peo[ps->useSpace].address);
		printf("请输入生日:");
		scanf("%s", ps->peo[ps->useSpace].birthday);
		ps->useSpace++;
		printf("添加成功\n\n");
	}*/

}

//打印全部联系人
void printContact(struct contactData* ps)
{
	if (ps->useSpace == 0)
	{
		printf("无联系人信息\n");
	}
	else
	{
		printf("%-10s\t%-12s\t%-3s\t%-3s\t%-50s\t%-11s\t\n","姓名" ,"电话", "性别" ,"年龄" ,"地址" ,"生日");
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

//删除联系人
void deleteContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax] = "0";
	printf("请输入需要删除的联系人姓名：");
	scanf("%s",&input);
	//找联系人位置
	ret = findByName(ps, input);
		//没找到
		if(ret == -1)
		{
			printf("没有此联系人\n");
		}
		//找到删除
		else
		{
			int j =0;
			for (j=ret;j<ps->useSpace-1;j++)
			{
				ps->peo[j] = ps->peo[j + 1];

			}
			printf("删除成功\n");
			ps->useSpace--;
		}
	
}

//搜索联系人
void searchContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax];
	printf("请输入需要查找的联系人姓名：");
	scanf("%s", &input);
	//找联系人位置
	ret = findByName(ps, input);
	if (ret == -1)
	{
		printf("没有此联系人\n");
	}
	else
	{
		printf("找到了\n");
		printf("%-10s\t%-12s\t%-3s\t%-3s\t%-50s\t%-11s\t\n", "姓名", "电话", "性别", "年龄", "地址", "生日");
		printf("%-10s\t", ps->peo[ret].name);
		printf("%-12s\t", ps->peo[ret].phoneNumber);
		printf("%-3s\t", ps->peo[ret].sex);
		printf("%-3s\t", ps->peo[ret].age);
		printf("%-50s\t", ps->peo[ret].address);
		printf("%-11s\t\n", ps->peo[ret].birthday);
	}
}

//更改信息
void modifyContact(struct contactData* ps)
{
	int ret = 0;
	char input[nameMax] = "0";
	printf("请输入需要更改信息的联系人姓名:");
	scanf("%s", &input);
	ret = findByName(ps, input);
	if (ret == -1)
	{
		printf("没有此联系人\n");

	}
	else
	{
		printf("请输入新的信息");
		printf("请输入姓名:");
		scanf("%s", ps->peo[ret].name);
		printf("请输入电话:");
		scanf("%s", ps->peo[ret].phoneNumber);
		printf("请输入性别:");
		scanf("%s", ps->peo[ret].sex);
		printf("请输入年龄:");
		scanf("%s", ps->peo[ret].age);
		printf("请输入地址:");
		scanf("%s", ps->peo[ret].address);
		printf("请输入生日:");
		scanf("%s", ps->peo[ret].birthday);
		printf("更改成功\n\n");
	}
}

//排序联系人
void sortContact(struct contactData* ps)
{

}

//释放内存
void destroyContsact(struct contactData* ps) 
{
	free(ps->peo);
	ps->peo = NULL;
}

