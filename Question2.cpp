//Your friend is an Intelligence officer at Pakistan Railway; his colleague gave him news about Karachi Express incident.
//Incident: A group of People Hijack a Cabin of a Train, and one of their member is hidden somewhere in train.
//Your task is to implement the scenario using double linked list to help your friend.
//Step1: Find a Hijacked Cabin
//Step2: Than Go back to the Engine and start finding the Last member

#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* prev;
	
};


class Double_Linked_List{
	Node* head;
	
	public:
		
		Double_Linked_List()
		{
			head=NULL;
		}
		
		~Double_Linked_List() {};
		
		void add_cabin(int value)
		{
			Node* n = new Node();
			n->data=value;
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
		
	void search_hijacked_cabin(int el)
	{
		Node *temp=head;
		int i=0;
		while(temp->next!=NULL)
		{
			i++;
			if(temp->data==el)
			{
				cout<<"Hijacked Cabin is at Position "<<i<<endl;
			}
			temp=temp->next;
			
			
		}
		
		while(temp->prev!=head)
		{
			temp=temp->prev;
		}
		cout<<"Value at Start : "<<temp->data<<endl;
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		cout << "Last member: " <<temp->data << endl;
	}
    
    
    void display_list()
    {
    	Node* temp;
    	if(head==NULL)
    	{
    		cout<<"List is Empty"<<endl;
		}
		else{
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			
		}
	}
	  
};

int main()
{
	Double_Linked_List *dlist = new Double_Linked_List();
	dlist->add_cabin(1);
	dlist->add_cabin(3);
	dlist->add_cabin(0); // Hijacked Value =0
	dlist->add_cabin(5);
	dlist->add_cabin(5);
	dlist->display_list();
	dlist->search_hijacked_cabin(0);
	
	
}
