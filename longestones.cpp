#include "stdc++.h"

using namespace std;


void longestConsecutiveOnes(int n){
	int count=0;
	while(n>0){
		n=n&(n<<1);
		count++;
	}
	cout << count << endl;
}
vector<int> vec;

void subsetSum(int ar[], int start, int end, int sum){
	if(start==end){
		vec.push_back(sum);
		return;
	}
	subsetSum(ar,start+1,end,sum);
	subsetSum(ar,start+1,end,sum+ar[start]);
	return;
}


int main(){
	// longestConsecutiveOnes(222);
	int ar[]={1,2};
	subsetSum(ar,0,2,0);
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
		cout << vec[i] << " " ;
	
	return 0;
}