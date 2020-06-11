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
	printf("*************��ӭʹ���ֻ�ͨѶ¼************");
	printf("\n");
	
	while (t!=7)
	{
		Menu();
		printf("\n");
		printf("���������ѡ��:");
		scanf("%d",&t);
		printf("\n");
		
		if (t == 0)
		{
			printf("¼�뼸����Ϣ:");
			scanf("%d",&a);
			printf("\n");
			Get(stu,a);
			printf("\n");
		}
		else if (t == 1)
		{
			printf("������������ϵ�˵ĸ���:");
			scanf("%d",&n);
			printf("\n");
			Add(stu,n);
			printf("\n");
			
			printf("���������ϵ��:\n");
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
			printf("������ĸ��˳����ʾ��������Ϣ:\n");
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
			printf("*************��ӭ�˳��ֻ�ͨѶ¼************");
			printf("\n");	
		}
		
	}
	
	return 0;
}

void Menu()//���˵� 
{
	printf("****************0.��Ϣ¼��*****************");
	printf("\n");
	printf("****************1.������ϵ��***************");
	printf("\n");
	printf("****************2.ɾ����ϵ��***************");
	printf("\n");
	printf("****************3.�޸���ϵ��***************");
	printf("\n");
	printf("***************4.���������Ϣ**************");
	printf("\n");
	printf("*************5.����������ʾ��Ϣ************");
	printf("\n");
	printf("*************6.����ͨѶ¼�ļ�**************");
	printf("\n");
	printf("*************7.�˳��ֻ�ͨѶ¼**************");
	printf("\n");
}

void Choose()//ѡ��˵� 
{	
	printf("****************1.�������-���� *****************");
	printf("\n");
	printf("****************2.�������-ְ�� *****************");
	printf("\n");
	printf("**************3.�������-�绰���� ***************");
	printf("\n");
	printf("****************4.�������-Email *****************");
	printf("\n");
	
}

 void Create()//�����ļ� 
{
	char ask;
	int flag = 1;
	FILE *fp;
	
	if ((fp=fopen("address.txt","rb")) != NULL)
	{
		fclose(fp);
		printf("ͨѶ¼�ļ��Ѿ����ڣ�Ҫ����ؽ���?");
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
		printf("�ļ��ɹ������������������");
		printf("\n");
		getchar();
	}
}

void Find(struct Information stu[100],struct Information std[100])//������ʾ������Ϣ 
{
	int i;
	int b;

	for (i=0;i<4;i++)
	{
		Choose();
		printf("\n");
		printf("���������ѡ��:");
		scanf("%d",&b);
		
		if (b == 1)
		{
			printf("\n");
			printf("������ʾ-����:\n");
			Print1(stu,std);
			printf("\n");
		}
		else if (b == 2)
		{
			printf("\n");
			printf("������ʾ-ְ��:\n");
			Print2(stu,std);
			printf("\n");
		}
		else if (b == 3)
		{
			printf("\n");
			printf("������ʾ-�绰����:\n");
			Print3(stu,std);
			printf("\n");
		}
		else
		{
			printf("\n");
			printf("������ʾ-Email:\n");
			Print4(stu,std);
			printf("\n");
		}
		printf("\n");
	}
		
}

void Get(struct Information stu[100],int n)//¼����ϵ�� 
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
		printf("����:");
		scanf("%s",stu[i].m_strName);
		printf("ְ��:");
		scanf("%s",stu[i].m_strJob);
		printf("�绰����:");
		scanf("%s",stu[i].m_strPhonenumber);
		printf("Email:");
		scanf("%s",stu[i].m_strEmail);
		printf("\n");
	}
	
	printf("��������˵Ļ�����Ϣ:");
	printf("\n");
	printf("\n");
	printf("����:	   ְ��:    	�绰����:   	 Email:");
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

void Add(struct Information stu[100],int n)//������ϵ�� 
{
	int i;
	
	stu[99].m_nA = stu[99].m_nA + n;
				
	for (i=(stu[99].m_nA - n); i<stu[99].m_nA; i++)
	{
		printf("����:");
		scanf("%s",stu[i].m_strName);
		printf("ְ��:");
		scanf("%s",stu[i].m_strJob);
		printf("�绰����:");
		scanf("%s",stu[i].m_strPhonenumber);
		printf("Email:");
		scanf("%s",stu[i].m_strEmail);
		printf("\n");
	}
	
}

void Input(struct Information stu[100])//���������ϵ�� 
{
	int i;
	printf("\n");
	
	printf("����:	   ְ��:    	�绰����:   	 Email:");
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

void Delete(struct Information stu[100])//ɾ����ϵ�� 
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
	
	printf("������Ҫɾ������ϵ�˵�����:");
	scanf("%s",name);
	printf("\n");
	
	for (i=0; i<stu[99].m_nA; i++)
	{
		if (strcmp(stu[i].m_strName,name) == 0)
		{
			x = i;
			printf("ɾ���ɹ�! \n");
	
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
	printf("����:	   ְ��:    	�绰����:   	 Email:");
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

void Amend(struct Information stu[100])//�޸���ϵ��
{
	int i;
	char name[10];
	
	printf("������Ҫ�޸ĵ���ϵ�˵�����:");
	scanf("%s",name);
	printf("\n");
					
	for (i=0; i<stu[99].m_nA; i++)
	{
		if (strcmp(stu[i].m_strName,name) == 0)
		{
			printf("�������滻������:");
			scanf("%s",stu[i].m_strName);
			printf("�������滻��ְ��:");
			scanf("%s",stu[i].m_strJob);
			printf("�������滻�ĵ绰����:");
			scanf("%s",stu[i].m_strPhonenumber);
			printf("�������滻��Email:");
			scanf("%s",stu[i].m_strEmail);
		} 
	}
	
	printf("\n");
	printf("����:	   ְ��:    	�绰����:   	 Email:");
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

int Print(struct Information stu[100],struct Information std[100])//������� 
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

void Print1(struct Information stu[100],struct Information std[100])//�������  ���� 
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

void Print2(struct Information stu[100],struct Information std[100])//�������ְ�� 
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

void Print3(struct Information stu[100],struct Information std[100])//����绰���� 
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

void Print4(struct Information stu[100],struct Information std[100])//������ʾEmail 
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

void Sort(struct Information stu[100],struct Information temp[100])//���� 
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
	printf("����:	   ְ��:    	�绰����:   	 Email:");
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

