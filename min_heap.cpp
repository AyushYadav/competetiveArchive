#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int curr=0;
void swap(int a,int b,int arr[]){
	int t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}

int leftChild(int arr[],int i){return arr[2*i];}

int rightChild(int arr[],int i){return arr[(2*i)+1];}

int parentOf(int i){
	if(i%2==0)return i/2;
	else return (i-1)/2;
}

int linSearch(int arr[], int v){
	for(int i=1;i<=curr;i++){
		if(arr[i]==v)
			return i;
	}
	return 0;
}

void heapify(int arr[],int j){ //first call should have j=1
	int left=leftChild(arr,j);
	int right=rightChild(arr,j);	
	if((arr[j]<left)&&(arr[j]<right))
		return;
	if(left<right && left<arr[j]){
		swap((2*j),j,arr);
		heapify(arr,(2*j));

	}else if(right < left && right < arr[j]){
		swap(j,((2*j)+1),arr);
		heapify(arr,((2*j)+1));
	}
	return;

}

void insertMinHeap(int arr[],int v){
	arr[++curr]=v;
	int j=curr;
	int t=v;
	while(j>1 && arr[j]<arr[parentOf(j)]){
		if(arr[parentOf(j)]>arr[j]){
			int temp=arr[parentOf(j)];
			arr[parentOf(j)]=arr[j];
			arr[j]=temp;
			j=parentOf(j);
			

		}
	}
}

void deleteMinHeap(int arr[],int v){
	int t=linSearch(arr,v);
	arr[t]=arr[curr];
	curr--;
	heapify(arr,1);
}
void popMin(int arr[]){
	cout << arr[1] << "\n";
}

int main() {
    int n=0;
    cin >> n;
    int arr[n];
    for(int i=1;i<=n;i++){
    	int ch=0;
    	cin >> ch;
    	if(ch==1){
    		int val;
    		cin >> val;
    		curr++;
    		insertMinHeap(arr,val);
    	}else if(ch==1){
    		int val;
    		cin >> val;
    		curr--;
    		deleteMinHeap(arr,val);
    	}else if(ch==3){
    		popMin(arr);
    	}
    }
    return 0;
}
