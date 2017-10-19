#include <bits/stdc++.h>

using namespace std;

#define MAX_ROW 4200010
#define MAX_ELE 100010

int n;
int trieNodes[MAX_ROW][2];
long long input[MAX_ELE];
long long prefix[MAX_ELE];
long long suffix[MAX_ELE];
int node;

void addToTrie(int i);  // adds a element at i'th position from the prefix array to the trie
long long calculateXORValue(long long x);   // calculates the max XOR value using the trie

int main(){
    int i,j;
    long long ans;
    cin>>n;
    ans=0;
    node=1;
    memset(trieNodes[0],0,sizeof(trieNodes[0]));
    for(i=1;i<=n;i++) cin >> input[i]; // Getting the input
    prefix[0]=prefix[n+1]=suffix[0]=suffix[n+1]=0;     // Base case for the prefix and suffix array
    for(i=1;i<=n;++i) prefix[i]=prefix[i-1]^input[i];   // Populating the prefix array
    for(i=n;i>0;--i) suffix[i]=suffix[i+1]^input[i];    // Populating the suffix array
    addToTrie(0);   // adding the first prefix to trie
    for(i=1;i<=n+1;i++){
        ans=max(ans,calculateXORValue(suffix[i]));  // finding the current max  
        addToTrie(i);   // and adding the next prefix to the trie
    }         
    cout << ans << endl;  // output the max xor value
    return 0;
}

void addToTrie(int i){
    long long k,current,x;
    x=prefix[i];
    current=0;
    for(int j=42;j>=0;j--){
        k=((1LL<<j)&x)?1:0; // getting the j'th bit from the current number
        if(trieNodes[current][k] == 0) {    /// if not set then make the tree node
                memset(trieNodes[node],0,sizeof(trieNodes[node]));
                trieNodes[current][k]=node++;
            }
        current=trieNodes[current][k];  // else just add the counter 
    }
}


long long calculateXORValue(long long x){
    long long i,k,current=0,r=0;
    for(i=42;i>=0;i--){
        k=((1LL<<i)&x)?0:1; // taking the j'th bit from the number
        if(trieNodes[current][k]) { // if set then compare for max val
                current=trieNodes[current][k];
                r|=1LL<<i;
        }
        else current=trieNodes[current][1-k];   // else goto another trie node 
    }
    return r;
}