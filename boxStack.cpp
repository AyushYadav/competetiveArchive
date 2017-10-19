#include "stdc++.h"

using namespace std;

typedef struct Box{
	int h,l,b;
}Box;

int max(int a,int b){return a>=b?a:b;}
int min(int a, int b){return a<b?a:b;}
bool compare(Box a, Box c){
	if(a.l*a.b > c.l*c.b)return true;
	return false;
}

int maxBoxHeight(Box ar[], int n){
	Box rot[3*n];
	int index=0;
	for(int i=0;i<n;i++){
		// taking the box as it is
		rot[index]=ar[i];
		index++;
		// taking the first rotation
		rot[index].h=ar[i].b;
		rot[index].b=min(ar[i].h,ar[i].l);
		rot[index].l=max(ar[i].h,ar[i].l);
		index++;
		// taking the second rotation
		rot[index].h=ar[i].l;
		rot[index].b=min(ar[i].h,ar[i].b);
		rot[index].l=max(ar[i].h,ar[i].b);
		index++;
	}
	n=3*n;
	sort(rot,rot+n,compare);
	int table[n];
	for(int i=0;i<n;i++)
		table[i]=rot[i].h;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(rot[j].b>rot[i].b && rot[i].l<=rot[j].l && table[i]<table[j]+rot[i].h)
				table[i]=table[j]+rot[i].h;
		}
	}
	int max=INT_MIN;
	for(int i=0;i<n;i++)
		if(table[i]>max)max=table[i];
	return max;
}


int main(){
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  	int n = sizeof(arr)/sizeof(arr[0]);
  	cout << maxBoxHeight(arr,n) << endl;
	return 0;
}