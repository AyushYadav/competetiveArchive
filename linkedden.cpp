#include "stdc++.h"

using namespace std;



int penaltyLinked(string s, int k){
    string linkedin = "linkedin";
    int len = s.length();
    int penalty1 = 0 , penalty2=0 ;
    
    // linkedin string in the first half
    for(int itr = 0 ; itr < 8 ; itr++){
        if (s[k+itr]==linkedin[itr]) {
            if (s[len-itr-k-1]!=linkedin[itr]) penalty1++;
        }
        else {
            if (s[len-itr-k-1]==linkedin[itr]) penalty1++;
             
            else penalty1+=2;
        }
    }
    
    // linkedin string in the second half
    for(int itr = 0 ; itr < 8 ; itr++){
        if(s[itr+k]==linkedin[8-itr-1]){
            if(s[len-itr-k-1]!=linkedin[8-itr-1]) penalty2++;
        }
        else {
            if(s[len-itr-k-1]==linkedin[8-itr-1]) penalty2++; 
        
            else penalty2+=2;
    
        }
    }
    return min(penalty1,penalty2);
}


int replacements(string s) {
    int len = s.length();
    int mid = len/2, min_penalty = INT_MAX;
    if (len%2==1) mid++;
    for(int itr = 0 ; itr <= mid-8 ; itr++){
        int penalty = 0;
        int j = 0;
        while(j<itr) {
            if(s[j]!=s[len-j-1])penalty++;
            j++;
        }
        penalty += penaltyLinked(s, itr);
        j = itr+8;
        while(j<mid) {
            if(s[j] != s[len-j-1]) penalty++;
            j++;
        }
        min_penalty = min(penalty, min_penalty);
    }
    return min_penalty;
}



int main(){
	string s="fulrokxeuolnzxltiiniabudyyozvnlqbydmaldbxaddmkobhlplkaplgndnksqidkaenxdacqtsskdkdddls";
	cout << replacements(s) << endl;
	return 0;
}




