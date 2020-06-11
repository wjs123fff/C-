#include <iostream>
#include <string.h> 
#include <math.h>
using namespace std;
const int MaxSize = 100;
template<class T> //��ʼ��һ��ջ��ģ����  
class LinkStack
{
	public:
		LinkStack(); //���캯������ʼ��һ������ջ 
		~LinkStack(){};//�������� 
		void 
		Push(T x);//��ջ��������Ԫ��X��ջ�� 
		T Pop();//��ջ��������ջ��Ԫ�س�ջ
		T GetTop(); //ȡջ��Ԫ�أ�����ջ 
		int Empty();//�пղ������ж��Ƿ�Ϊ��ջ 
		void Delete();//ɾ��ջ�ڳ�Ա
		int top;
	protected:
	       T data[MaxSize];
};

template <class T> LinkStack<T>::LinkStack()
{
	top = 0;
}

template <class T>
 int LinkStack<T>::Empty()
{
	return top == 0? true : false;
}
template <class T> 
T LinkStack<T>::GetTop()
{
	if(top != 0)
	{
		return data[top-1];
	}
}
template <class T> 
void LinkStack<T>::Push(T x)
{
	if(top == 100-1)  
    {  
        cout<<"None"<<endl;
    }  
    data[top] = x;  
    top++;
} 
template <class T> 
T LinkStack <T>::Pop()
{
	
    if(top == 0)
    {  
        cout<<"None"<<endl;
    }  
    T x = data[top-1];  
    top--;
    return x;  
}
template <class T>
 void LinkStack <T>::Delete()  
{    
    top --;  
} 

int Operator(char op) // ������������ȼ� 
{
	switch(op)
	{
		case '#':
			return -1;
		case '(':
			     return 0;
		case '+':
		case '-':
		     	return 1;
		case '*':
		case '/':
		    	return 2;
		dafault:
		    	return -1;
	}
}
bool judge_perator(char op)  // �ж��Ƿ�Ϊ����� 
{
	switch(op)
	{
		case'+':
		case'-':
		case'*':
		case'/':
			return true;
		default :   
        	return false;  
	}  
}
void MidtoLast(char str[] ,char str1[],int &n) //��׺ת��׺�����غ�׺���ʽ�ĳ��ȣ��������š� 
{
	int i = 0;
	int j = 0;
	LinkStack <char> s;
	
	s.Push('#');
	
	while(str[i]!='#')//��ջ��Ϊ�� 
	{
		
		if((str[i] >= '0'&&str[i]<='9')||str[i]=='.')//������Ϊ������ʱ ,ֱ�Ӵ���str������ 
		{
			str1[j++] = str[i];  
            n++;  
		}
		else if(str[i] == '(')//����������� '('��ֱ�ӽ�ջ 
		{
			s.Push(str[i]);
		}
		else if(str[i] == ')')// ����������ţ�ջ��Ԫ�ز���'('ʱ�����֮ǰ��ջ�Ĳ�������������str1�� 
		{
			while(s.GetTop() != '(')  
            {  
                str1[j++] = s.Pop();  
                n++;  
            }  
            s.Pop(); //������е����ų�ջ 
		}
		else if(judge_perator(str[i]))//������������ʱ��ȡջ��Ԫ�غ�ջ�����ȼ����бȽϡ� 
		{
			str1[j++] = ' ';
			n++;
			if(Operator(str[i]) <= Operator(s.GetTop()))//���ջ��Ԫ�����ȼ���ֱ�ӳ�ջ������str1�� 
			{
				str1[j++] = s.Pop();
				n++;
			}
			if(Operator(str[i]) > Operator(s.GetTop()))//���ջ�����ȼ���ֱ�ӽ�ջ 
			{
				s.Push(str[i]);
			}
		}
		i++;
	}
	while(s.GetTop())//��ջ��Ϊ��ʱ�����ջ��ʣ��Ĳ����� 
	{
		str1[j++] = s.Pop();
        str1[j++] = ' ';
        n++;  
	}
}
double Get_Number(char str[],int *i) //���ַ�����ת�������� 
{
	double x = 0.0;//�洢ת���ɵ����� 
	int k = 0;//�洢С�����λ�� 
	while(str[*i] >= '0' && str[*i] <= '9')
	{
		x = x*10 + (str[*i]-'0'); 
		(*i)++;
	}
	if(str[*i] == '.')//�������� 
	{
		(*i)++;
		
		while(str[*i] >= '0'&&str[*i] <='9')
		{
			x = x*10 + (str[*i]-'0');
			(*i)++;
			k++;
		}
	}
	while(k!=0)
	{
		x = x/10;//С��ÿ��һλ��Ҫ��10 
		k--;
	}
	return x;
}
double Last_value(char str1[]) //��׺���ʽ������ֵ 
{
	LinkStack <double> s;
	int i = 0;
	double n;
	double m;
	
	while(str1[i] != '#')
	{
		if(str1[i] >= '0'&& str1[i] <= '9')//��������Ϊ�ַ���ʱ������ת�����ջ 
		{
			s.Push(Get_Number(str1,&i));
		}
		else if(str1[i] == ' ')
		{
			i++;
		}
		else if(str1[i] == '+')//���㷨������һ���������������������������������㣬�ٽ���������ջ���ټ��� 
	    {                      //���б�����ֱ���õ����ս�� 
			n = s.Pop();
			m = s.Pop()+n;
			s.Push(m);
			i++; 
		}
		else if(str1[i] == '-')
		{
			n = s.Pop();
			m = s.Pop()-n;
			s.Push(m);
			i++;
		}
		else if(str1[i] == '*')
		{
			n = s.Pop();
			m = s.Pop()*n;
			s.Push(m);
			i++;
		}
		else if(str1[i] == '/')//ע���ջ�Ⱥ�˳�򣬳�������Ϊ0�� 
		{
			n = s.Pop();
			m = s.Pop()/n;
			if(n == 0)
			{
				cout << "����������Ϊ0 " <<endl;
			}
			s.Push(m);
			i++;
		}
	}
	return s.GetTop();
}
int Wrong_Character(char str[],int n) //�ж��Ƿ���ڷǷ��ַ� 
{
	int flag;//��һ�������� 
	int i;
	
	for(i = 0;i < n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')//�ж��ַ��������Ƿ���ȷ 
		{
			continue;
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='.'||str[i]=='('||str[i]==')')//�жϲ����� �����Ƿ���ȷ 
		{
			
		}
		else if(i == n-1&&str[i] == '#') //�ж����볤���Ƿ���ȷ 
		{
			continue;
		}
		else
		{
			flag++;
		}
	}
	if(flag!=0)
	{
		cout<<"�������"<<endl; 
	}
	return flag;
}
int Brack_match(char str[],int n)//�ж������Ƿ�ƥ�� 
{
	int left = 0;
	
	int right = 0;//���������� 
	
	for(int i=0; i<n; i++)
	{
		if(str[i] == '(')
		{
			left++;
		}
	
	}
	for(int j=0; j<n; j++)
	{
		if(str[j] == ')')
		{
			right++;
		}
	}
	
	if(left == right)//�ж��������Ÿ����Ƿ���� 
	{
		return 0;
	}
	else
	{
		cout<<"���Ų�ƥ��"<<endl;
	}
	
 } 
int judge_format(char str[],int n) //�ж��Ƿ���ڸ�ʽ����  
{
	int Num1 = 0;
	int Num2 = 0;
	int Num3 = 0;
	int Num4 = 0;//���������ж��Ƿ���� 

	for (int i = 0; i < n; i++)
	{
		if(i == 0&&(str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/'||str[i] == '.'))
		{
			cout<<"��ͷ������С����������"<<endl;
			Num1++; 
		}
		if(str[i] == '.'&&str[i+1] == '.')
		{
			cout<<"С���㲻���ظ�����"<<endl;
			Num2++;
		}
		if((str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/')
		&&(str[i+1] == '+'||str[i+1] == '-'||str[i+1] == '*'||str[i+1] == '/'))
		{
			cout<<"�����������ظ�����"<<endl;
			Num3++;
		}
		if((str[i] >= 'a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			cout<<"�ַ��Ƿ�"<<endl;
			Num4++;
		}
		
	}
	return Num1+Num2+Num3+Num4;	
} 
void Fun()//�������� 
{
	   int len;
	   int count;
	   int m = 0;
	   int n = 0; 
	   for(n=0; m == 0; n++)
	   {
	   	
	   	cout<<"������һ����׺���ʽ:"<<endl;
		
		char str[MaxSize];
		cin >> str;
	   len = strlen(str);
		str[len] = '#';
		len++;
		count = Wrong_Character(str, len)+judge_format(str, len)+Brack_match(str,len);//�ж�����ı��ʽ�Ƿ���ִ��� 
		
		if(count == 0)
		{
			char str1[MaxSize];
			int n = 0;
			
			MidtoLast(str, str1, n);//��׺ת��׺�������� 
			
			cout <<"��׺���ʽΪ��";
			
			for(int i = 0;i < n;i++)
	    	{
	    		if(str1[i] == '#')
	    		{
	    			i++;
				}
	    		cout << str1[i];
			}
			
			cout << "\n��׺���ʽ������:";  
			
	    	cout << Last_value(str1) << endl;//��׺���ʽ�������� 
	    	
	    	cout << "\n�Ƿ�����������룿" << endl
			;
	    	cout << "\ny/Y�������㣬������˳�:"  << endl;
	    	
	    	char ch;
	    	cin >> ch;
	    	
	    	if(ch == 'y'||ch == 'Y')
	    	{
	    		m = 0;
			}
			else
			{
				m = 1;
			}
		}
		else
		{
			cout<<"---------------------------------------------"<<endl; 
			cout << "\n���ʽ�����Ƿ���������" << endl; 
			
			cout << "\ny/Y�������룬������˳�:";
			
			char ch;
			cin >> ch;
			
			if (ch == 'y'||ch == 'Y')
			{
				m = 0;
			}
			else
			{
				m = 1;
			}
		}
	  }
	
}
int main()//������ 
{
	cout<<"\n\t------------------------------------------------\n\n"<<endl;
	cout<<endl;
	cout<< "\n\t----------------���׼�����---------------\n\n"<<endl;
	cout<<endl;
	cout<<"\n\t------------------------------------------------\n\n"<<endl;
	
	Fun();
		
	return 0;
}

