#include "stdc++.h"

using namespace std;

#define SIZE 100
int vec[SIZE][SIZE];

//vector<vector<int> > vec,
int missingvalue(int n){
 	if(n==1)return 0;
	int r,c;
	int rc=-1;
	for(int i=0;i<n;i++)
		for(int j=0;i<n;j++)
			if(vec[i][j]==0){
				r=i;
				c=j;
			}
	if(r>0)rc=0;
	else rc=r+1;
	int sum=0,sum_missing=0;
	
	for(int i=0;i<n;i++)
		sum+=vec[rc][i];
	for(int i=0;i<n;i++)
		sum_missing+=vec[c][i];
	vec[r][c]=sum-sum_missing;
	for(int i=0;i<n;i++){
		int sum_row=0;
		for(int j=0;j<n;j++)
			sum_row+=vec[i][j];
		if(sum_row!=sum)return -1;

	}
	for(int i=0;i<n;i++){
		int sum_col=0;
		for(int j=0;j<n;j++)
			sum_col+=vec[j][i];
		if(sum_col!=sum)return -1;
	}
	int sum_diag1=0,sum_diag2=0;
	for(int i=0;i<n;i++){
		sum_diag1+=vec[i][i];
		sum_diag2+=vec[i][n-i-1];
	}
	if(sum_diag1!=sum || sum_diag2!=sum)return -1;
	return vec[r][c];
}


int main(){
	int n;
	cin >> n;
	// vector< vector<int> >vec(n, vector<int>(n,-1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin >> vec[i][j];
	}
	cout << vec[0][0] << " " << vec[0][1] << " " << vec[1][0] << " " << vec[1][1] << endl;
	cout << missingvalue(n) << endl;
	return 0;
}



/*
if(n==1){
		cout << vec[0][0] << endl;
		return 0;
	}
	
	
	int r,c;
	int rc=-1,cc=-1;
	for(int i=0;i<n;i++)
		for(int j=0;i<n;j++)
			if(vec[i][j]==0){
				r=i;
				c=j;
			}
	if(r>0)rc=0;
	else rc=r+1;
	int sum=0,sum_missing=0;
	
	for(int i=0;i<n;i++)
		sum+=vec[rc][i];
	for(int i=0;i<n;i++)
		sum_missing+=vec[c][i];
	vec[r][c]=sum-sum_missing;
	for(int i=0;i<n;i++){
		int sum_row=0;
		for(int j=0;j<n;j++)
			sum_row+=vec[i][j];
		if(sum_row!=sum){
			cout << "-1" << endl;
			return 0;
		}

	}
	for(int i=0;i<n;i++){
		int sum_col=0;
		for(int j=0;j<n;j++)
			sum_col+=vec[j][i];
		if(sum_col!=sum){
			cout << "-1" << endl;
			return 0;
		}
	}
	int sum_diag1=0,sum_diag2=0;
	for(int i=0;i<n;i++){
		sum_diag1+=vec[i][i];
		sum_diag2+=vec[i][n-i-1];
	}
	if(sum_diag1!=sum || sum_diag2!=sum){
		cout << "-1" << endl;
		return 0;
	}
	cout << vec[r][c] << endl;
	

*/
