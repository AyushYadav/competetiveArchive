#include "stdc++.h"

using namespace std;

int main(){
	int t;
	while(t--){
		int n;
		cin >> n;
		while(n>9)
			n=(n/10)+(n%10);
		cout << n << endl;
	}

	return 0;
}