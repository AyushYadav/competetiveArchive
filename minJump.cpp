#include "stdc++.h"

using namespace std;

int min(int a, int b){return a<b?a:b;}


int minJumps(int ar[], int n){
	if(n==0 || ar[0]==0)return -1;
	int jmp[n];
	jmp[0]=0;
	for(int i=1;i<n;i++){
		jmp[i]=INT_MAX;
		for(int j=0;j<i;j++)
			if(i<=j+ar[j] && jmp[j]!=INT_MAX)
				jmp[i]=min(jmp[i],jmp[j]+1);
	}
	return jmp[n-1];
}

int main(){
	int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    cout << minJumps(arr,size) << endl;
	return 0;
}