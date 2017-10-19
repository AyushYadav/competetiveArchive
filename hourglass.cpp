#include <cstdio>
#include <cstdlib>
#include <iostream>

#define n 6

using namespace std;

int retCount(int arr[][n],int k, int l){   // Row count == k   Column Count == l
	int cnt=0;
	//if(n>=3) return 0;
	for(int i=k;i<(k+3);i+=2){
		for(int j=l;j<(l+3);j++){
			cnt+=arr[i][j];
            
		}
	}
    
    //cout << arr[k+1][l+1];
    cnt+=arr[k+1][l+1];
    //cout << cnt<<"\n";
	
    return cnt;
}

int retMaxCount(int arr[][n]){
	int maxCount=-1000;

	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			int cnt=retCount(arr,i,j);
			if(cnt>maxCount)
				maxCount=cnt;
		}
	}
   // cout << maxCount;
	return maxCount;
}


int main(){
	int arr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	int answer=retMaxCount(arr);
	cout << answer;

	return 0;
}
