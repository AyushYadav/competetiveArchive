#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
	int n;
	long long int k;
	cin >> n >> k;
	if(k>=(n-1)){
	    for(int i=0;i<n;i++)cout << (n-i) << " ";
	    return 0;
	}
	int ar[n],pos[n];
	for(int i=0;i<n;i++){
		cin >> ar[i];
		pos[ar[i]-1]=i;	
	}
	int j=n-1;
	int jj=0;
	for(int i=0;i<k && j>=0 && jj<n ;i++){
		int ind=pos[j];
		if(jj==ind){
			jj++;
			j--;
			i--;
		}else{
			int temp=ar[ind];
			ar[ind]=ar[jj];
			pos[ar[ind]-1]=ind;
			ar[jj]=temp;
			pos[ar[jj]-1]=jj;
			jj++;
			j--;
		}
	}




	for(int i=0;i<n;i++)cout << ar[i] << " ";
    
    return 0;
}
