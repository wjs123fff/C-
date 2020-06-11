#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

struct Student
{
	char m_strNum[20];	
	char m_strName[20];
	double m_fEnglish;
	double m_fMath;
	double m_fComputer;
	double m_fSum;
	double m_fAve;
};

void Menu(struct Student Stu[], int n); //�ܲ˵����� 
void Menu1(struct Student Stu[], int n); //�Ӳ˵����ֱ�������ӣ�ɾ�����޸ĳɼ� 
void Menu2(struct Student Stu[],int n);//�Ӳ˵��������ֱ������ѧ��Ӣ�C���Եĵ��Ƴɼ�
void Menu3(struct Student Stu[],int n);//�Ӳ˵�3���ֱ���ѧ�ţ��������в��� 
void Menu4(struct Student Stu[],int n);//�Ӳ˵�4���ֱ���ѧ�ţ��������в�ѯ 
void Input(struct Student Stu[], int n);//¼�뺯��������ѧ����Ϣ �� 
void Nopassee (struct Student Stu[], int n);//�����������ſβ�������� 
void MathSort (struct Student Stu[], int n);//��ѧ����������Ӣ������������� 
void EnglishSort (struct Student Stu[], int n);//Ӣ������������Ӣ������������� 
void ComputerSort (struct Student Stu[], int n);//C��������������Ӣ������������� 
void TotalScore (struct Student Stu[], int n);//�ֺܷ��� 
void AveScore (struct Student Stu[], int n);//ƽ���ֺ��� 
void Search1 (struct Student Stu[],int n);//��ѯ������������ѯ�����ѧ����Ϣ(��ѧ�Ž��в��ң� 
void Search2(struct Student Stu[],int n);//��ѯ������������ѯ�����ѧ����Ϣ(���������в��ң�
int  Delete (struct Student Stu[], int n);//ɾ������ ����ΪҪ���ؼ����Ժ��������������int�� 
int Increase (struct Student Stu[], int n);//���Ӻ��� ����ΪҪ���������Ժ��������������int�� 
void Update1(struct Student Stu[], int n);//�޸ĺ�������ѧ����Ϣ�����޸� ����ΪҪ�����޸��Ժ�����ݣ�������int�� ����ѧ�Ž��в��ң� 
void Update2 (struct Student Stu[], int n);//�޸ĺ�������ѧ����Ϣ�����޸� ����ΪҪ�����޸��Ժ�����ݣ�������int�� �����������в��ң�

int main()
{	
    int n;
	 
	struct Student Stu[20];  //�����������涨��һ���ṹ�����//
	
	cout << "����ѧ��������" << endl;
	cin >>n;  
	
	Input(Stu,n);//¼�뺯��������ѧ���ɼ���¼�롣 
     
    Menu(Stu,n);//�ܲ˵�����ѧ���ɼ����л��ܡ� 
	
	return 0;	
}

void Menu(struct Student Stu[],int n)                  //�ܲ˵����� 
 {
    cout << "\n\t\t*****************ѧ������ϵͳ****************\t\t\n " << endl;	 		
	cout << "\n\t\t*******************************\n\n" << endl;
	cout << "\n\t\t1..---------------�ɼ�(����������)\n" << endl;
	cout << "\n\t\t2..---------------���Ƴɼ�\n" << endl;
	cout << "\n\t\t3.----------------�ɼ���ѯ\n" << endl;
	cout << "\n\t\t4.----------------���ϸ�\n" << endl;
	cout << "\n\t\t5.----------------��Ŀ�ܷ�\n" << endl;
	cout << "\n\t\t6-----------------��Ŀƽ����\n" << endl; 
	cout << "\n\t\t7.----------------�˳�\n" <<	endl;
	cout <<"\n\t\t***********************************************\t\n" << endl;
	
	int i;

	cout <<"please select(1--7):" << endl;
	cin >> i;
	
	if(i>0 && i<=7)
	{
			switch(i)
      {  
	    case 1:
		       system("cls");  
		       Menu1(Stu,n);//�Ӳ˵�1���������ӣ�ɾ�����޸�ѧ����Ϣ 
		    	break;
		case 2:
			   system("cls");
			   Menu2(Stu,n);//�Ӳ˵�2������ѧ���ɼ��������� 
			   Menu(Stu,n);	
			    break;
		case 3:
			   system("cls");
		       Menu4(Stu, n);//��ѯѧ����Ϣ���� 
		       Menu(Stu,n);
		       break;
		case 4:
			   system("cls");
		 	   Nopassee (Stu,n); //��ѯ������ѧ���ɼ��ĺ��� 
		 	   Menu(Stu,n);
		 	   break;
		case 5:
			   system("cls");
		       TotalScore(Stu, n);//�ֺܷ��� 
		        Menu(Stu,n);
				break;
	    case 6:
	    	   system("cls"); 
		       AveScore(Stu, n);//ƽ���ֺ��� 
			   Menu(Stu,n); 
		case 7:
		       cout <<  "Goodbay!" << endl;
		       system("pause");
		       exit(0);
			   break; 
		default :
		          cout <<"ERROR!" << endl;		          
		          break;
	   }
	}	
	else
	      cout << "ERROR!" << endl;	
	       
}

void Menu1(struct Student Stu[],int n)//�Ӳ˵�����1����ѧ���ɼ����д��� 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------����\n" << endl;
	cout << "\n\t\t2.----------------ɾ��\n" << endl;		
	cout << "\n\t\t3.----------------�޸�\n" << endl;
	cout << "\n\t\t4.----------------�������˵�\n" << endl;
	cout << "\n\t\t5.----------------�˳�\n" << endl; 
	 cout << "\n\t\t**************************\t\t\n" << endl;
	
	int i;
	cin >>i;
	
	cout <<"please select(1--5):" << endl;
	
	if(i>0 && i<=5)
	{
		switch(i)
		{
			case 1:
				   system("cls");
		    	   n = Increase(Stu,n);//���Ӻ��� 
		           Menu1(Stu,n);//�����Ӳ˵�1���Ա��������ѧ����Ϣ�Ĵ��� 
			       break;
			       
		    case 2:
		    	   system("cls");
		    	   n = Delete(Stu,n);//ɾ������ 
			        Menu1(Stu,n);		
			        break;
		    	   
		    case 3:
		    	   system("cls");
		           Menu3(Stu,n); 
		           Menu1(Stu,n);
		        	break;
		        	
		    case 4:
		    	    system("cls");
		            Menu(Stu,n);//�����ܲ˵� �����������Ĳ��� 
		        	break;
		    case 5:
		    	   cout << "Goodbay!" << endl;
		    	   system("pause");
		    	   break;
		        	
			default :
		          cout <<"ERROR!" << endl;		          
		          break;
	    }
	}
	
}

void Menu2(struct Student Stu[], int n)//���Ƴɼ�����˵� ���ֱ������ѧ��Ӣ�C���Գɼ��������� 
{
	cout << "\n\t*****************************\t\n" << endl;
	cout << "\n\t1.---------------------��ѧ�ɼ���������\n" << endl;
	cout << "\n\t2.---------------------Ӣ��ɼ���������\n" << endl;
	cout << "\n\t3.---------------------C���Գɼ���������\n" << endl;
	cout << "\n\t4.---------------------�������˵�\n" << endl;
	cout <<  "\n\t5,--------------------�˳�\n" << endl; 
	cout << "\n\t*******************************\t\n" << endl;
	
	int i;
	
	cout << "Input you the choose:" << endl;
	cin >>i;
	
	if(i>0 && i<=5)
	{
		switch(i)
		{
			case 1:
				   system("cls");
			       MathSort(Stu, n);//��ѧ���Ƴɼ��������� 
			        Menu2(Stu,n);//���ز˵�2���������в��� 
			       break;
			       
		    case 2:
		    	    system("cls");
		    	    EnglishSort(Stu,n);//Ӣ�ﵥ�Ƴɼ��������� 
		    	    Menu2(Stu,n);
		    	   break;
		    	   
		    case 3:
		    	   system("cls");
		    	   ComputerSort(Stu, n);//C���Ե��Ƴɼ��������� 
		    	   Menu2(Stu,n);
		    	   break;
		   case 4:
		   	      system("cls");
		          Menu(Stu,n);//�����ܲ˵� �����������Ĳ��� 
		          break;
		   case 5:
		   	     cout << "Goodbay!" << endl;
		   	     system("pause");
		   	     break;
		   default :
		   	        cout << "ERROR!" << endl;
		   	        break;
		}
	}
	
	else cout << "ERROR!" << endl;

}

void Menu3(struct Student Stu[],int n)//�Ӳ˵�����3����ѧ���ɼ����в��ҡ� 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------��ѧ�Ų���\n" << endl;
	cout << "\n\t\t2.----------------����������\n" << endl;		
	cout << "\n\t\t3.----------------���ز˵�1\n" << endl;
	cout << "\n\t\t4.----------------�������˵�\n" << endl;
	cout << "\n\t\t5.----------------�˳�\n" << endl;
	 cout << "\n\t\t**************************\t\t\n" << endl;
	
	int i;
	cin >>i;
	
	cout <<"please select(1--5):" << endl;
	
	if(i>0 && i<=5)
	{
		switch(i)
		{
			case 1:
				   system("cls");
		    	    Update1(Stu,n);//���Һ���1����ѧ�Ž��в��� 
		           Menu3(Stu,n);// ���Ҳ˵� 
			       break;
			       
		    case 2: 
		           system("cls");
		    	     Update2(Stu,n); //���Һ���2�����������в���  
			        Menu3(Stu,n);		
			        break;
		    	   
		    case 3:
			        system("cls"); 
		            Menu1(Stu,n);//���غ���1�����½������ӣ�ɾ�����޸ĵĺ����˵� 
		        	break;
		        	
		    case 4:
		    	    system("cls");
		            Menu(Stu,n);//�����ܲ˵� �����������Ĳ��� 
		        	break;
		    case 5:
		           cout << "Goodbay!" << endl;
				   system("pause"); 
		        	break;
		        	
			default :
		          cout <<"ERROR!" << endl;		          
		          break;
	    }
	}
	
	else  cout << "ERROR!" << endl; 
	
}

void Menu4(struct Student Stu[],int n)//�Ӳ˵�����4����ѧ���ɼ����в�ѯ�� 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------��ѧ�Ų�ѯ\n" << endl;
	cout << "\n\t\t2.----------------��������ѯ\n" << endl;		
	cout << "\n\t\t3.----------------�������˵�\n" << endl;
	cout << "\n\t\t4.----------------�˳�\n" << endl;
	 cout << "\n\t\t**************************\t\t\n" << endl;
	
	int i;
	cin >>i;
	
	cout <<"please select(1--4):" << endl;
	
	if(i>0 && i<=4)
	{
		switch(i)
		{
			case 1:
				   system("cls");
		    	   Search1(Stu, n);//���Һ���1����ѧ�Ž��в��� 
		           Menu4(Stu, n);// ���Ҳ˵� 
			       break;
			       
		    case 2:
		    	    system("cls");
		    	    Search2(Stu, n); //���Һ���2�����������в���  
			        Menu4(Stu, n);		
			        break;
		        	
		    case 3:
		    	    system("cls");
		            Menu(Stu,n);//�����ܲ˵� �����������Ĳ��� 
		        	break;
		    case 4:
		           cout << "Goodbay!" << endl; //��������˳� 
		           system("pause");
		        	break;
		        	
			default :
		          cout <<"ERROR!" << endl;		          
		          break;
	    }
	}
	
	else cout << "ERROR!" << endl;
	
	cout << "\n" << endl;
	
}

void Input(struct Student Stu[],int n)//¼�뺯��������ѧ���ɼ�¼�� 
{
	int i;//����ѧ��������¼��//

	for(i=0; i<n; i++)
     {
			  cout << "ѧ��:" << endl;		
		      cin >> Stu[i]. m_strNum;
			
			   cout << "����:" << endl;		
			   cin >> Stu[i].m_strName;				
			
			   cout << "math:" << endl;			
			   cin >> Stu[i].m_fMath;

			   cout << "English:" << endl;				
			   cin >> Stu[i].m_fEnglish;
			 			
			   cout << "computer:" << endl;			
			   cin >> Stu[i].m_fComputer;
    }
    
	 system("cls");//��������
    
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//����¼���ѧ����Ϣ����Ļ����� 
   	{
		  cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl; 

}

int  Delete(struct Student Stu[], int n)//ɾ����������ѧ����Ϣ����ɾ�� 
{
	int i, j;
	
	char number[20];
    
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//ѧ����Ϣ��ʾ 
   	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
   
		
	cout << "������ѧ�ţ�" << endl; //��ѧ�Ž��в�ѯ 
	cin >> number; 
	
	for(i=0; i<n; i++)    //Ѱ����Ҫ���ҵ�ѧ��// 
	{
		if(strcmp(Stu[i].m_strNum,number) == 0 )//���ҵ���Ҫɾ����ѧ����Ϣ 
		{
			for(j=i; j<n-1; j++) //��ΪҪɾ��һλ�����j+1��nλ����j���ֻ����n-1λ�����ѵ�nλ���� 
			{
			     
			 Stu[j] = Stu[j+1];  //������һ����¼��ǰ�ƶ�,�����ǡ� 
			 
			              
		    } 
		          
	    }		
	
	}
	
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n-1; i++)//��Ϊɾ����һλ������������������һλ�� ����ɾ�����ѧ����Ϣ��� 
   	{  
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
	return(n-1);//���ؼ��ٺ��ѧ������ 
	
}

int  Increase (struct Student Stu[], int n)
{
	int i, j, number;
	
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)
  	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
   	}
    
	cout << "���������ӵ�ѧ��������" << endl;
	cin >> number; 
	
	for(i=n; i<n+number; i++)    //Ѱ����Ҫ���ҵĺ���,�ӵ�n-1λ���濪ʼ��һ��������������// 
	{		
			cout << "ѧ��:" << endl;		
		    cin >> Stu[i]. m_strNum;
			
			cout << "����:" << endl;		
			cin >> Stu[i].m_strName;				
			
			cout << "math:" << endl;			
			cin >> Stu[i].m_fMath; 
			  			
			cout << "English:" << endl;				
			cin >> Stu[i].m_fEnglish;
			 			
			cout << "computer:" << endl;			
			cin >> Stu[i].m_fComputer;  
				  
    }
    
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n+number; i++)//��Ϊ������number�ˣ�����ѧ������Ӧ����n+number�ˣ������Ӻ��ѧ��������Ϣ��� 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
	return(n+number);//�������Ӻ��ѧ������ 

} 

void Update1 (struct Student Stu[], int n)   //�޸ĺ��� 
{
      int i;
      char j;
      char  number[20];
	       
    cout << "��������Ҫ���ҵ�ѧ�ţ�" << endl;	   
    cin >> number;
      
	for(i=0; i<n; i++)	 
    {			  
	       	if(strcmp(Stu[i].m_strNum, number) == 0) //��ѧ�Ž��в���// 
			{
			 cout << "��������Ҫ�޸ĵ����ݣ�" << endl; 
			  
			  cout << "ѧ�ţ�" << endl;
			  cin >>  Stu[i].m_strNum;
		     
		      cout << "����:" << endl;
		      cin >> Stu[i].m_strName;
			  
			  cout << "math:" << endl;			
			  cin >> Stu[i].m_fMath; 
		
			  cout << "English:" << endl;				
			  cin >> Stu[i].m_fEnglish;
		     
			  cout << "computer:" << endl;			
			  cin >> Stu[i].m_fComputer;
            }
    }
    
    system("cls");
    
    cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//���޸ĺ��ѧ����Ϣ��� 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName  <<  "\t"  << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
//	return(n);//�����޸ĺ��ѧ����Ϣ 
	
} 

void Update2 (struct Student Stu[], int n)   //�޸ĺ��� 
{
      int i;
      char j;
      char  name[20];
           
    cout << "��������Ҫ���ҵ�������" << endl;	   
    cin >> name;
      
	for(i=0; i<n; i++)	 
    {			  
	       	if(strcmp(Stu[i].m_strName, name) == 0) //��ѧ�Ž��в���// 
			{
			 cout << "��������Ҫ�޸ĵ����ݣ�" << endl; 
			  
			  cout << "ѧ�ţ�" << endl;
			  cin >>  Stu[i].m_strNum;
		     
		      cout << "����:" << endl;
		      cin >> Stu[i].m_strName;
			  
			  cout << "math:" << endl;			
			  cin >> Stu[i].m_fMath; 
		
			  cout << "English:" << endl;				
			  cin >> Stu[i].m_fEnglish;
		     
			  cout << "computer:" << endl;			
			  cin >> Stu[i].m_fComputer;
            }
    }
    
    system("cls");
    
    cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//���޸ĺ��ѧ����Ϣ��� 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName  <<  "\t"  << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
//	return(n);//�����޸ĺ��ѧ����Ϣ 
	
} 

void TotalScore (struct Student Stu[], int n)
{
	int i;

	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)
  	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
   	}
	
	for(i=0; i<n; i++)
	{ 
		   Stu[i].m_fSum = Stu[i].m_fEnglish + Stu[i].m_fMath + Stu[i].m_fComputer;
    }
    
    system("cls");
	
	cout << "����" << "\t" << "�ܷ�" <<  endl;
	
	for(i=0; i<n; i++)
	{
		
	cout << Stu[i].m_strName  << "\t" <<  Stu[i].m_fSum  << endl;
	
    }
   	
   	cout << "\n" << endl;
} 

void AveScore (struct Student Stu[], int n)
{
	int i;
	
	cout << "ѧ��" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)
  	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
   	}
   	
	for(i=0; i<n; i++)
	{ 
		   Stu[i].m_fSum = Stu[i].m_fEnglish + Stu[i].m_fMath + Stu[i].m_fComputer;
		   
		   Stu[i].m_fAve = Stu[i].m_fSum/3.0;
    }
    
    system("cls");
	
	cout << "����" << "\t" << "ƽ����" <<  endl;
	
	for(i=0; i<n; i++)
	{
		
	cout << Stu[i].m_strName  << "\t" <<  Stu[i].m_fAve  << endl;
	
    }
   	
   	cout << "\n" << endl;
	
}

void MathSort (struct Student Stu[], int n)  //��ѧ������������ 
{	      	
    	struct Student temp;
    	
 		int i, j, k;
			
 		cout << "��ѧ���Ƴɼ�������" << endl;
 		
 		for(i=0; i<n; i++)  //ѡ������ 
 		{
 			k = i;	 
 			for(j=i+1; j<n; j++)
 			
 			 if(Stu[j].m_fMath>Stu[k].m_fMath)//������forѭ�������ж�stu[i+1]�Ƿ����stu[i] ,ȷ��stu[i+1]����stu[i],�ſ��Խ��н��� 
			 { 
			  k = j;  
			  temp = Stu[k];
			  Stu[k] =	Stu[i];
			  Stu[i] = temp;
			 } 
		 }  
		 
		system("cls");
		 
	    cout << "name" << "\t" << "math" << endl;
    
       for(i=0; i<n; i++)//�������Ժ�ĳɼ��������Ļ�� 
     	{
		  cout << Stu[i].m_strName << "\t" << Stu[i].m_fMath  << endl;
    	}
	
	cout << "\n" << endl;
}
	
void EnglishSort(struct Student Stu[], int n)// Ӣ�ﵥ���������� 
{
    	struct Student temp;
    	
	    int i, j, k;
	    
	    cout << "Ӣ�ﵥ�Ƴɼ�������" << endl;
	    
	    for(i=0; i<n; i++)
 		{
 			k = i;	
 			for(j=i+1; j<n; j++)
 			
 			 if(Stu[j].m_fEnglish > Stu[k].m_fEnglish)
			  
			  k = j;  
			  temp = Stu[k];
			  Stu[k] =	Stu[i];
			  Stu[i] = temp;                       
		 } 
		 
	     system("cls"); 
		 
	    cout << "name" << "\t"  <<"English"  << endl;

        for(i=0; i<n; i++)
     	{
	 	    cout << Stu[i].m_strName << "\t" << Stu[i].m_fEnglish << endl;
    	}
	
    	cout << "\n" << endl;
}

void ComputerSort(struct Student Stu[], int n)//C���Ե����������� 
{	
        struct Student temp;
        
        int i, j, k;
		    
	    cout << "C���Ե��Ƴɼ�������" << endl;
	    
	    for(i=0; i<n; i++)
 		  {
 			k = i;	
 			for(j=i+1; j<n; j++)
 			
 			 if(Stu[j].m_fComputer>Stu[k].m_fComputer)
			  
			  k = j;  
			  temp = Stu[k];
			  Stu[k] =	Stu[i];
			  Stu[i] = temp;
		   } 
		   
	    system("cls"); 
		 
	   cout << "name"  << "\t" << "computer" << endl;
    
       for(i=0; i<n; i++)
     	{
	    	cout << Stu[i].m_strName << "\t" << Stu[i].m_fComputer << endl;
    	}
	
	   cout << "\n" << endl;
} 

void Search1(struct Student Stu[], int n)  //���Һ��� 
{
      int i;
	  char  number[20];	
            
      cout << "��������Ҫ��ѯ��ѧ�ţ�" << endl;	   //��ѧ�Ž��в��� 
      cin >> number;
      
	for(i=0;  i<n; i++)	//���ν��в��� 
    {	
         		  
	        if(strcmp(Stu[i].m_strNum,number) == 0)//�ж��Ƿ��ҵ���Ҫ���ҵĺ��� 
			{
	      		cout << "ѧ�ţ�" << endl;
	      		cout << Stu[i].m_strNum << endl;
	      		
	      		cout << "������" << endl;
	      		cout << Stu[i].m_strName << endl;
	      		
	      		cout << "��ѧ��" << endl;
				cout << Stu[i].m_fMath << endl; 
	      		
	      		cout << "Ӣ�" << endl;
	         	cout << Stu[i].m_fEnglish << endl;
	         	
	         	cout << "C���ԣ�" << endl; 
	      	    cout << Stu[i].m_fComputer << endl;
		
	          }
    	
    }
    
    
    cout << "\n" << endl;

}

void Search2(struct Student Stu[], int n)  //���Һ��� 
{
      int i;
	  char  name[20];
            
      cout << "��������Ҫ��ѯ��������" << endl;	   //���������в��� 
      cin >> name;
      
	for(i=0;  i<n; i++)	//���ν��в��� 
    {	
         		  
	        if(strcmp(Stu[i].m_strName,name) == 0)//�ж��Ƿ��ҵ���Ҫ���ҵĺ��� 
			{
	      		cout << "ѧ�ţ�" << endl;
	      		cout << Stu[i].m_strNum << endl;
	      		
	      		cout << "������" << endl;
	      		cout << Stu[i].m_strName << endl;
	      		
	      		cout << "��ѧ��" << endl;
				cout << Stu[i].m_fMath << endl; 
	      		
	      		cout << "Ӣ�" << endl;
	         	cout << Stu[i].m_fEnglish << endl;
	         	
	         	cout << "C���ԣ�" << endl; 
	      	    cout << Stu[i].m_fComputer << endl;
		
	          }
    	
    }
    
    
    cout << "\n" << endl;

}

void Nopassee (struct Student Stu[], int n)   //�������ſβ����������ĺ��� 
{
	int i;
     
     for(i=0; i<n; i++)
     {
      	if((((Stu[i].m_fMath<60) && (Stu[i].m_fEnglish<60)) || ((Stu[i].m_fMath<60) && (Stu[i].m_fComputer<60)) || ((Stu[i].m_fEnglish<60) && (Stu[i].m_fComputer<60)))!= 0)//�߼��ж���䡣 
		 {		 	
			cout <<"\n\t\t������ѧ����ѧ�ź����֣�\t\t\n" << endl;
			cout << "\n\t\t"<< Stu[i].m_strNum << "\t" << Stu[i].m_strName<<"\t\t\n" << endl; 
		 } 
	 }
	 
	 cout << "\n" << endl;
	 
}




