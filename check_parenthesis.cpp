#include<iostream>
#include<cstring>
using namespace std;
#define stacksize 100

class stack
{
	public:
	int top;
	char items[stacksize];
};

class Stacks
{
	stack *ps;
	int bracket_count;
	int braces_count;
	
	public:
	Stacks()
	{
		ps= new stack;
		ps->top=0;
		bracket_count=0;
		braces_count=0;
	}
	
	void push(char item)
	{
		if(is_full())
		{
			cout<<"Stack Overflow"<<endl;
			return;
		}
		
		if(item=='(')
		bracket_count++;
		
		if(item=='{')
		braces_count++;		
	
		ps->items[ps->top]=item;
		ps->top++;
	}
	char pop()
	{
		if(is_empty())
		{
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		ps->top--;
		
		if(ps->items[ps->top]==')')
		bracket_count--;
		
		if(ps->items[ps->top]=='}')
		braces_count--;
		
		if(braces_count<0 || bracket_count<0)
		{
			cout<<"Unmatching grouping symbols";
			return 0;
		}
		
		return ps->items[ps->top];
	}
	void peek()
	{
		cout<<ps->items[ps->top];
	}
	
	bool last_check()
	{
		return (braces_count!=0 || bracket_count!=0);
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
	void print()
	{
		cout<<braces_count;
		cout<<bracket_count;
	}
};

int main()
{
	Stacks obj;
	string exp;
	cout<<"Enter expression: ";
	cin>>exp;
	
	for(int i=0;i<exp.length();i++)
	obj.push(exp[i]);
	
	while(!obj.is_empty())
	{
		if(obj.pop()==0)
		exit(1);
	}
	if(obj.last_check())
	{
		cout<<"Unmatching grouping symbols";
		exit(1);		
	}	
	
	obj.print();
	cout<<"Matching grouping symbols";


}



