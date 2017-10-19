#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int p=1;p<=t;p++){
        int n;
        cin >> n;
        char ar[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin >> ar[i][j];
            sort(ar[i],ar[i]+n);
        }
        bool flag=true;
        for(int i=0;i<n && flag ;i++){
            for(int j=0;j<n-1;j++){
                if(ar[j][i]>ar[j+1][i]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;


        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout << ar[i][j] << " ";
        //     cout << endl;
        // }
            
        
    }
    return 0;
}
