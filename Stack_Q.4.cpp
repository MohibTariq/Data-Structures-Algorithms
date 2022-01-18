#include<iostream>
#include<stack>
#define maxsize 5
using namespace std;

void reverse_stack(stack<int> &s1,stack<int> &s2)
	{
		int array[10];
		int i=0;

		while(!s1.empty())
		{
			s2.push(s1.top());
			array[i]=s1.top();
			i++;
			s1.pop();
			
		}
		i=0;
		while(!s2.empty())
		{
			s1.push(array[i]);
			cout<<array[i++]<<endl;
			s2.pop();
		}

}



int main()
{
	stack<int> s1;
	stack<int> s2;
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	reverse_stack(s1,s2);
	
}
