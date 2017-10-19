#include "stdc++.h"

using namespace std;

bool isGoodString(string s){
	int len=s.length();
	for(int i=0;i<len-1;i++){
		char first=s[i];
		char second=s[i+1];
		int diff=abs(second-first);
		if(diff!=1 || diff!=25)
			return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(isGoodString(s))cout << "YES" << endl;
		else cout << "NO" << endl;
 	}
	return 0;
}
