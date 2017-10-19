#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define lli long long int

const lli MOD = 1000000007;

lli powerFunc(lli a, int p);


int main(void){
    vector<lli> fact(1111);
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



