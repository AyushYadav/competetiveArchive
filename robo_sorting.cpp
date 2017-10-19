#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int smallest(int ar[],int n,int start){
	int i=start;
	int ind=-1;
	int min=INT_MAX;
	while(i<=n){
		if(ar[i]<min){
			min=ar[i];
			ind=i;
		}
		i++;
	}
	return ind;
}

int isSorted(int ar[],int n){
	for(int i=1;i<n;i++)
		if(ar[i]>ar[i+1])return 0;
	return 1;
}

int main() {
	int t;
	cin >>t;
	for(int p=1;p<=t;p++){
		int n;
		cin >> n;
		int ar[n+1];
		for(int i=1;i<=n;i++)
			cin >> ar[i];
		//bool flag=true;
		for(int i=1;i<=n;i++){
			int ret=smallest(ar,n,i);
			if(ret==i){
				//cout << ar[ret]  << " " << i<< endl;
				continue;	
			}
			else{ // Use value of ret not i
				//cout << ar[i] << endl;
				if(((ret-2)>=1) && ((ar[ret-2]!=(ret-2)) || (ar[ret-2]>ar[ret]))){
					int temp=ar[ret];
					ar[ret]=ar[ret-1];
					ar[ret-1]=ar[ret-2];
					ar[ret-2]=temp;
					i--;
				}else if(((ret-1)==1 && ret<n)|| (ar[ret-2]==(ret-2) && ret<n) ){
					//cout << i << endl;
					int temp=ar[ret];
					ar[ret]=ar[ret+1];
					ar[ret+1]=ar[ret-1];
					ar[ret-1]=temp;
					i--;
				}
				//for(int i=1;i<=n;i++)cout << ar[i] << " ";
				//cout <<  endl;
			}
		}
		if(isSorted(ar,n)==0){
			cout << "NO" << endl;
			//for(int i=1;i<=n;i++)cout << ar[i] << " ";
		}
		else cout << "YES" << endl;

	}  
    return 0;
}
