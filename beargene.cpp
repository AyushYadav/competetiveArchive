#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ar[4]={0,0,0,0};
    int countA=0,countC=0,countG=0,countT=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'){
            ar[0]+=1;
            if(ar[0]>(n/4))countA++;
        }
        else if(s[i]=='C'){
            ar[1]+=1;
            if(ar[1]>(n/4))countC++;
        }
        else if(s[i]=='G'){
            ar[2]+=1;
            if(ar[2]>(n/4))countG++;
        }
        else if(s[i]=='T'){
            ar[3]+=1;
            if(ar[3]>(n/4))countT++;
        }
    }
    //cout << countA << " "<< countC <<" "<<countG <<" "<<countT << endl;
    int min=INT_MAX;
    int i=0;
    int countTotal=countA+countC+countG+countT;
    do{
        if((countA>0 && s[i]=='A') || ((countC>0 && s[i]=='C') || ((countG>0 && s[i]=='G') || ((countT>0 && s[i]=='T')){
            int l=countTotal;
            string ss=substr(i,l);

            for(int i=0;i<ss.length();i++){
                if(ss[i]=='A'){
                    _countA++;
                }
                else if(ss[i]=='C'){
                    _countC++;
                }
                else if(ss[i]=='G'){
                    _countG++;
                }
                else if(ss[i]=='T'){
                    _countT++;
                }
            }
                            


        }
        

    }while(min<s.length()); //NOT RIGHT CONDITION

    return 0;
}
