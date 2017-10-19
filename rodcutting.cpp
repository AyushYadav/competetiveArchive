#include "stdc++.h"

#define size(ar) sizeof(ar)/sizeof(ar[0])

using namespace std;

int rodcuting(int ar[], int n){
	int table[n+1];
	table[0]=0;
	for(int i=1;i<=n;i++){
		int max=INT_MIN;
		for(int j=0;j<i;j++){
			if(max < (table[i-j-1]+ar[j]))
				max=table[i-j-1]+ar[j];
		}
		table[i]=max;
	}
	return table[n];
}


int main(){
	int ar[]={1, 5, 8, 9, 10, 17, 17, 20};
	int n=size(ar);
	cout << rodcuting(ar,n) << endl;
	return 0;
}
