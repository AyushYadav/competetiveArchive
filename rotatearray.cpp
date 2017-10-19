#include "stdc++.h"

using namespace std;


int main(){
	int t;
	cin >> t;

	while(t--){
		vector<int> vec(26,0);
		string s;
		int k;
		cin>>s>>k;
		// cout <<k<<endl;
		for(int i=0;i<s.length();i++)
			vec[s[i]-'a']++;
		vec.erase(remove(vec.begin(), vec.end(), 0), vec.end());
		sort(vec.begin(),vec.end(),greater<int>());
		int end=0;
		for(int i=vec.size()-1;i>=0;i--){
			if(vec[i]!=0){
				end=i;
				break;
			}
		}
		int ind=1;
		cout << end;
		while(k>0){
			if(ind<=end){
				int diff=vec[ind-1]-vec[ind];
				if(diff>=k){
					vec[ind-1]=vec[ind-1]-k;
					k=0;
					break;
				}
				else if(diff==0){
					int j=1;
					while(vec[ind+j]==vec[ind] && (ind+j)<=end){
						j++;
					}
					if(j+1>k){
						int jj=0;
						while(jj<=j){
							vec[ind+jj-1]--;
							jj++;
						}
						k=0;
						break;
					}
				}
				else if(diff<k){
					vec[ind-1]=vec[ind];
					k-=diff;
					if(vec[ind-1]!=vec[ind])ind++;	
				}
			}else break;
		}
		int score=0;
		for(int i=0;i<=end;i++){
			score+=pow(vec[i],2);
		}
		cout << score << endl;


	}
	return 0;
}