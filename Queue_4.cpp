#include<iostream>
using namespace std;
 
class Stack {
  private:
    int top;
 
  public:
  	int arr[5];
    Stack() {
      top = -1;
      int size = sizeof(arr)/sizeof(arr[0]);
      for (int i = 0; i < size; i++) {
        arr[i] = 0;
      }
    }
 
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }
 
  void push(int val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
      cout << "pushed" << endl;
    }
  }
  
	  int count() {
	    return (top + 1);
	  }
 
  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      cout << "Popped" << endl;
      return popValue;
    }
  }
  
    void display() {
    cout << "All values in the Stack are " << endl;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = size; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  } 
};

class Queue{
	Stack *s2 = new Stack;
		public:
			
		void enqueue(Stack &s1, int x)
		{
			
			int size = s1.count();
			while((size!=0)&&(!s1.isEmpty()))
			{
				
				s2->push(s1.pop());
				size--;
				cout << "Added to s2" << endl;
			}
			
			s1.push(x);
			int nsize = s2->count();
			while((size!=0)&&(!s2->isEmpty()))
			{
				s1.push(s2->pop());
				size--;
				cout << "Added back to s1" << endl;
			}
		}
		
		int dequeue(Stack &s1)
        {
        	if(s1.isEmpty())
        	{
        		cout << "Error" << endl;
			}
			
			else
			{
				return s1.pop();
				cout <<"value popped" << endl;
			}
		}
	
};

int main()
{
	Stack s1;
	s1.push(6);
	s1.push(6);
	s1.push(6);
	s1.push(6);
	s1.push(6);
	Queue q1;
	q1.enqueue(s1,5);
	q1.dequeue(s1);
	
}
