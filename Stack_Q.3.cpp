//Two stacks of the same type are the same if they have the same number of elements and their
//elements at the corresponding positions are the same. Overload the relational operator == for
//the class stackType that returns true if two stacks of the same type are the same, false
//otherwise. Also, write the definition of the function template to overload this operator.




#include<iostream>
#include<stack>
using namespace std;

class Stack{
	
	public:
		
	bool operator ==(stack<int> s2)
	{
		stack<int> s1;
		bool flag=true;
		
		// Checking of size
		if(s1.size() != s2.size())
		{
			flag=false;
			return flag;
		}
		
		while(s1.empty()==false)
		{
			
			
		if(s1.top()==s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else{
			flag=false;
			break;
		}
	}
	
	return flag;
	}
		
	
	
};

int main()
{
	stack<int> s1;
	stack<int> s2;
	Stack s;
	s1.push(4);
	s1.push(5);
	s1.push(3);
	s2.push(4);
	s2.push(5);
	s2.push(3);
	if(s1==s2)
	{
		cout<<"Both Stacks are the same "<<endl;
	}
	
	else{
		cout<<"Stacks are not the same "<<endl;
	}
	
	
}
