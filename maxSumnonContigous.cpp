#include "stdc++.h"

using namespace std;

int sumNonConti(vector<int> ar, int n){
	int incl=ar[0];
	int excl=0;
	int excl_new;
	for(int i=1;i<n;i++){
		excl_new=max(incl,excl);
		incl=excl+ar[i];
		excl=excl_new;
	}
	cout << incl << " " << excl << " " << excl_new << endl;
	return max(incl,excl);
}


int main(){
	int ar[]={1,2,3,4,5,6};
	vector<int> v(ar,ar+6);
	cout << sumNonConti(v,6) << endl;
	return 0;
}
