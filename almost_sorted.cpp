#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isSorted(int ar[],int n){
	for(int i=0;i<n-1;i++)
		if(ar[i]>ar[i+1])return 0;
	return 1;
}

int main() {
	int n;
	cin >> n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin >> ar[i];
	for(int i=0;i<n-1;i++){
		if(ar[i]>ar[i+1]){
			int ind=i+1;
			bool flag=true;
			for(int j=i+1;j<n && flag;j++){
				if(ar[j]>ar[i]){
					ind=j-1;
					flag=false;
				}
			}
			int temp=ar[i];
			ar[i]=ar[ind];
			ar[ind]=temp;
			int ret_val=isSorted(ar,n);
			if(ret_val==1){
				//for(int i=0;i<n;i++)cout << ar[i] << " ";
				//cout << endl;
				cout << "yes" << endl << "swap " << i+1 << " "<< ind+1 << endl;
				return 0;
			}
			else{
				int k=1;
				int p=ind;
				while((k+i)<(ind-k)){
					int tt=ar[k+i];
					ar[i+k]=ar[ind-k];
					ar[ind-k]=tt;
					k++;
					ind--;
				}
				int ret_val1=isSorted(ar,n);
				if(ret_val1==1){
					cout << "yes" << endl << "reverse " << i+1 << " "<< p+1 << endl;
					return 0;
			
				}
				//for(int i=0;i<n;i++)cout << ar[i] << " ";
				//cout << endl;
				cout << "no" << endl;
				return 0;
			}
		}
	}
    return 0;
}
