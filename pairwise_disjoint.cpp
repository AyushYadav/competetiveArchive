#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int isPresent(int ar[], int n , int ele){
	for(int i=0;i<n;i++)
		if(ar[i]==ele)return 1;
	return 0;
}

int main() {
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    
    int count=0;
	int var=1;
	for(int i=0;i<n;i++){
		int temp=a[i];
		for(int j=0;j<n;j++){
			if(b[j]!=-1 && b[j]==temp){
				count++;
				b[j]=-1;
				a[i]=-1;
				break;
			}else if((b[j]!=-1) && (a[i]!=-1) &&(var==1) && (isPresent(a,n,b[j])==0)){
				count++;
				b[j]=-1;
				a[i]=-1;
				var=0;
				break;
			}
		}
	}
	if(var==1 && count == n )count--;
	cout << count << endl;

    return 0;
}
