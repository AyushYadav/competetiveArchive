#include "stdc++.h"

using namespace std;
vector<int> vec;
int endd;

void subsetSum(vector<int> ar, int start, int sum){
	if(start==endd){
		vec.push_back(sum);
		return;
	}
	subsetSum(ar,start+1,sum);
	subsetSum(ar,start+1,sum+ar[start]);
	return;
}



int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec.clear();
        vector<int> ar(n,0);
        for(int i=0;i<n;i++){
            // int val;
            cin >> ar[i];
            // ar.push_back(val);
        }
        endd=n;
        subsetSum(ar,0,0);
        sort(vec.begin(),vec.end());
	    for(int i=0;i<vec.size();i++)
		    cout << vec[i] << " " ;
        cout << endl;
    }   
	return 0;
}