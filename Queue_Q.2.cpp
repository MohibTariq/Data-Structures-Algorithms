//Implement a queue which deletes all negative integers without changing the order of the
//remaining elements in the queue.(u have to use dequeue operation)



#include<iostream>
#define maxsize 10
using namespace std;

class Queue{
	int queue_array[maxsize];
	int front;
	int rear;
	
	
	public:
		
	void enQueue(int value){
		if(front == 0 && rear == maxsize - 1){
		cout << endl<< "Queue is full!!";
		} 
		
		else {
		if(front == -1) 
		front = 0;
		rear++;
		queue_array[rear] = value;
		cout << value << " ";
		}
    }
    
    int deQueue(){
		int value;
		if(front == -1){
		cout << "Queue is empty!!" << endl;
		return(-1);
		} 
		 else { 
		 value = queue_array[front]; 
		 if(front >= rear){      //only one element in queue
		front = -1;
		rear = -1;
		} 
		else {
		front++;
		}
		
		return(value);
        }
    }
    
    void display()
    {
    	int i;
		if(front == -1) {
		cout << endl << "Queue is Empty!!" << endl;
		}
		
		else{
		cout << endl << "Front = " << front;
		cout << endl << "Queue elements : ";
		for(i=front; i<=rear; i++)
		cout << queue_array[i] << "\t";
		cout << endl << "Rear = " << rear << endl;
	 }
		    }
	
    
    
	
	void delete_negative()
	{
		int i=0;
		
		while(i<=rear)
		{
			if(queue_array[i]<0)
			{
				deQueue();
			}
			i++;
		}
	}
    
    
    
		
	
	
};

int main()
{
	Queue q2,q1;
	q2.enQueue(-2);
	q2.enQueue(-1);
	q2.enQueue(5);
	q2.enQueue(6);
	q2.display();
	q2.delete_negative();
	q2.display();
	
}
