#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
	Node* head;
	Node* last;
	
public:
    LinkedList() { 
        head = NULL;
    }
    ~LinkedList() {}; 
    
    
	
	void traverse_beginning()
	{
		Node* temp=head;
		if(head=NULL)
		{
			cout<<"List Is Empty"<<endl;
		}
		
		else{
			while(temp!=NULL)
			{
				cout<<"Data :"<<temp->data<<endl;
				temp=temp->next;
			}
		}
	}
	
	void traverse_end()// print in reverse order
	{
		Node* temp=last;
		if(last==NULL)
		{
			cout<<"List is empty "<<endl;
		}
		
		else
		{
			while(temp!=NULL)
			{
				cout<<"Data :"<<temp->data<<endl;
				temp=temp->prev;
			}
		}
	}
	
	void insert_beginning(int val)
    {
    	Node* newnode= new Node();
    	if(head==NULL)
    	{
    		newnode->next=NULL;
    		newnode->prev=NULL;
    		newnode->data=val;
    		head=newnode;
		}
		
		else{
			newnode->data=val;
			newnode->prev=NULL;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
	}
	
	void insert_end(int val)
	{
		
		
			Node* n = new Node();
			n->data=val;
			n->prev=NULL;
			n->next=NULL;
			if(head==NULL)
			{
				head=n;
			}
			else{
				
				head->prev=n;
				n->next=head;
				head=n;
			}
		
	}
	
	void insert_n_position(int val,int index)
	{
		Node* newnode=new Node();
		Node* temp=head;
		int i;
		if(newnode==NULL)
		{
			cout<<"Unable to allocate memory "<<endl;
		}
		
		else{
			for(i=0;i<index;i++)
			{
				temp=temp->next;
				if(temp==NULL)
				{
					cout<<"Error"<<endl;
				}
			}
			
			newnode->data=val;
			newnode->next=temp->next;
			newnode->prev=temp;
			temp->next=newnode;
			temp->next->prev=newnode;
				
			}
		
	}
	
	Node* delete_end()
	{
		Node* temp;
		if(head->next==NULL)
		{
			head=NULL;
			delete head;
		}
		
		else{
			temp=head;
			if(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->prev->next=NULL;
			delete temp;
			return NULL;
		}
	}
	
	void delete_n_position(int val)
	{
		Node *ptr,*temp;
		temp=head;
		while(temp->data!=val)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			cout<<"Cant Delete"<<endl;
		}
		
		else if(temp->next->next==NULL)
		{
			temp->next=NULL;
		}
		
		else{
			ptr = temp -> next;  
            temp -> next = ptr -> next;  
            ptr -> next -> prev = temp;
            delete ptr;
		}
	}
	
	
	
	
	
};
    
    
    int main()
    {
       LinkedList *list;
	   list = new LinkedList();
	   list->insert_beginning(3);
	   list->insert_beginning(7);
	   list->insert_beginning(8);
	   list->traverse_beginning();
	   list->insert_end(1);
	   list->traverse_beginning();
	   list->delete_n_position(3);
	   list->traverse_beginning();
	}
