#include<stack>
#include<iostream>
#include<cstring>
#include <math.h>
#define maxsize 20
using namespace std;

class Stack{
	char A[101];
	int top;
	int max_size;
	int factors[maxsize];
	
	public:
		
	
	void Push(int x)
	{
		if(top==max_size-1)
		{
			cout<<"Stack Overflow"<<endl;
		}
		else{
			top++;
			A[top]=x;
		}
	}
	
	void Pop()
	{
		if(top==-1)
		{
			cout<<"Stack is empty"<<endl;
		}
		else{
			top--;
		}
	}
	
	int Top()
	{
		return A[top];
	}
	
	void display_stack()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<A[i]<<endl;
		}	
	}
	
	
	bool IsEmpty()
	{
		if(top==-1)
		{
			return true;
		}
		else{
			return false;
		}
	}
	
	void reverse_string(char C[],int n)
	{
		stack<char> s;
		for(int i=0;i<n;i++)
		{
			s.push(C[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			C[i]=s.top();
			s.pop();
		}
		
	}
	
	bool check_paranthesis(char exp[])
	{
		int n=strlen(exp);
		stack<char> s;
		for(int i=0;i<n-1;i++)
		{
			if(exp[i]=='(' || exp[i]=='{'|| exp[i]== '[')
			{
				s.push(exp[i]);
			}
			else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']')
			{
				if(s.empty())
				{
					return false;
				}
				
				else{
					s.pop();
					if(s.empty())
				{
					return true;
				}
				
				else{
					return false;
				}
				}
				
				
			}
		}
		
	}
	
	
};

int main()
{
	

Stack s;
char c[]="[()]";
if(s.check_paranthesis(c)==true)
{
	cout<<"Not Balanced"<<endl;
}

else{
	cout<<"Yes-Balanced"<<endl;
}


	
	
}
