#include "stdc++.h"

using namespace std;

int _maxValue(vector<int> vec, int n){
    int table[n][n];
    int gap,i,j;
    for(gap=0;gap<n;gap++){
        for(j=gap,i=0;j<n;j++,i++){
            int x,y,z;
            x=((i+2)<=j)?table[i+2][j]:0;
            y=((i+1)<=(j-1))?table[i+1][j-1]:0;
            z=(i<=(j-2))?table[i][j-2]:0;
            table[i][j]=max(vec[i]+min(x,y) ,vec[j]+min(y,z));
        }
    }
    return table[0][n-1];
}







int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin >> vec[i];
        }
        cout << _maxValue(vec,n) << endl;
    }
	return 0;
}