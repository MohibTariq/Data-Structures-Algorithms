//Your task is to create a class DSA in DSA.h file and declare two functions ‘insertion’ and ‘searching’ in it
//in addition to the functions discussed in the rule of three. Now inherit two classes ‘Ordered Dynamic
//Safe Array’ and ‘Unordered Dynamic Safe Array’ and implement both the functions for these classes.

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std;

class DSA{
	

   int *Data;
   int size;
   
    public:
    	
    DSA(){
    Data=NULL;
    size=0;
}

DSA(int n){
size=n;
Data= new int[size];
memset(this->Data, 0, sizeof(int)*size); 
}

int getSize()
{
	return size;
}

DSA(const DSA & rhs){
this->size= rhs.size;
this->Data= new int[size];
//memcpy(this->Data,rhs.Data,(sizeof(int)*rhs.getSize()));
}

~DSA()
{
if(Data !=0)
{
cout<<"Object Deleted !!"<<endl;
delete [] Data;
Data=0;
size=0; }
}

void insert_element(int e)
{
	for(int i=0;i<size;i++)
	{
	Data[i]=e;
}
	cout<<"Element Entered in Array "<<endl;
}

void search_element()
{
	int n;
	cout<<"Enter Value to Search :"<<endl;
	cin>>n;
	
	for(int i=0;i<size;i++)
	{
		if(n==Data[i])
		{
			cout<<"Element Found "<<endl;
			cout<<"Element found at position"<<i<<endl;
		}
		
		else{
			cout<<"Element not Found"<<endl;
			exit(1);
		}
	}
}

int&  operator[](int i)
			{
				if((i>=size )||(i<0))
				{
					cout<<"Out of Bound - Error"<<endl;
				}
			return *(Data+i) ;
			}
	
	
  void display_elements()
  {
  	cout<<"Elements in Array :"<<endl;
  	for(int i=0;i<size;i++)
  	{
  		cout<<Data[i];
  		cout<<endl;
	}
  }
  
};

//class OrderedArray():public DSA
//{
//	
//}

int main()
{
	int asize,element;
	
	cout<<"Enter Size of the array :"<<endl;
	cin>>asize;
	
	DSA *d;
	d=new DSA[5];
	for(int i=0;i<5;i++)
	{
	
	
	cout<<"Enter the element you want to insert :"<<endl;
	cin>>element;
	
	(*(d+i)).insert_element(element);

}
	
//	// to search an element
//	for(int i=0;i<5;i++)
//	{
//		(*(d+i)).search_element;
//	} 
	
	
}

//// for checking out of bound
//for(int i=0;i<5;i++)
//{
//cout<<(*(d+i)).getsize();
//}


