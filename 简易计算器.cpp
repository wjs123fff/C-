#include <iostream>
#include <string.h> 
#include <math.h>
using namespace std;
const int MaxSize = 100;
template<class T> //初始化一个栈的模板类  
class LinkStack
{
	public:
		LinkStack(); //构造函数，初始化一个空链栈 
		~LinkStack(){};//析构函数 
		void 
		Push(T x);//入栈操作，将元素X入栈； 
		T Pop();//出栈操作，将栈顶元素出栈
		T GetTop(); //取栈顶元素，不出栈 
		int Empty();//判空操作，判断是否为空栈 
		void Delete();//删除栈内成员
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

int Operator(char op) // 定义运算符优先级 
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
bool judge_perator(char op)  // 判断是否为运算符 
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
void MidtoLast(char str[] ,char str1[],int &n) //中缀转后缀，返回后缀表达式的长度，包括括号。 
{
	int i = 0;
	int j = 0;
	LinkStack <char> s;
	
	s.Push('#');
	
	while(str[i]!='#')//当栈不为空 
	{
		
		if((str[i] >= '0'&&str[i]<='9')||str[i]=='.')//数组内为操作数时 ,直接存入str数组中 
		{
			str1[j++] = str[i];  
            n++;  
		}
		else if(str[i] == '(')//如果遇到的是 '('，直接进栈 
		{
			s.Push(str[i]);
		}
		else if(str[i] == ')')// 如果是右括号，栈顶元素不是'('时，输出之前进栈的操作符，并存入str1中 
		{
			while(s.GetTop() != '(')  
            {  
                str1[j++] = s.Pop();  
                n++;  
            }  
            s.Pop(); //最后将所有的括号出栈 
		}
		else if(judge_perator(str[i]))//遇到操作符，时，取栈顶元素和栈外优先级进行比较。 
		{
			str1[j++] = ' ';
			n++;
			if(Operator(str[i]) <= Operator(s.GetTop()))//如果栈顶元素优先级大，直接出栈，存入str1中 
			{
				str1[j++] = s.Pop();
				n++;
			}
			if(Operator(str[i]) > Operator(s.GetTop()))//如果栈外优先级大，直接进栈 
			{
				s.Push(str[i]);
			}
		}
		i++;
	}
	while(s.GetTop())//当栈不为空时，输出栈内剩余的操作符 
	{
		str1[j++] = s.Pop();
        str1[j++] = ' ';
        n++;  
	}
}
double Get_Number(char str[],int *i) //将字符数组转换成数字 
{
	double x = 0.0;//存储转换成的数字 
	int k = 0;//存储小数点的位数 
	while(str[*i] >= '0' && str[*i] <= '9')
	{
		x = x*10 + (str[*i]-'0'); 
		(*i)++;
	}
	if(str[*i] == '.')//继续遍历 
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
		x = x/10;//小数每后一位都要除10 
		k--;
	}
	return x;
}
double Last_value(char str1[]) //后缀表达式计算数值 
{
	LinkStack <double> s;
	int i = 0;
	double n;
	double m;
	
	while(str1[i] != '#')
	{
		if(str1[i] >= '0'&& str1[i] <= '9')//当数组内为字符数时，进行转换后进栈 
		{
			s.Push(Get_Number(str1,&i));
		}
		else if(str1[i] == ' ')
		{
			i++;
		}
		else if(str1[i] == '+')//运算法则，遇到一个操作符，弹出两个操作数，进行运算，再将运算结果进栈，再继续 
	    {                      //进行遍历，直到得到最终结果 
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
		else if(str1[i] == '/')//注意出栈先后顺序，除数不能为0等 
		{
			n = s.Pop();
			m = s.Pop()/n;
			if(n == 0)
			{
				cout << "被除数不能为0 " <<endl;
			}
			s.Push(m);
			i++;
		}
	}
	return s.GetTop();
}
int Wrong_Character(char str[],int n) //判断是否存在非法字符 
{
	int flag;//做一个计算器 
	int i;
	
	for(i = 0;i < n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')//判断字符数输入是否正确 
		{
			continue;
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='.'||str[i]=='('||str[i]==')')//判断操作符 输入是否正确 
		{
			
		}
		else if(i == n-1&&str[i] == '#') //判断输入长度是否正确 
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
		cout<<"输入错误"<<endl; 
	}
	return flag;
}
int Brack_match(char str[],int n)//判断括号是否匹配 
{
	int left = 0;
	
	int right = 0;//两个计数器 
	
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
	
	if(left == right)//判断两边括号个数是否相等 
	{
		return 0;
	}
	else
	{
		cout<<"括号不匹配"<<endl;
	}
	
 } 
int judge_format(char str[],int n) //判断是否存在格式错误  
{
	int Num1 = 0;
	int Num2 = 0;
	int Num3 = 0;
	int Num4 = 0;//计数器，判断是否出错 

	for (int i = 0; i < n; i++)
	{
		if(i == 0&&(str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/'||str[i] == '.'))
		{
			cout<<"开头不能是小数点或操作符"<<endl;
			Num1++; 
		}
		if(str[i] == '.'&&str[i+1] == '.')
		{
			cout<<"小数点不能重复出现"<<endl;
			Num2++;
		}
		if((str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/')
		&&(str[i+1] == '+'||str[i+1] == '-'||str[i+1] == '*'||str[i+1] == '/'))
		{
			cout<<"操作符不能重复出现"<<endl;
			Num3++;
		}
		if((str[i] >= 'a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			cout<<"字符非法"<<endl;
			Num4++;
		}
		
	}
	return Num1+Num2+Num3+Num4;	
} 
void Fun()//操作函数 
{
	   int len;
	   int count;
	   int m = 0;
	   int n = 0; 
	   for(n=0; m == 0; n++)
	   {
	   	
	   	cout<<"请输入一个中缀表达式:"<<endl;
		
		char str[MaxSize];
		cin >> str;
	   len = strlen(str);
		str[len] = '#';
		len++;
		count = Wrong_Character(str, len)+judge_format(str, len)+Brack_match(str,len);//判断输入的表达式是否出现错误 
		
		if(count == 0)
		{
			char str1[MaxSize];
			int n = 0;
			
			MidtoLast(str, str1, n);//中缀转后缀函数调用 
			
			cout <<"后缀表达式为：";
			
			for(int i = 0;i < n;i++)
	    	{
	    		if(str1[i] == '#')
	    		{
	    			i++;
				}
	    		cout << str1[i];
			}
			
			cout << "\n后缀表达式计算结果:";  
			
	    	cout << Last_value(str1) << endl;//后缀表达式函数调用 
	    	
	    	cout << "\n是否进行运算输入？" << endl
			;
	    	cout << "\ny/Y继续运算，其余键退出:"  << endl;
	    	
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
			cout << "\n表达式错误，是否重新输入" << endl; 
			
			cout << "\ny/Y重新输入，其余键退出:";
			
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
int main()//主函数 
{
	cout<<"\n\t------------------------------------------------\n\n"<<endl;
	cout<<endl;
	cout<< "\n\t----------------简易计算器---------------\n\n"<<endl;
	cout<<endl;
	cout<<"\n\t------------------------------------------------\n\n"<<endl;
	
	Fun();
		
	return 0;
}

