#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
}


int main()
{
	int num[7]={10,6,7,5,4,2,1};
	
	bubble_sort(num,7);
	
	for(int i=0;i<7;i++)
	{
		cout<<num[i];
		cout<<endl;
	}
}
