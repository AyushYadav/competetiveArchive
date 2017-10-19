#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int smallest(int ar[],int n){
	int min=INT_MAX;
	int ind=-1;
	for(int i=0;i<n;i++){
		if(ar[i]<min){
			min=ar[i];
			ind=i;
		}
	}
	return ind;
}

int main() {
	int n;
	cin >> n;
	int td[n];
	for(int i=0;i<n;i++){
		int t1,t2;
        cin >> t1 >> t2;
		td[i]=t1+t2;
	}
	for(int i=0;i<n;i++){
		int ret_ind=smallest(td,n);
		cout << ret_ind+1 << " ";
		td[ret_ind]=INT_MAX;
	}
    return 0;
}
