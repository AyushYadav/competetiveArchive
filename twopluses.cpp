#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_ROW 15
#define MAX_COL 15

char ar[MAX_ROW][MAX_COL];
int m=MAX_ROW,n=MAX_COL;

int findMaxPlus(int centeri,int centerj){
    //cout << centeri << " " << centerj << endl;
    int span=0;
    //if(centeri==0 || centerj==0 || centeri==m-1 && centerj==n-1)return 0;
    {   
        
        int i=1;
        while(true){
            //cout << centeri <<" "<<centerj<<" "<<ar[centeri-i][centerj] << " " << ar[centeri+i][centerj] << " " << ar[centeri][centerj-i] << " H " << ar[centeri][centerj+i]  << endl;
            //cout << "Here :"<< ar[2][3];
            if(centeri-i>=0 && centerj-i>=0 && centeri+i<m && centerj+i<n && ar[centeri-i][centerj]=='G' && ar[centeri+i][centerj]=='G' && ar[centeri][centerj-i]=='G' && ar[centeri][centerj+i]=='G'){
                span++;
                //cout <<"Here";
                i++;
            }else{
                break;
            }
        }
        
    }
    return span;
}

// 1-->No Conflict
// 2-->Conflict
// change conflict function --> bug Err found
int isConflict(int i1,int j1,int s1,int i2,int j2,int s2){
    if(i1==i2 && j1==j2)return 0;
    
    //int smin=s1<s2?s1:s2;
    //int smax=s1>=s2?s1:s2;
    
    int js=1;
    for(int k=1;k<=s1;k++){
        int t1=i1-k,d1=i1+k;
        int l1=j1-k,r1=j1+k;
        if(js<=s2){
            if((t1<0||d1>=m||l1<0||r1>=n)||(t1==(i2-k)&&d1==(i2+k)&&l1==(j2-k)&&r1==(j1+k))){
                //cout << t1 << " " << d1 << " " << l1 << " " << r1 << " "<< endl;
                //cout << i2-k
                return 0;   
            }
            js++;
        }
    }
    //cout << i1<< " "<< j1<< " "<< s1<< " "<< i2 << " "<< j2<< " " << s2 << endl;
    return 1;
}

int main() {
    cin >> m >> n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin >> ar[i][j];
        }

    int area_max=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if((ar[i][j]=='G') ){
                if(i!=0 && j!=0 && i!=m-1 && j!=n-1){
                    int ret_span=findMaxPlus(i,j);
                    for(int ii=i;ii<m;ii++){
                        for(int jj=j+1;jj<n;jj++){
                            if((ar[ii][jj]=='G') ){
                                if(ii!=0 && jj!=0 && ii!=m-1 && jj!=n-1){
                                    int ret_span2=findMaxPlus(ii,jj);
                                    //cout << ret_span << " " << ret_span2 << endl;
                                    if((((ret_span*4)+1)*((ret_span2*4)+1))>=area_max){
                                        int val=isConflict(i,j,ret_span,ii,jj,ret_span2);
                                        if(val==1){
                                            //cout << i << " " << j <<" "<< ii << " "<< jj << endl;
                                            //cout << ret_span << " " << ret_span2 << endl;
                                            area_max=(((ret_span*4)+1)*((ret_span2*4)+1));
                                            //cout << "1 "<< area_max << endl;
                                        }
                                        else{
                                            if(ret_span>ret_span2){
                                                int _ret_span=ret_span-1;
                                                while(_ret_span>=0){
                                                    
                                                    int rett=isConflict(i,j,_ret_span,ii,jj,ret_span2);
                                                    if(rett==1 && ((((_ret_span*4)+1)*((ret_span2*4)+1))>=area_max)){
                                                        area_max=(((_ret_span*4)+1)*((ret_span2*4)+1));  
                                                        //cout <<"2 "<< area_max << endl;
                                                    }
                                                    _ret_span--;
                                                    
                                                }
                                            }else{
                                                int _ret_span=ret_span2-1;
                                                while(_ret_span>=0){
                                                    
                                                    int rett=isConflict(i,j,ret_span,ii,jj,_ret_span);
                                                    if(rett==1 && ((((ret_span*4)+1)*((_ret_span*4)+1))>=area_max)){
                                                        area_max=(((ret_span*4)+1)*((_ret_span*4)+1)); 
                                                        //cout << "3 "<<area_max << endl;
                                                    }
                                                    _ret_span--;
                                                }
                                            }
                                        }
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
                
        }
    }
    cout << area_max << endl;
    return 0;
}
