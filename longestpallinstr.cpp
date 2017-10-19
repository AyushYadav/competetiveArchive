#include <iostream>
#include <string>

using namespace std;

int longestPallinStr(string s,int n){
	if(n==0 || n==1)return n;
	int start = -1, last = -1;
	int max_start=-1,max_end=-1;
	int maxlen=-1;
	for(int i=1;i<(n-1);i++){
		start=i-1;
		last=i;
		int len=0;
		while(start>=0 && last<n &&s[start]==s[last]){
			len+=2;
			start--;
			last++;
		}
		if(len>maxlen){
			maxlen=len;
			max_start=start+1;
			max_end=last-1;
		}
		len=1;
		start=i-1;
		last=i+1;
		while(start>=0 && last<n && s[start]==s[last]){
			start--;
			last++;
			len+=2;
		}
		if(len>maxlen){
			maxlen=len;
			max_start=start+1;
			max_end=last-1;
		}
	}
	for(int i=max_start;i<=max_end;i++)cout << s[i];
	cout << endl;
	return maxlen;
}


int main(){
	string s="banana";
	// cin >> s;
	cout << longestPallinStr(s, s.length()) << endl;
	return 0;
}
