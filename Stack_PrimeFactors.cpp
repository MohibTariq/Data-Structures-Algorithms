#include<iostream>
#include<cmath>
using namespace std;
#define stacksize 100

class stack
{
	public:
	int top;
	int items[stacksize];
};

class Stacks
{
	stack *ps;
	
	public:
	Stacks()
	{
		ps= new stack;
		ps->top=0;
	}
	
	void push(int item)
	{
		if(is_full())
		{
			cout<<"Stack Overflow"<<endl;
			return;
		}
		
		ps->items[ps->top]=item;
		ps->top++;
	}
	int pop()
	{
		if(is_empty())
		{
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		ps->top--;
		return ps->items[ps->top];
	}
	void peek()
	{
		cout<<ps->items[ps->top];
	}
	
	bool is_empty()
	{
		return ps->top==0;
	}
	
	bool is_full()
	{
		return ps->top==stacksize-1;
	}

	void reverse_stack()
	{
		int temp[ps->top],i=0;
		while(ps->top>0)
		{
			temp[i]=pop();
			i++;
		}
		while(i>0)
		{
			push(temp[ps->top]);
			i--;
		}
	}
};

void prime_factors(Stacks obj,int n)
{
	while(n%2==0)
	{
		obj.push(2);
		n/=2;
	}

	for(int i=3;i<=int(sqrt(n));i+=2)
	{
		while(n%i==0)
		{
			obj.push(i);
			n/=i;
		}
	}
	if(n>2)
	obj.push(n);	
}

int main()
{
	Stacks obj;
	int n;
	cout<<"Enter number to calculate prime factors: ";
	cin>>n;
	
	prime_factors(obj,n);
	
	obj.reverse_stack();
	
	cout<<obj.pop();
	while(!obj.is_empty())
	{
		cout<<" * "<<obj.pop();
	}
	
	
}





