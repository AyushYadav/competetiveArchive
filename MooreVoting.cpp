#include <iostream>

using namespace std;


int candidate(int ar[], int n){
	int count=1,maj_ind=0;
	for(int i=1;i<n;i++){
		if(ar[i]==ar[maj_ind])count++;
		else count--;
		if(count==0){
			maj_ind=i;
			count=1;	
		}
	}
	return ar[maj_ind];
}

bool majority(int ar[], int n, int cand){
	int count=0;
	for(int i=0;i<n;i++)
		if(ar[i]==cand)count++;
	if(count>n/2)return true;
	else return false;
}


void printMajority(int ar[], int n){
	int cand=candidate(ar,n);
	if(majority(ar,n,cand))cout << cand << endl;
	else cout << "No majority" << endl;
}


int main(){
	int ar[]={1, 3, 2, 1, 3};
	int n=sizeof(ar)/sizeof(ar[0]);
	printMajority(ar,n);
	return 0;
}