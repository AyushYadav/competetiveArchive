#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;
	int c[n];
	for(int i = 0; i < n; i++) cin >> c[i];
	int quantity[k];
	int total=0, cost=0, cost_i=0;
	memset(quantity, 0, sizeof quantity);
	sort(c,c+n,greater<int>());
	while(total<n){
		for(int i=0;i<k && cost_i<n ;i++){
			cost+=((quantity[i]+1)*c[cost_i]);
			quantity[i]+=1;
			total+=1;
			cost_i++;
		}
	}
	cout << cost << endl;   
	return 0;
}
