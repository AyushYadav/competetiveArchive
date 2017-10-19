#include "stdc++.h"

using namespace std;
#define MAX_SIZE 20

struct heap
{
	int val,r,c;
};

void swap(heap* a, heap* b){
	heap* t=a;
	*a=*b;
	*b=*t;
}

void minHeapify(heap harr[], int i, int size){
	int l=i*2+1;
	int r=(i*2)+2;
	int small=i;
	if(l<size && harr[l].val < harr[i].val)
		small=l;
	if(r<size && harr[r].val < harr[small].val)
		small=r;
	if(small!=i){
		swap(&harr[i],&harr[small]);
		minHeapify(harr,small,size);
	}
}

void kthSmallestValue(int ar[4][4], int k, int n, int m){
	if(k<=0 || k>(n*m)){
		cout << "Err" << endl;
		return ;
	}
	int size=m;
	heap harr[size];
	for(int i=0;i<m;i++){
		harr[i].val=ar[0][i];
		harr[i].r=0;
		harr[i].c=i;
	}
	int i=(m-1)/2;
	while(i>=0){
		minHeapify(harr,i,size);
		i--;
	}
	
	while(k>0){
		k--;
		if(k==0){
			cout << harr[0].kthSmallestValue << endl;
			return;
		}
		heap hh=harr[0];
		int nextval = (hh.r < (n-1))? ar[hh.r + 1][hh.c]: INT_MAX;
 		// cout << nextval << endl;
	    harr[0].val =  nextval;
	    harr[0].r = (hh.r) + 1;
	    harr[0].c = hh.c;
	    minHeapify(harr, 0, size);
	}

}


int main(){
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},};
  	kthSmallestValue(mat ,  4 , 4 , 4 );

	return 0;
}