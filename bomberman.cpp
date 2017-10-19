#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int r,c,n;
    cin >> r >> c >> n;
    if(n%2==0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << 'O' ;
            }
            cout << endl;
        }
        return 0;    
    }
    
    char ar[r][c];
    char in[r][c];
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            cin >> ar[i][j];
            in[i][j]=ar[i][j];
        }
            
    int time=1;
    while(time<n){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ar[i][j]=='.'){
                    ar[i][j]='O';
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(in[i][j]=='O'){
                    ar[i][j]='.';
                    if(j>0)ar[i][j-1]='.';
                    if(j<c-1)ar[i][j+1]='.';
                    if(i>0)ar[i-1][j]='.';
                    if(i<r-1)ar[i+1][j]='.';
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                in[i][j]=ar[i][j];
                //cout << ar[i][j];
            }
            //cout << endl;
                
        }
        
        time+=2;
        //cout << time << endl;

        if(time==3 && n%4==3)break;
        if(time==5 && n%4==1)break;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout << ar[i][j];
        cout << endl;
    }
    return 0;
}
