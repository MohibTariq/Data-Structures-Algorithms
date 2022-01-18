#include<iostream>
using namespace std;

#define max_size 100

class Queue
{
	int front,rear;
	int queue_array[max_size];
	
	public:
	Queue()
	{
		front=-1;
		rear=-1;	
	}
	bool is_empty()
	{
		return (front==-1);
	}
	void enqueue(int item)
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		queue_array[rear]=item;
	}
	int dequeue()
	{
		if(is_empty())
		{
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		if(front>=rear)
		{
			front=-1;
		}
		return queue_array[rear--];
	}
	
	void reverse()
	{
		int temp[rear+1];
		int i=0;
		while(!is_empty())
		{
			temp[i]=dequeue();
			i++;
		}

		int j=0,item;
		while(i>0)
		{
			item=temp[j];
			enqueue(item);
			i--;
			j++;
		}
	}
	
	void display()
	{
		for(int i=0;i<rear+1;i++)
		cout<<queue_array[i]<<"  ";
	}
};

int main()
{
	Queue obj;
	
	for(int i=0;i<10;i++)
	obj.enqueue(i);
	
	cout<<"Original :"<<endl;
	obj.display();
	obj.reverse();
	cout<<endl;
	cout<<"Reverse :"<<endl;
	obj.display();	
}


