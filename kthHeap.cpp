// http://www.practice.geeksforgeeks.org/problem-page.php?pid=700309

#include "stdc++.h"

using namespace std;
#define MAX 4

// Heap starts from 1
typedef struct Heap{
	int val;
	int i;
	int j;
}Heap;
void heapify(Heap *harr[],int i,int size);
int rightChild(int i){return (i*2)+1;}
int leftChild(int i){return i*2;}
void pop(Heap *harr[],int size){
	harr[1]->val=harr[size]->val;
	harr[1]->i=harr[size]->i;
	harr[1]->j=harr[size]->j;
	heapify(harr,1,size-1);
}

void heapify(Heap *harr[],int i,int size){
	// cout << i << " : " << harr[i]->val  << endl;
	int left=leftChild(i);
	int right=rightChild(i);
	int smallest=i;
	
	if(left<=size && harr[i]->val > harr[left]->val)
		smallest=left;

	if(right<=size && harr[smallest]->val > harr[right]->val)
		smallest=right;		
	
	cout << "HereAgain" << endl;

	if(smallest != i){
		cout << smallest << endl;
		Heap *temp=harr[smallest];
		harr[smallest]=harr[i];
		harr[i]=temp;
		heapify(harr,smallest,size);
	}else return;
}


int kthSmallest(int mat[MAX][MAX], int n, int k){
	Heap *ar=(Heap*)malloc(sizeof(struct Heap)*(n+1));
	for(int i=0;i<n;i++){
		ar[i+1].val=mat[0][i];
		ar[i+1].i=0;
		ar[i+1].j=i;
	}
	cout << "Here " << endl;
	// cout << ar[1].val << endl;
	for(int i=n/2;i>=1;i--) heapify(&ar,i,n);
	cout << " and Here" << endl;
	Heap result;
	while(k--){
		result=ar[1];
		cout << result.val << endl;
		if(result.i>=n){
			ar[1].val=INT_MAX;
			ar[1].i=n;
			ar[1].j=result.j;
		}
		else{
			ar[1].val = mat[result.i+1][result.j];
			ar[1].i = result.i+1;
			ar[1].j = result.j;
			heapify(&ar,1,n);
		}
	}
	return result.val;
}



int main(){

	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},};
  	kthSmallest(mat,4,4);
	return 0;
}