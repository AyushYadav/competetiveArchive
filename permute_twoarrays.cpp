#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	for(int p=1;p<=t;p++){
		int n,k;
		cin >> n >> k;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		bool flag=true;
		for(int i=0;i<n && flag ;i++){
			int a1=a[i];
			flag=false;
			for(int j=0;j<n;j++)
				if( b[j]!=-1 &&  (b[j]+a1 >= k) ){
					flag=true;
					b[j]=-1;
					break;
				}
		}
		if(flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
    return 0;
}
