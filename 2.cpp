#include <bits/stdc++.h>

using namespace std;
pair<int,int> S[1000][1000];
int P[1000][1000];
int arr[1000][1000];

int findPath(int r,int c){
	int a,b,x;

	S[0][0]=make_pair(arr[0][0],arr[0][0]);
	for(int k=1;k<c;k++){
		S[0][k]=make_pair(INT_MAX-10000,arr[0][k]+S[0][k-1].second);
	}
	for(int k=1;k<r;k++){
		S[k][0]={arr[k][0]+S[k-1][0].first,INT_MAX-10000};
	}

	for (int j=1;j<r;j++){
		for(int k=1;k<c;k++){
			a = min(S[j][k-1].first+P[j][k-1],S[j][k-1].second)+arr[j][k];
			b = min(S[j-1][k].first,S[j-1][k].second+P[j-1][k])+arr[j][k];

			S[j][k]={b,a};
		}
	}

	return min(S[r-1][c-1].first,S[r-1][c-1].second);
}

int main(){
	int t,n,m;

	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		
		for (int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>arr[j][k];
			}
		}

		for (int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>P[j][k];
			}
		}

		cout<<findPath(n,m)<<endl;		
	}
}

