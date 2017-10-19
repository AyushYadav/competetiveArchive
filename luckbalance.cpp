#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,k;
	cin >> n >> k;
	int imp[n];
	int i=0;
	//int unimp[n];
	int luck=0;
	for(int p=0;p<n;p++){
		int temp1,temp2;
		cin >> temp1 >> temp2;
		if(temp2==1){
			imp[i]=temp1;
			i++;
		}
			
		else if(temp2==0){
			//unimp[j]=temp1;
			//j++;
			luck+=temp1;
		}
	}
	sort(imp,imp+i);
	//sort(unimp,unimp+j);
	
	for(int p=i-1;p>=0;p--){
		if(k>0){
			luck+=imp[p];
			k--;
		}else
			luck-=imp[p];
		
	}
	cout << luck << endl;
    return 0;
}
