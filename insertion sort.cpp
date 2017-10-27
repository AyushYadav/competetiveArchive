#include <iostream>

using namespace std;

class Sort
{

public:
	void insert_sort(int* a,int l) //function to do insertion_sort
	{
		for (int i=1;i<=l;i++)
		{
			int key=a[i];
			int j=i-1;
			while(j>=0 && a[j]>key)
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=key;
		}
	}


};

int main()
{
	int arr[]={9,8,7,6,5,4,3,2,1}; 
	int l=sizeof(arr)/sizeof(arr[0]);
	Sort obj;
	obj.insert_sort(arr,l);
	for (int i=0;i<l;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}



