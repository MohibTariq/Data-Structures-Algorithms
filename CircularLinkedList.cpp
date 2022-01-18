#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class Circular_Linked_List{
	
	Node *head;
	
	public:
		Circular_Linked_List()
		{
			head=NULL;
		}
		
		void append_node(int val)
		{
			Node* newnode = new Node();
            newnode->data = val;
            if(head==NULL)
            {
            	head=newnode;
            	newnode->next=head;
			}
			
			else{
				Node* temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				temp->next=newnode;
				newnode->next=head;
				cout<<"Node successfully Appended !"<<endl;
			}
		}
		
		void display_CLL()
		{
			if (head == NULL) {
            cout << "List is Empty "<<endl;
            }
			else {
 
            Node* temp = head;
            do
			{
				cout << temp->data <<" ";
				temp = temp->next;
			}while(temp!=head);
		}
		}
		
		void search_node(int el)
		{
		Node *temp= head;
		int position=0;
    	
    	while (temp->next != head)
    	{
    		position++;
    		if(temp->data==el)
    		{
    			cout<<"Element found : "<<temp->data<<endl;
    			cout<<"Found At Position "<<position<<endl;
			}
			temp=temp->next;
		}
		}
		
		void insert_n_position(int index,int num)
		{
			Node* new_node=new Node();
			Node* currentnode;
			int i;
			
			if(head== NULL)
			{
				cout<<"EMpty List"<<endl;
			}
			
			else{
				new_node->data=num;
				currentnode=head;
				for(i=0;i<=index-1;i++)
				{
					currentnode=currentnode->next;
				}
				new_node->next=currentnode->next;
				currentnode->next=new_node;
			}
		}
		
		void delete_from_start()
		{
			Node *temp=head;
            if (head == NULL)
            {
            	cout<<"List is empty "<<endl;
			}
 
   
            else{
            	if(temp->next!=head)
            	{
            		head=head->next;
            		temp->next=head;
            		
				}
				
				cout<<"First Node Deleted "<<endl;
			}
 
            
		}
		
		void delete_n_position(int value)
		{
			Node* temp= head;
			Node* temp2=temp->next;
			
			while(temp2!=head){
				if(temp2->data==value){
					temp->next=temp2->next;
				}
				temp=temp->next;
				temp2=temp2->next;
			}
			
			
			
		}
			
};

int main()
{
	Circular_Linked_List *list=new Circular_Linked_List();
	list->append_node(2);
	list->append_node(3);
	list->append_node(4);
	list->append_node(5);
	list->insert_n_position(2,6);
	cout <<"Display"<<endl;
	list->display_CLL();
	list->search_node(6);
	list->delete_from_start();
	list->display_CLL();
	cout<<endl;
	list->delete_n_position(4);
	list->display_CLL();
	
}

