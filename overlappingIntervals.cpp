#include "stdc++.h"

using namespace std;

typedef struct interval{
	int start;
	int end;
}interval;

bool myComp(interval a, interval b){
	return a.start < b.start ? true : false ;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<interval> input;
		for(int i =0;i<n;i++){
			interval temp;
			cin >> temp.start >> temp.end;
			input.push_back(temp);
		}
		sort(input.begin(),input.end(),myComp);
		cout << endl;
		for(int i=0;i<input.size()-1;i++){
			if(input[i].end>=input[i+1].start){
				input[i].end=max(input[i].end,input[i+1].end);
				input.erase(input.begin()+i+1);
				i--;
			}
		}
		for(int i=0;i<input.size();i++)
			cout << input[i].start << " " << input[i].end << " ";
		cout << endl;
	}
	return 0;
}