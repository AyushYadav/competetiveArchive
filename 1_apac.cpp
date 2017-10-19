#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define MAX_ROW 20
#define MAX_COL 20

int r,c;
float p,q;


float prob(float val, int n){
	float result=0;
	while(n>0){
		result+=(val*(pow((1.0-val),n)));
		n--;
	}
	cout << result << endl;
	return result+val;
}


float traversal(char arr[][MAX_COL],int visited[][MAX_COL],int si,int sj, int steps){
	if(si>=r || sj >=c || si<0 || sj<0 )return 0.0;
	if(steps<=0)return 0.0;
	float pval=0.0;
	if(visited[si][sj]==0){
		if(arr[si][sj]=='A'){
			pval=p;
		}else if(arr[si][sj]=='.'){
			pval=q;
		}
		visited[si][sj]=1;
	}else{
		int visitations=visited[si][sj];
		visited[si][sj]+=1;
		if(arr[si][sj]=='A'){
			pval=prob(p,visitations);
		}else if(arr[si][sj]=='.'){
			pval=prob(q,visitations);
		}			
	}
	//cout << pval << endl;
	steps--;
	return (pval+max(max(traversal(arr,visited,si+1,sj,steps),traversal(arr,visited,si-1,sj,steps)),max(traversal(arr,visited,si,sj+1,steps),traversal(arr,visited,si,sj-1,steps))));
}

int main(){
	int t;
	cin >> t;
	for(int pp=1;pp<=t;pp++){
		int rs,cs,steps;
		cin >> r >> c >> rs >> cs >> steps ;
		cin >> p >> q;
		int visited[MAX_ROW][MAX_COL]={0};
		char arr[MAX_ROW][MAX_COL];
		//cout << p << q << endl;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> arr[i][j];
			}
		} 
		steps--;
		float answer=max(max(traversal(arr,visited,rs+1,cs,steps),traversal(arr,visited,rs-1,cs,steps)),max(traversal(arr,visited,rs,cs+1,steps),traversal(arr,visited,rs,cs-1,steps)));
		cout << "Case #" << pp << ": " << answer << endl;
	}
	return 0;
}