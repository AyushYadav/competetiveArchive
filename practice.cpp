#include "stdc++.h"

using namespace std;


int minCutStr(string s,int n){
	int C[n],p[n][n];
	for(int i=0;i<n;i++)
		p[i][i]=true;
	for(int L=2;L<=n;L++){
		for(int i=0;i<n-L+1;i++){
			int j=i+L-1;
			if(L==2)p[i][j]=s[i]==s[j];
			else
				p[i][j]=(s[i]==s[j])&&(p[i+1][j-1]);
		}
	}
	for(int i=0;i<n;i++){
		if(p[0][i]==true)C[i]=0;
		else{
			C[i]=INT_MAX;
			for(int j=0;j<i;j++){
				if(p[j+1][i]==true && 1+C[j]<C[i])
					C[i]=C[j]+1;
			}
		}
	}
	return C[n-1];
}


int matrixChainMult(int p[],int n){
	int dp[n][n];
	for(int i=0;i<n;i++) dp[i][i]=0;
	for(int L=2;L<n;L++){
		for(int i=1;i<n-L+1;i++){
			int j=i+L-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int cost=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];	
				dp[i][j]=min(cost,dp[i][j]);
			}
		}
	}
	return dp[1][n-1];
}

int longestCommonSeq(string s1,int n,string s2,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}


int editDistance(string s1,int n,string s2, int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)dp[i][j]=j;
			else if(j==0)dp[i][j]=i;
			else if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1];
			else 
				dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	return dp[n][m];
}





int main(){
 	string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
 
    cout << longestCommonSeq(str1,str1.length(), str2, str2.length()) << endl;
	// int arr[] = {1, 2, 3, 4};
 //    int size = sizeof(arr)/sizeof(arr[0]);
 //    cout << matrixChainMult(arr,size) << endl;
	// cout << minCutStr("ababbbabbababa",14) << endl;
	return 0;
}