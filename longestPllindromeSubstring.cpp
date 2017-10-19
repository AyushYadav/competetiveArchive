#include "stdc++.h"

using namespace std;

int longestPallinSubstring(string s, int n){
	bool table[n][n];
	memset(table,0,sizeof(table));
	int maxlength=1;
	int starting=0;
	for(int i=0;i<n;i++)table[i][i]=true;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			table[i][i+1]=true;
			maxlength=2;
			starting=i;
		}
	}
	for(int k=3;k<=n;k++){
		for(int i=0;i<n-k+1;i++){
			int j=i+k-1;
			if(table[i+1][j-1] && s[i]==s[j]){
				table[i][j]=true;
				if(k>maxlength){
					maxlength=k;
					starting=i;
				}
			}
		}
	}
	for(int i=starting;i<starting+maxlength;i++)
		cout << s[i];
	cout << endl;
	return maxlength;
}

int main(){
	string s= "forgeeksskeegfor";
	cout <<longestPallinSubstring(s,s.length())<< endl;
	return 0;
}