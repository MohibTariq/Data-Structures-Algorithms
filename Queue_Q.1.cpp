#include<iostream>
using namespace std;
struct QNode { 
    int data; 
	QNode* next;  
}; 

class Queue { 
    QNode *front, *rear; 
    public:
    Queue() 
    { 
        front = rear = NULL; 
    } 
    
    bool isEmpty()
    {
    	if((front==NULL)&&(rear==NULL))
    	{
    		return true;
		}
		else return false;

	}
    void enQueue(int x) 
	{
		QNode *tmp = new QNode;
	 	tmp->data= x;
	 	tmp->next=NULL;
 		if(isEmpty())
 		{
 			front = tmp;
 			rear = tmp;
 			cout <<"Enqueued" <<endl;
		}
		else
		{
			rear->next = tmp;
			rear = rear->next;
			cout <<"Enqueued" << endl;
		}
	 } 

    void deQueue()
    {
    	QNode *temp = front;
		front = temp->next;
		temp->next=NULL;
		cout <<"Dequeued" << endl;
	}
	
	void Display()
	{
		QNode *temp = front;
	 	while(temp!=NULL)
	 	{
	 		cout << temp->data << " ";
	 		temp = temp->next;
		 }
	}
	
	int Count()
	{
		int count = 0;
		QNode* temp = front;
		while(temp!=NULL)
		{
			count ++;
			temp=temp->next;
		}
		return count;	
	}
	

}; 

int main() 
{ 
	
    Queue q; 
    q.enQueue(10); 
    q.enQueue(20); 
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50); 
    q.enQueue(99);
    q.enQueue(1);
    q.deQueue();
    cout << "Size of Queue = " << q.Count() << endl;
}
