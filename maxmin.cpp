#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, k, unfairness = INT_MAX;
    cin >> n >> k;
    int list[n];
    for (int i=0; i<n; i++)
        cin >> list[i];
    sort(list,list+n);
    int diff[n-1];
    for(int i=0;i<n-1;i++)
    	diff[i]=list[i+1]-list[i];
    int range=INT_MAX;
    int range_lower=0;
    int j=0;
    while(j+k<n-1){
    	int min=INT_MAX,max=INT_MIN;
    	for(int i=j;i<(j+k);i++){
    		if(diff[i]<min)min=diff[i];
    		if(diff[i]>max)max=diff[i];
    	}
    	if(max-min<range){
    		range=max-min;
    		range_lower=j;
    	}
    }
    for(int i=range_lower;i<(range_lower+k);i++)

    cout << unfairness << "\n";
    return 0;
}
