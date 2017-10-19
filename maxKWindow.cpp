#include "stdc++.h"

using namespace std;

void maxInKWindow(vector <int> vec,int k){
	int n=vec.size();
	deque<int> qe;
	int i=0;
	for(i=0;i<k;i++){
		while(!qe.empty() && vec[i]>vec[qe.back()])
			qe.pop_back();
		qe.push_back(i);
	}
	for(;i<n;i++){
		cout << vec[qe.front()] << " " ;
		while(!qe.empty() && qe.front()< (i-k+1)){
			qe.pop_front();
		}
		while(!qe.empty() && vec[qe.back()]< vec[i]) 
			qe.pop_back();
		qe.push_back(i);

	} 
	cout << vec[qe.front()] << endl;
}

int main(){

	int arr[]={12, 1, 78, 90, 57, 89, 56};
	vector<int> ar(arr,arr+7);
	int k=3;

	maxInKWindow(ar,k);
	
	return 0;
}

