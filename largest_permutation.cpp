#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int largest(int ar[],int n, int start){
	if(start==n-1)return start;
	int max=INT_MIN;
	int ind=-1;
	for(int i=start;i<n;i++){
		if(ar[i]>max){
			max=ar[i];
			ind=i;
		}
	}
	return ind;
}

int main() {
	int n;
	long long int k;
	cin >> n >> k;
	if(k>=(n-1)){
	    for(int i=0;i<n;i++)cout << (n-i) << " ";
	    return 0;
	}
	int ar[n];
	for(int i=0;i<n;i++)cin >> ar[i];
	bool flag=true;
	
	int j=0;
	for(int i=0;i<k && flag && j<n ;i++){
		int ret_ind=largest(ar,n,j);
		if(ret_ind==j && j==(n-1) ){
			flag=false;
			break;	
		}
		if(ret_ind==j){
			j++;
			i--;
		}
		else{
			int temp=ar[ret_ind];
			ar[ret_ind]=ar[j];
			ar[j]=temp;
			j++;
		}
		
	}
	
	for(int i=0;i<n;i++)cout << ar[i] << " ";
    
    return 0;
}
