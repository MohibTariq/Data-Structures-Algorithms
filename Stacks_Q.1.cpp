#include<stack>
#include<iostream>
#include<cstring>
#include <math.h>
#define maxsize 20
using namespace std;

class Stack{
	int top;
	int A[5];
	int factors[maxsize];
	
	public:
		
	
	void Push(int x)
	{
		if(top==maxsize-1)
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
	
	
	void prime_factors(int n)
	{
		
	  stack<int> s1;
	  int j=0;
	
	  while(n%2 == 0){
      cout<<"2\t";
      n = n/2;
    }
    
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
      	
        factors[j]=i;
        s1.push(factors[j]);
        j++;
        n = n/i;
        
        
      }
   }
   
   
   
//   for(int i=0;i<2;i++)
//   {
//   	 s1.push(factors[i]);
//   }
//   
//   for(int i=0;i<2;i++)
//   {
//   	factors[i]=s1.top();
//   	s1.pop();
//   }

    
   
	}
	
	void display()
	{
	for(int i=0;i<top;i++)
    {
    	cout<<factors[i]<<endl;
	}
	}
};

int main()
{

Stack s;
s.Push(5);
s.Push(6);
s.Push(7);
s.Push(2);
s.Push(1);
s.display();
	
	
}
