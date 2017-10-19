#include "stdc++.h"

using namespace std;

int noOfUniqueChars(string s){
    vector<int> ar(256,0);
    for(int i=0;i<s.length();i++){
        int ch=(int)s[i];
        if(ar[ch]==0)ar[ch]=1;
    }
    int count=0;
    for(int i=0;i<256;i++)
        if(ar[i]==1)count++;
    return count;
}
bool isEqual(string s, string ss, int n){
    for(int i=0;i<n;i++)
        if(s[i]!=ss[i])return false;
    return true;
}

bool isValidSubs(string s,int n, string sub,int j){
    if(n%j!=0)return false;
    for(int i=0;i<n;i+=j){
        string tmp=s.substr(i,j);
        if(isEqual(sub,tmp,j))continue;
        else return false;
    }
    return true;
}


bool isPossible(string s, int n){
    int uniqChars=noOfUniqueChars(s);
    if(uniqChars==1)return true;
    for(int i=uniqChars;i<n;i++){
        if(n%i!=0){
            continue;
        }
        string subs=s.substr(0,i);
        if(uniqChars==noOfUniqueChars(subs)){
            bool res=isValidSubs(s,n,subs,i);
            if(res==true)return true;
        }    
    }
    return false;
}



int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(isPossible(s,s.length()))
            cout << "True" << endl;
        else 
            cout << "False" << endl;
    }
	return 0;
}