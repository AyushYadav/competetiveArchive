#include <iostream>
#include <algorithm>

#define MAX_SIZE 100005
using namespace std;

long long pre[MAX_SIZE];
long long suf[MAX_SIZE];
long long arr[MAX_SIZE];
long long res[MAX_SIZE];


long long cal(long long zu[MAX_SIZE], int m, int n){
    long long res = 0;
    for (int i = m; i <= n; i++){
        res = max(res, zu[i]);
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    int i = 1;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    pre[0] = pre[N + 1] = suf[0] = suf[N + 1] = 0;
    for (int i = 1; i<N; i++){
        pre[i] = pre[i - 1] ^ arr[i];
    }
    for (int i = N; i >= 1; i--){
        suf[i] = suf[i + 1] ^ arr[i];   
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++){
        ans = max(ans, max(cal(pre, 0, i), cal(suf, i + 1, N)));

    }
    cout << ans << endl;
    return 0;
}