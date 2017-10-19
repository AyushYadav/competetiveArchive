#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	long long int rr;
	cin >> m >> n >> rr;
	int ar[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> ar[i][j];
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++)
	// 		cout << ar[i][j] <<" ";
	// 	cout << endl;
	// }
	int r=rr%(((n+m)*2)-4);
	int i=0,j=0;
	int il=m-1,jl=n-1;
	while(i<il && j<jl){
		r=rr%(((il-i+1+jl-j+1)*2)-4);
		int counter=1;
		while(counter<=r){
			//cout << counter << endl;
			int temp=ar[i][j];
			int temp2=0;
			for(int k=i+1;k<=il;k++){
				temp2=ar[k][j];
				ar[k][j]=temp;
				temp=temp2;
			}
			
			for(int k=j+1;k<=jl;k++){
				temp2=ar[il][k];
				ar[il][k]=temp;
				temp=temp2;
			}
			for(int k=il-1;k>=i;k--){
				temp2=ar[k][jl];
				ar[k][jl]=temp;
				temp=temp2;
			}
			for(int k=jl-1;k>=j;k--){
				temp2=ar[i][k];
				ar[i][k]=temp;
				temp=temp2;
			}
			counter++;
		}
		i++;
		j++;
		il--;
		jl--;

	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout << ar[i][j] <<" ";
		cout << endl;
	}
		

    return 0;
}
