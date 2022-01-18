#include<iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
};

class LinkedList{
Node* head;
public:
 LinkedList() {
 head = NULL;
 }
 ~LinkedList() {};
 
 
int add_item(int val)
{
 Node* newnode = new Node();
 newnode->data = val;
 newnode->next = NULL;
 
 if (head == NULL) {
 head = newnode;
 }
 else {
 Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 
 }
 temp->next = newnode;
 }
 
}

void display_list()
{
if (head == NULL) {
 cout << "List is empty!" << endl;
 }
 else {
 Node* temp = head;
 while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
}


int get_Nth(int index)
{
	Node *temp=head;
	
	if(head==NULL)
	{
		cout<<"List is empty";
		return -1;		
	}
	for(int i=0;i<index;i++,temp=temp->next);
	return 	temp->data;
}
};

int main()
{
	int index;
 LinkedList *list;
 list = new LinkedList();
 list->add_item(1);
 list->add_item(2);
 list->add_item(1);
 list->add_item(3); 
 list->add_item(4);
 cout<<"Enter the index to get data of "<<endl;
 cin>>index;
 cout<<list->get_Nth(index);
 
}
