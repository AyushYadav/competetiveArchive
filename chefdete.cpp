#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>

using namespace std;


int main(){
    int n=0;
    cin >> n;
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        int j=0;
        cin >> j;
        arr[j]+=1;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==0)
            cout << i << " ";
    }
    cout << "\n"; 
    return 0;
}
