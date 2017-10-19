#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        int G[R][C];
        for(int G_i = 0;G_i < R;G_i++){
            for(int j=0;j<C;j++){
                cin >> G[G_i][j];
                //cout << G[G_i][j] << " ";
            }          
           // cout << endl;
        }
        
        int r;
        int c;
        cin >> r >> c;
        int P[r][c];
        for(int P_i = 0;P_i < r;P_i++){
           for(int j=0;j<c;j++){
               cin >> P[P_i][j];
               //cout << P[P_i][j] << " ";
           }
           // cout<<endl;
        }
        int k=0;
        int l=0;        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(G[i][j]==P[0][0]){
                    if((i+r <= R)&&(j+c <= C)){
                        int ii=i;
                        int jj=j;
                        int ch=0;
                        int cnt=0;
                        k=0;
                        l=0;
                        while(k<r){
                            while(l<c){
                                if(G[ii][jj]==P[k][l]){
                                    jj++;
                                    l++;
                                    cnt++;
                                }else{
                                    ch=-1;
                                    cnt=0;
                                    break;
                                    
                                }
                            }
                            if(ch==-1)break;
                            else{
                                ii++;
                                jj=j;
                                k++;
                                l=0;
                            }
                        }
                        if(cnt==(r*c)){
                            cout << "YES" <<endl;
                            cnt=0;
                        }
                        else{
                            cout << "NO"<< endl;
                        }
                    }
                }
               // k=0;
                //l=0;
            }
        }
        //cout << "NO"<< endl;
    }
    return 0;
}
