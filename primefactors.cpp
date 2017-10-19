#include "stdc++.h"

using namespace std;


void printPrimeFactorsPowers(int n){
	map<int , int > mp;
	map<int, int>::iterator it;
	int m=n;
	for(int i=2;i<=m/2;i++){
		// cout << i << endl;
		while(n%i==0){
			it=mp.find(i);
			if(it==mp.end()){
				mp.insert(make_pair(i,1));
			}
			else {
				it->second+=1;
			}
			// cout << n << endl;
			n=n/i;
		}
	}
	for(it=mp.begin();it!=mp.end();it++){
		cout << it->first << " " << it->second << " " ;
	}
}


int main(){	
	int t;
	cin >> t;
	while(t>0){
		t--;
		int n;
		cin >> n;
		printPrimeFactorsPowers(n);
		cout << endl;

	}
	return 0;
}