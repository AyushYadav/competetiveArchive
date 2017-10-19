#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	int ar[n];
	for(int i=0;i<n;i++)cin >> ar[i];
	int cost=0;
	sort(ar,ar+n);
	for(int i=0;i<n;){
		int k=i+1;
		while(ar[k]<=(ar[i]+4))k++;
		i=k;
		cost++;
	}
	cout << cost << endl;
    return 0;
}
