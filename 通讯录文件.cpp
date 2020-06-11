#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Information
{
	char m_strName[10];
	char m_strJob[10];
	char m_strPhonenumber[11];
	char m_strEmail[20];
	int m_nA;
};

void Menu();
void Create();
void Find(struct Information stu[100],struct Information std[100]);
void Choose();
void Get(struct Information stu[100],int n);
void Add(struct Information stu[100],int n);
void Input(struct Information stu[100]);
void Delete(struct Information stu[100]);
void Amend(struct Information stu[100]);
int Print(struct Information stu[100],struct Information std[100]);
void Print1(struct Information stu[100],struct Information std[100]);
void Print2(struct Information stu[100],struct Information std[100]);
void Print3(struct Information stu[100],struct Information std[100]);
void Print4(struct Information stu[100],struct Information std[100]);
void Sort(struct Information stu[100],struct Information temp[100]);
void Inputed(struct Information stu[100],struct Information temp[100]);

int main()
{
	int n;
	int t;
	int a;
	int m = 0;
	
	struct Information stu[100];
	struct Information std[100];
	struct Information temp[100];
	
	stu[99].m_nA = 0;
	printf("*************欢迎使用手机通讯录************");
	printf("\n");
	
	while (t!=7)
	{
		Menu();
		printf("\n");
		printf("请输入你的选项:");
		scanf("%d",&t);
		printf("\n");
		
		if (t == 0)
		{
			printf("录入几人信息:");
			scanf("%d",&a);
			printf("\n");
			Get(stu,a);
			printf("\n");
		}
		else if (t == 1)
		{
			printf("请输入增加联系人的个数:");
			scanf("%d",&n);
			printf("\n");
			Add(stu,n);
			printf("\n");
			
			printf("输出所有联系人:\n");
			Input(stu);
			printf("\n");
		}
		else if (t == 2)
		{	
			Delete(stu);
			printf("\n");
		}
		else if (t == 3)
		{
			Amend(stu);
			printf("\n");
		}
		else if (t == 4)
		{
			Print(stu,std);
			if (m == 0)
			{
				Find(stu,std);
			}
			else 
			{
				printf("Error!");
				printf("\n");
			}
		}
		else if (t == 5)
		{
			printf("按照字母表顺序显示出所有信息:\n");
			Sort(stu,temp);
			Inputed(stu,temp);
			printf("\n");
		}
		else if (t == 6)
		{
			Create();
			printf("\n");
		}
		else
		{
			printf("*************欢迎退出手机通讯录************");
			printf("\n");	
		}
		
	}
	
	return 0;
}

void Menu()//主菜单 
{
	printf("****************0.信息录入*****************");
	printf("\n");
	printf("****************1.增加联系人***************");
	printf("\n");
	printf("****************2.删除联系人***************");
	printf("\n");
	printf("****************3.修改联系人***************");
	printf("\n");
	printf("***************4.分类查找信息**************");
	printf("\n");
	printf("*************5.姓名排序显示信息************");
	printf("\n");
	printf("*************6.建立通讯录文件**************");
	printf("\n");
	printf("*************7.退出手机通讯录**************");
	printf("\n");
}

void Choose()//选择菜单 
{	
	printf("****************1.分类查找-姓名 *****************");
	printf("\n");
	printf("****************2.分类查找-职务 *****************");
	printf("\n");
	printf("**************3.分类查找-电话号码 ***************");
	printf("\n");
	printf("****************4.分类查找-Email *****************");
	printf("\n");
	
}

 void Create()//建立文件 
{
	char ask;
	int flag = 1;
	FILE *fp;
	
	if ((fp=fopen("address.txt","rb")) != NULL)
	{
		fclose(fp);
		printf("通讯录文件已经存在，要清楚重建吗?");
		printf("\n");
		
		ask = getchar();
		getchar();
		
		if (ask!='y'&&ask!='Y')
		{
			flag = 0;
		}
	}
	if(flag)
	{
		fp=fopen("address.tx1","wb");
		
		if(fp=NULL)
		{
			printf("can't open file!");
			printf("\n");
			exit(1);
		}
		
		fclose(fp);
		printf("文件成功建立！按任意键继续");
		printf("\n");
		getchar();
	}
}

void Find(struct Information stu[100],struct Information std[100])//分类显示各项信息 
{
	int i;
	int b;

	for (i=0;i<4;i++)
	{
		Choose();
		printf("\n");
		printf("请输入你的选项:");
		scanf("%d",&b);
		
		if (b == 1)
		{
			printf("\n");
			printf("分类显示-姓名:\n");
			Print1(stu,std);
			printf("\n");
		}
		else if (b == 2)
		{
			printf("\n");
			printf("分类显示-职务:\n");
			Print2(stu,std);
			printf("\n");
		}
		else if (b == 3)
		{
			printf("\n");
			printf("分类显示-电话号码:\n");
			Print3(stu,std);
			printf("\n");
		}
		else
		{
			printf("\n");
			printf("分类显示-Email:\n");
			Print4(stu,std);
			printf("\n");
		}
		printf("\n");
	}
		
}

void Get(struct Information stu[100],int n)//录入联系人 
{
	int i;
	FILE *fp;
	
	if ((fp=fopen("address.tx1","ab")) == NULL)
	{
		printf("The file can't be opened");
		printf("\n"); 
		exit(1);
	}
	
	stu[99].m_nA = n;
	
	for (i=0; i<stu[99].m_nA; i++)               
	{	
		printf("姓名:");
		scanf("%s",stu[i].m_strName);
		printf("职务:");
		scanf("%s",stu[i].m_strJob);
		printf("电话号码:");
		scanf("%s",stu[i].m_strPhonenumber);
		printf("Email:");
		scanf("%s",stu[i].m_strEmail);
		printf("\n");
	}
	
	printf("输出所有人的基本信息:");
	printf("\n");
	printf("\n");
	printf("姓名:	   职务:    	电话号码:   	 Email:");
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s\t\t",stu[i].m_strName);
		printf("%s\t\t",stu[i].m_strJob);
		printf("%s\t\t",stu[i].m_strPhonenumber);
		printf("%s\t\t",stu[i].m_strEmail);
		printf("\n");
		printf("\n");
	}
	
	fwrite(&stu,sizeof(struct Information),1,fp);
	fclose(fp);
}

void Add(struct Information stu[100],int n)//增加联系人 
{
	int i;
	
	stu[99].m_nA = stu[99].m_nA + n;
				
	for (i=(stu[99].m_nA - n); i<stu[99].m_nA; i++)
	{
		printf("姓名:");
		scanf("%s",stu[i].m_strName);
		printf("职务:");
		scanf("%s",stu[i].m_strJob);
		printf("电话号码:");
		scanf("%s",stu[i].m_strPhonenumber);
		printf("Email:");
		scanf("%s",stu[i].m_strEmail);
		printf("\n");
	}
	
}

void Input(struct Information stu[100])//输出所有联系人 
{
	int i;
	printf("\n");
	
	printf("姓名:	   职务:    	电话号码:   	 Email:");
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s\t\t",stu[i].m_strName);
		printf("%s\t\t",stu[i].m_strJob);
		printf("%s\t\t",stu[i].m_strPhonenumber);
		printf("%s\t\t",stu[i].m_strEmail);
		printf("\n");
		printf("\n");
	}
	
}

void Delete(struct Information stu[100])//删除联系人 
{
	FILE *fp;
	int x;
	int i = 0;
	int flag = 0; 
	char name[10];
	
	if ((fp=fopen("address.tx1","rb")) == NULL)
	{
		printf("The file can't be opened");
		printf("\n");
		exit(1);
	}
	
	printf("请输入要删除的联系人的姓名:");
	scanf("%s",name);
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		if (strcmp(stu[i].m_strName,name) == 0)
		{
			x = i;
			printf("删除成功! \n");
	
			for (x=i; x<stu[99].m_nA; x++)
			{
				strcpy(stu[x].m_strName,stu[x+1].m_strName);
				strcpy(stu[x].m_strJob,stu[x+1].m_strJob);
				strcpy(stu[x].m_strPhonenumber,stu[x+1].m_strPhonenumber);
				strcpy(stu[x].m_strEmail,stu[x+1].m_strEmail);
			}
		
			stu[99].m_nA = stu[99].m_nA -1;
		}
	}
	
	printf("\n");
	printf("姓名:	   职务:    	电话号码:   	 Email:");
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s\t\t",stu[i].m_strName);
		printf("%s\t\t",stu[i].m_strJob);
		printf("%s\t\t",stu[i].m_strPhonenumber);
		printf("%s\t\t",stu[i].m_strEmail);
		printf("\n");
		printf("\n");
	}
	
	if (flag)
	{
		fp = fopen("address.tx1","wb");
		fwrite(&stu,sizeof(struct Information),1,fp);
		fclose(fp);
	}
	
}

void Amend(struct Information stu[100])//修改联系人
{
	int i;
	char name[10];
	
	printf("请输入要修改的联系人的姓名:");
	scanf("%s",name);
	printf("\n");
					
	for (i=0; i<stu[99].m_nA; i++)
	{
		if (strcmp(stu[i].m_strName,name) == 0)
		{
			printf("请输入替换的名字:");
			scanf("%s",stu[i].m_strName);
			printf("请输入替换的职务:");
			scanf("%s",stu[i].m_strJob);
			printf("请输入替换的电话号码:");
			scanf("%s",stu[i].m_strPhonenumber);
			printf("请输入替换的Email:");
			scanf("%s",stu[i].m_strEmail);
		} 
	}
	
	printf("\n");
	printf("姓名:	   职务:    	电话号码:   	 Email:");
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s\t\t",stu[i].m_strName);
		printf("%s\t\t",stu[i].m_strJob);
		printf("%s\t\t",stu[i].m_strPhonenumber);
		printf("%s\t\t",stu[i].m_strEmail);
		printf("\n");
		printf("\n");
	}
					
}

int Print(struct Information stu[100],struct Information std[100])//分类查找 
{ 
	int i;
	int t;
	int n;
	
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		if (strcmp(stu[i].m_strName,std[i].m_strName) == 0)
		{
			t = 0;
		}
		else
		{
			t = 1;
		}
	}
	
	return t;
}

void Print1(struct Information stu[100],struct Information std[100])//分类查找  姓名 
{
	int i;
	int n;
	
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s",stu[i].m_strName);
		printf(" ");
	}
	
}

void Print2(struct Information stu[100],struct Information std[100])//分类查找职务 
{
	int i;
	int n;
	
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s",stu[i].m_strJob);
		printf(" ");
	}
	
}

void Print3(struct Information stu[100],struct Information std[100])//分类电话号码 
{
	int i;
	int n;

	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s",stu[i].m_strPhonenumber);
		printf(" ");
	}
	
}

void Print4(struct Information stu[100],struct Information std[100])//分类显示Email 
{
	int i;
	int n;
	
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s",stu[i].m_strEmail);
		printf(" ");
	}
	
}

void Sort(struct Information stu[100],struct Information temp[100])//排序 
{
	int i;
	int j;
	
	printf("\n");
		
	for (i=0; i<stu[99].m_nA; i++)
	{	
		for (j=i+1; j<stu[99].m_nA; j++)
		{
			if (strcmp(stu[i].m_strName,stu[j].m_strName) > 0)
			{
				strcpy(temp[i].m_strName,stu[i].m_strName);
				strcpy(temp[i].m_strJob,stu[i].m_strJob);
				strcpy(temp[i].m_strPhonenumber,stu[i].m_strPhonenumber);
				strcpy(temp[i].m_strEmail,stu[i].m_strEmail);
				
				strcpy(stu[i].m_strName,stu[j].m_strName);
				strcpy(stu[i].m_strJob,stu[j].m_strJob);
				strcpy(stu[i].m_strPhonenumber,stu[j].m_strPhonenumber);
				strcpy(stu[i].m_strEmail,stu[j].m_strEmail);
				
				strcpy(stu[j].m_strName,temp[i].m_strName);
				strcpy(stu[j].m_strJob,temp[i].m_strJob);
				strcpy(stu[j].m_strPhonenumber,temp[i].m_strPhonenumber);
				strcpy(stu[j].m_strEmail,temp[i].m_strEmail);
			}
		}
	}
	
}

void Inputed(struct Information stu[100],struct Information temp[100])
{
	int i;
	int j;
	
	printf("\n");
	printf("姓名:	   职务:    	电话号码:   	 Email:");
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		printf("%s\t\t",stu[i].m_strName);
		printf("%s\t\t",stu[i].m_strJob);
		printf("%s\t\t",stu[i].m_strPhonenumber);
		printf("%s\t\t",stu[i].m_strEmail);
		printf("\n");
		printf("\n");	
	}
	
}

