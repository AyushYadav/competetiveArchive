#include "stdc++.h"

using namespace std;

int binarySearch(vector<int> vec,int start, int end,int key);
bool isValidBST(vector<int> vec);
int maxDiff(vector<int> vec, int n);
int numberOfPairs(vector<int> vec, int k);
int toggleBits(int n);

int main(){
	int ar[6]={1,5,3,4,2,6};
	vector<int> vec(ar,ar+6);
	cout << numberOfPairs(vec,3) << endl;
	return 0;
}

int binarySearch(vector<int> vec,int start, int end,int key){
    int first=start;
    int last=end;
    while(last>=first){
        int mid=first+((last-first)/2);
        if(vec[mid]==key)return mid;
        else if(vec[mid]>key)last=mid-1;
        else first=mid+1;
    }
    return -1;
}

// find number of pairs such that |a-b|=k

int numberOfPairs(vector<int> vec, int k){
	int n=vec.size();
	if(n==1)return 0;
	sort(vec.begin(),vec.end());
	int count=0;
	for(int i=0;i<n;i++)
		if((vec[i]+k) < vec[n-1] && binarySearch(vec,i+1,n-1,vec[i]+k)!=-1)
			count++;
	return count;
}

// is pre-order a valid BST
// Input: preorder traversal vector , size of vector
// Output: true if a bst else false

bool isValidBST(vector<int> vec){
	int n=vec.size();
	int root=INT_MIN;
	stack<int> st;
	for(int i=0;i<n;i++){
		if(root<vec[i])return false;
		while(!st.empty() && vec[i]>st.top()){
			root=st.top();
			st.pop();
		}
		st.push(vec[i]);
	}
	return true;
}

// return max(ar[j]-ar[i]) such that j>i

int maxDiff(vector<int> vec, int n){
	if(n==1)return 0;
	int maxDiff=vec[1]-vec[0];
	int min=vec[0];
	for(int i=1;i<n;i++){
		if(vec[i]-min>maxDiff){
			maxDiff=vec[i]-min;		
		}
		if(vec[i]<min)min=vec[i];
	}
	return maxDiff;
}

// return the number formed by toggling the bits of a number
// Input: the number to be flipped
// Output: the number with flipped bits 
int toggleBits(int n){
	int k=1+log2(n);
    int mask=(1<<k)-1;
	return (n^mask);
}


// Lego - DP

/*

#include <iostream>
#include <cstring>
using namespace std;

const long long mod = 1000000007;
int t;
int n;
int m;
long long f[1111];
long long g[1111];
long long h[1111];

long long pow(long long a, int p)
{
    long long ans = 1;
    while(p)
    {
        if (p % 2) ans = ans * a % mod;
        a = a * a % mod;
        p /= 2;
    }
    return ans;
}
int main(void){
    f[0] = 1;
    for (int i=1; i<=1000; i++)
        for (int j=1; j<=4; j++)
            if (i - j >= 0) f[i] = (f[i] + f[i-j]) % mod;

    for (cin >> t; t; t--)
    {
        cin >> n >> m;
        for (int i=1; i<=m; i++) g[i] = pow(f[i], n);

        memset(h, 0, sizeof(h));
        h[1] = 1;
        for (int i=2; i<=m; i++)
        {
            h[i] = g[i];
            long long tmp = 0;
            for (int j=1; j<i; j++)
                tmp = (tmp + h[j] * g[i-j]) % mod;
            h[i] = (h[i] - tmp + mod) % mod;
        }
        cout << h[m] << "\n";
    }

    return 0;
}




#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define lli long long int

const lli MOD = 1000000007;

lli powerFunc(lli a, int p);

int main(void){
    vector<lli> fact(1111);=
    vector<lli> inp(1111);
    fact[0] = 1;
    for (int i=1; i<=1000; i++)
        for (int j=1; j<=4; j++)
            if (i - j >= 0) fact[i] = (fact[i] + fact[i-j]) % MOD;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=m;i++) inp[i]=powerFunc(fact[i], n);
        vector<lli> res(1111,0);
        res[1] = 1;
        for (int i=2; i<=m; i++){
            lli temp = 0;
            res[i] = inp[i];
            for (int j=1; j<i; j++)
                temp = (temp + res[j] * inp[i-j]) % MOD;
            res[i] = (res[i] - temp + MOD) % MOD;
        }
        cout << res[m] << endl;
    }
    return 0;
}

lli powerFunc(lli a, int p){
    lli answer = 1;
    while(p){
        if (p % 2) answer = answer * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return answer;
}









*/

