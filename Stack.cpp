#include<stack>
#include<iostream>
#include<cstring>
#include <math.h>
using namespace std;

class Stack{
	char A[101];
	int top;
	int max_size;
	
	public:
		
	Stack()
	{
		max_size=101;
	}
	
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
	
	void prime_factors(int n)
	{
		
	  int factors[3];
	  int j=0;
	
	  while(n%2 == 0){
      cout<<"2\t";
      n = n/2;
    }
    
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
      	
        factors[j]=i;
        j++;
        n = n/i;
        
        
      }
   }
   
   stack<int> s1;
   
   for(int i=0;i<2;i++)
   {
   	 s1.push(factors[i]);
   }
   
   for(int i=0;i<2;i++)
   {
   	factors[i]=s1.top();
   	s1.pop();
   }

    for(int i=0;i<2;i++)
    {
    	cout<<factors[i]<<endl;
	}
   
	}
};

int main()
{
//	Stack s;
//	char c[51];
//	cout<<"Enter A String"<<endl;
//	gets(c);
//	s.reverse_string(c,strlen(c));
//	cout<<"Output "<<endl<<c;

//Stack s;
//char c[]="[()]";
//if(s.check_paranthesis(c)==true)
//{
//	cout<<"Yes-Balanced"<<endl;
//}
//
//else{
//	cout<<"No"<<endl;
//}

Stack s;
s.prime_factors(15);
	
	
}
