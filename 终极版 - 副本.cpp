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

void Menu(struct Student Stu[], int n); //总菜单函数 
void Menu1(struct Student Stu[], int n); //子菜单，分别进行增加，删除，修改成绩 
void Menu2(struct Student Stu[],int n);//子菜单函数，分别输出数学，英语，C语言的单科成绩
void Menu3(struct Student Stu[],int n);//子菜单3，分别用学号，姓名进行查找 
void Menu4(struct Student Stu[],int n);//子菜单4，分别用学号，姓名进行查询 
void Input(struct Student Stu[], int n);//录入函数，输入学生信息 。 
void Nopassee (struct Student Stu[], int n);//用来查找两门课不及格的人 
void MathSort (struct Student Stu[], int n);//数学排序函数，对英语分数进行排序 
void EnglishSort (struct Student Stu[], int n);//英语排序函数，对英语分数进行排序 
void ComputerSort (struct Student Stu[], int n);//C语言排序函数，对英语分数进行排序 
void TotalScore (struct Student Stu[], int n);//总分函数 
void AveScore (struct Student Stu[], int n);//平均分函数 
void Search1 (struct Student Stu[],int n);//查询函数，用来查询和输出学生信息(用学号进行查找） 
void Search2(struct Student Stu[],int n);//查询函数，用来查询和输出学生信息(用姓名进行查找）
int  Delete (struct Student Stu[], int n);//删除函数 ，因为要返回减少以后的人数，所以是int型 
int Increase (struct Student Stu[], int n);//增加函数 ，因为要返回增加以后的人数，所以是int型 
void Update1(struct Student Stu[], int n);//修改函数，对学生信息进行修改 ，因为要返回修改以后的数据，所以是int型 （用学号进行查找） 
void Update2 (struct Student Stu[], int n);//修改函数，对学生信息进行修改 ，因为要返回修改以后的数据，所以是int型 （用姓名进行查找）

int main()
{	
    int n;
	 
	struct Student Stu[20];  //在主函数里面定义一个结构体变量//
	
	cout << "输入学生人数：" << endl;
	cin >>n;  
	
	Input(Stu,n);//录入函数，进行学生成绩的录入。 
     
    Menu(Stu,n);//总菜单，对学生成绩进行汇总。 
	
	return 0;	
}

void Menu(struct Student Stu[],int n)                  //总菜单函数 
 {
    cout << "\n\t\t*****************学生管理系统****************\t\t\n " << endl;	 		
	cout << "\n\t\t*******************************\n\n" << endl;
	cout << "\n\t\t1..---------------成绩(增，减，修)\n" << endl;
	cout << "\n\t\t2..---------------单科成绩\n" << endl;
	cout << "\n\t\t3.----------------成绩查询\n" << endl;
	cout << "\n\t\t4.----------------不合格\n" << endl;
	cout << "\n\t\t5.----------------科目总分\n" << endl;
	cout << "\n\t\t6-----------------科目平均分\n" << endl; 
	cout << "\n\t\t7.----------------退出\n" <<	endl;
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
		       Menu1(Stu,n);//子菜单1，进行增加，删除，修改学生信息 
		    	break;
		case 2:
			   system("cls");
			   Menu2(Stu,n);//子菜单2，进行学生成绩单科排名 
			   Menu(Stu,n);	
			    break;
		case 3:
			   system("cls");
		       Menu4(Stu, n);//查询学生信息函数 
		       Menu(Stu,n);
		       break;
		case 4:
			   system("cls");
		 	   Nopassee (Stu,n); //查询不及格学生成绩的函数 
		 	   Menu(Stu,n);
		 	   break;
		case 5:
			   system("cls");
		       TotalScore(Stu, n);//总分函数 
		        Menu(Stu,n);
				break;
	    case 6:
	    	   system("cls"); 
		       AveScore(Stu, n);//平均分函数 
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

void Menu1(struct Student Stu[],int n)//子菜单函数1，对学生成绩进行处理。 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------增加\n" << endl;
	cout << "\n\t\t2.----------------删除\n" << endl;		
	cout << "\n\t\t3.----------------修改\n" << endl;
	cout << "\n\t\t4.----------------返回主菜单\n" << endl;
	cout << "\n\t\t5.----------------退出\n" << endl; 
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
		    	   n = Increase(Stu,n);//增加函数 
		           Menu1(Stu,n);//调用子菜单1，以便继续进行学生信息的处理 
			       break;
			       
		    case 2:
		    	   system("cls");
		    	   n = Delete(Stu,n);//删除函数 
			        Menu1(Stu,n);		
			        break;
		    	   
		    case 3:
		    	   system("cls");
		           Menu3(Stu,n); 
		           Menu1(Stu,n);
		        	break;
		        	
		    case 4:
		    	    system("cls");
		            Menu(Stu,n);//返回总菜单 ，进行其他的操作 
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

void Menu2(struct Student Stu[], int n)//单科成绩排序菜单 ，分别输出数学，英语，C语言成绩单科排名 
{
	cout << "\n\t*****************************\t\n" << endl;
	cout << "\n\t1.---------------------数学成绩单科排名\n" << endl;
	cout << "\n\t2.---------------------英语成绩单科排名\n" << endl;
	cout << "\n\t3.---------------------C语言成绩单科排名\n" << endl;
	cout << "\n\t4.---------------------返回主菜单\n" << endl;
	cout <<  "\n\t5,--------------------退出\n" << endl; 
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
			       MathSort(Stu, n);//数学单科成绩排名函数 
			        Menu2(Stu,n);//返回菜单2，继续进行操作 
			       break;
			       
		    case 2:
		    	    system("cls");
		    	    EnglishSort(Stu,n);//英语单科成绩排名函数 
		    	    Menu2(Stu,n);
		    	   break;
		    	   
		    case 3:
		    	   system("cls");
		    	   ComputerSort(Stu, n);//C语言单科成绩排名函数 
		    	   Menu2(Stu,n);
		    	   break;
		   case 4:
		   	      system("cls");
		          Menu(Stu,n);//返回总菜单 ，进行其他的操作 
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

void Menu3(struct Student Stu[],int n)//子菜单函数3，对学生成绩进行查找。 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------按学号查找\n" << endl;
	cout << "\n\t\t2.----------------按姓名查找\n" << endl;		
	cout << "\n\t\t3.----------------返回菜单1\n" << endl;
	cout << "\n\t\t4.----------------返回主菜单\n" << endl;
	cout << "\n\t\t5.----------------退出\n" << endl;
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
		    	    Update1(Stu,n);//查找函数1，用学号进行查找 
		           Menu3(Stu,n);// 查找菜单 
			       break;
			       
		    case 2: 
		           system("cls");
		    	     Update2(Stu,n); //查找函数2，用姓名进行查找  
			        Menu3(Stu,n);		
			        break;
		    	   
		    case 3:
			        system("cls"); 
		            Menu1(Stu,n);//返回函数1，重新进行增加，删除，修改的函数菜单 
		        	break;
		        	
		    case 4:
		    	    system("cls");
		            Menu(Stu,n);//返回总菜单 ，进行其他的操作 
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

void Menu4(struct Student Stu[],int n)//子菜单函数4，对学生成绩进行查询。 
{
	cout << "\n\t\t**************************\t\t\n" << endl;
	cout << "\n\t\t1.----------------按学号查询\n" << endl;
	cout << "\n\t\t2.----------------按姓名查询\n" << endl;		
	cout << "\n\t\t3.----------------返回主菜单\n" << endl;
	cout << "\n\t\t4.----------------退出\n" << endl;
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
		    	   Search1(Stu, n);//查找函数1，用学号进行查找 
		           Menu4(Stu, n);// 查找菜单 
			       break;
			       
		    case 2:
		    	    system("cls");
		    	    Search2(Stu, n); //查找函数2，用姓名进行查找  
			        Menu4(Stu, n);		
			        break;
		        	
		    case 3:
		    	    system("cls");
		            Menu(Stu,n);//返回总菜单 ，进行其他的操作 
		        	break;
		    case 4:
		           cout << "Goodbay!" << endl; //按任意键退出 
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

void Input(struct Student Stu[],int n)//录入函数，进行学生成绩录入 
{
	int i;//进行学生人数的录入//

	for(i=0; i<n; i++)
     {
			  cout << "学号:" << endl;		
		      cin >> Stu[i]. m_strNum;
			
			   cout << "姓名:" << endl;		
			   cin >> Stu[i].m_strName;				
			
			   cout << "math:" << endl;			
			   cin >> Stu[i].m_fMath;

			   cout << "English:" << endl;				
			   cin >> Stu[i].m_fEnglish;
			 			
			   cout << "computer:" << endl;			
			   cin >> Stu[i].m_fComputer;
    }
    
	 system("cls");//清屏函数
    
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//将已录入的学生信息在屏幕上输出 
   	{
		  cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl; 

}

int  Delete(struct Student Stu[], int n)//删除函数，对学生信息进行删除 
{
	int i, j;
	
	char number[20];
    
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//学生信息显示 
   	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
   
		
	cout << "请输入学号：" << endl; //由学号进行查询 
	cin >> number; 
	
	for(i=0; i<n; i++)    //寻找需要查找的学号// 
	{
		if(strcmp(Stu[i].m_strNum,number) == 0 )//查找到需要删除的学生信息 
		{
			for(j=i; j<n-1; j++) //因为要删除一位，如果j+1是n位，则j最大只能是n-1位，即把第n位隐藏 
			{
			     
			 Stu[j] = Stu[j+1];  //将后面一个记录向前移动,即覆盖。 
			 
			              
		    } 
		          
	    }		
	
	}
	
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n-1; i++)//因为删除了一位，所以真正的总数少一位。 将已删除后的学生信息输出 
   	{  
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
	return(n-1);//返回减少后的学生总数 
	
}

int  Increase (struct Student Stu[], int n)
{
	int i, j, number;
	
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)
  	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
   	}
    
	cout << "请输入增加的学生人数：" << endl;
	cin >> number; 
	
	for(i=n; i<n+number; i++)    //寻找需要查找的号码,从第n-1位后面开始加一，最后再整体输出// 
	{		
			cout << "学号:" << endl;		
		    cin >> Stu[i]. m_strNum;
			
			cout << "姓名:" << endl;		
			cin >> Stu[i].m_strName;				
			
			cout << "math:" << endl;			
			cin >> Stu[i].m_fMath; 
			  			
			cout << "English:" << endl;				
			cin >> Stu[i].m_fEnglish;
			 			
			cout << "computer:" << endl;			
			cin >> Stu[i].m_fComputer;  
				  
    }
    
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n+number; i++)//因为增加了number人，所以学生总数应该是n+number人，将增加后的学生人数信息输出 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
	return(n+number);//返回增加后的学生总数 

} 

void Update1 (struct Student Stu[], int n)   //修改函数 
{
      int i;
      char j;
      char  number[20];
	       
    cout << "请输入你要查找的学号：" << endl;	   
    cin >> number;
      
	for(i=0; i<n; i++)	 
    {			  
	       	if(strcmp(Stu[i].m_strNum, number) == 0) //由学号进行查找// 
			{
			 cout << "请输入需要修改的内容：" << endl; 
			  
			  cout << "学号：" << endl;
			  cin >>  Stu[i].m_strNum;
		     
		      cout << "姓名:" << endl;
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
    
    cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//将修改后的学生信息输出 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName  <<  "\t"  << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
//	return(n);//返回修改后的学生信息 
	
} 

void Update2 (struct Student Stu[], int n)   //修改函数 
{
      int i;
      char j;
      char  name[20];
           
    cout << "请输入你要查找的姓名：" << endl;	   
    cin >> name;
      
	for(i=0; i<n; i++)	 
    {			  
	       	if(strcmp(Stu[i].m_strName, name) == 0) //由学号进行查找// 
			{
			 cout << "请输入需要修改的内容：" << endl; 
			  
			  cout << "学号：" << endl;
			  cin >>  Stu[i].m_strNum;
		     
		      cout << "姓名:" << endl;
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
    
    cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)//将修改后的学生信息输出 
   	{
		cout << Stu[i].m_strNum  << "\t" << Stu[i].m_strName  <<  "\t"  << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
	}
	
	cout << "\n" << endl;
	
//	return(n);//返回修改后的学生信息 
	
} 

void TotalScore (struct Student Stu[], int n)
{
	int i;

	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
   for(i=0; i<n; i++)
  	{
		cout << Stu[i].m_strNum << "\t" << Stu[i].m_strName << "\t" << Stu[i].m_fMath << "\t" << Stu[i].m_fEnglish << "\t" << Stu[i].m_fComputer << endl;
   	}
	
	for(i=0; i<n; i++)
	{ 
		   Stu[i].m_fSum = Stu[i].m_fEnglish + Stu[i].m_fMath + Stu[i].m_fComputer;
    }
    
    system("cls");
	
	cout << "姓名" << "\t" << "总分" <<  endl;
	
	for(i=0; i<n; i++)
	{
		
	cout << Stu[i].m_strName  << "\t" <<  Stu[i].m_fSum  << endl;
	
    }
   	
   	cout << "\n" << endl;
} 

void AveScore (struct Student Stu[], int n)
{
	int i;
	
	cout << "学号" << "\t" << "name" << "\t" << "math" << "\t" << "English" << "\t" << "computer" << endl;
    
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
	
	cout << "姓名" << "\t" << "平均分" <<  endl;
	
	for(i=0; i<n; i++)
	{
		
	cout << Stu[i].m_strName  << "\t" <<  Stu[i].m_fAve  << endl;
	
    }
   	
   	cout << "\n" << endl;
	
}

void MathSort (struct Student Stu[], int n)  //数学单科排名函数 
{	      	
    	struct Student temp;
    	
 		int i, j, k;
			
 		cout << "数学单科成绩排名：" << endl;
 		
 		for(i=0; i<n; i++)  //选择排序 
 		{
 			k = i;	 
 			for(j=i+1; j<n; j++)
 			
 			 if(Stu[j].m_fMath>Stu[k].m_fMath)//这两个for循环用于判断stu[i+1]是否大于stu[i] ,确保stu[i+1]大于stu[i],才可以进行交换 
			 { 
			  k = j;  
			  temp = Stu[k];
			  Stu[k] =	Stu[i];
			  Stu[i] = temp;
			 } 
		 }  
		 
		system("cls");
		 
	    cout << "name" << "\t" << "math" << endl;
    
       for(i=0; i<n; i++)//将交换以后的成绩输出在屏幕上 
     	{
		  cout << Stu[i].m_strName << "\t" << Stu[i].m_fMath  << endl;
    	}
	
	cout << "\n" << endl;
}
	
void EnglishSort(struct Student Stu[], int n)// 英语单科排名函数 
{
    	struct Student temp;
    	
	    int i, j, k;
	    
	    cout << "英语单科成绩排名：" << endl;
	    
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

void ComputerSort(struct Student Stu[], int n)//C语言单科排名函数 
{	
        struct Student temp;
        
        int i, j, k;
		    
	    cout << "C语言单科成绩排名：" << endl;
	    
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

void Search1(struct Student Stu[], int n)  //查找函数 
{
      int i;
	  char  number[20];	
            
      cout << "请输入你要查询的学号：" << endl;	   //由学号进行查找 
      cin >> number;
      
	for(i=0;  i<n; i++)	//依次进行查找 
    {	
         		  
	        if(strcmp(Stu[i].m_strNum,number) == 0)//判断是否找到所要查找的函数 
			{
	      		cout << "学号：" << endl;
	      		cout << Stu[i].m_strNum << endl;
	      		
	      		cout << "姓名：" << endl;
	      		cout << Stu[i].m_strName << endl;
	      		
	      		cout << "数学：" << endl;
				cout << Stu[i].m_fMath << endl; 
	      		
	      		cout << "英语：" << endl;
	         	cout << Stu[i].m_fEnglish << endl;
	         	
	         	cout << "C语言：" << endl; 
	      	    cout << Stu[i].m_fComputer << endl;
		
	          }
    	
    }
    
    
    cout << "\n" << endl;

}

void Search2(struct Student Stu[], int n)  //查找函数 
{
      int i;
	  char  name[20];
            
      cout << "请输入你要查询的姓名：" << endl;	   //由姓名进行查找 
      cin >> name;
      
	for(i=0;  i<n; i++)	//依次进行查找 
    {	
         		  
	        if(strcmp(Stu[i].m_strName,name) == 0)//判断是否找到所要查找的函数 
			{
	      		cout << "学号：" << endl;
	      		cout << Stu[i].m_strNum << endl;
	      		
	      		cout << "姓名：" << endl;
	      		cout << Stu[i].m_strName << endl;
	      		
	      		cout << "数学：" << endl;
				cout << Stu[i].m_fMath << endl; 
	      		
	      		cout << "英语：" << endl;
	         	cout << Stu[i].m_fEnglish << endl;
	         	
	         	cout << "C语言：" << endl; 
	      	    cout << Stu[i].m_fComputer << endl;
		
	          }
    	
    }
    
    
    cout << "\n" << endl;

}

void Nopassee (struct Student Stu[], int n)   //查找两门课不及格人数的函数 
{
	int i;
     
     for(i=0; i<n; i++)
     {
      	if((((Stu[i].m_fMath<60) && (Stu[i].m_fEnglish<60)) || ((Stu[i].m_fMath<60) && (Stu[i].m_fComputer<60)) || ((Stu[i].m_fEnglish<60) && (Stu[i].m_fComputer<60)))!= 0)//逻辑判断语句。 
		 {		 	
			cout <<"\n\t\t不及格学生的学号和名字：\t\t\n" << endl;
			cout << "\n\t\t"<< Stu[i].m_strNum << "\t" << Stu[i].m_strName<<"\t\t\n" << endl; 
		 } 
	 }
	 
	 cout << "\n" << endl;
	 
}




