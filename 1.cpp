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

#define ll long long int

using namespace std;


int min(int x, int y)
{
    return x<y?x:y;
}

int toInt(char ch){
	return (int)(ch-'0');
}

int sumdigits(string s,int start,int end){
	int val=0;
	for(int i=start;i<end;i++)
		val+=((int)(s[i]-'0'));
	return val;
}

int recur(string s1, string s2, int i, int j){
	if(s1.length()==i && s2.length()==j)return 0;
	if(s1.length()==i && s2.length()>j)return sumdigits(s2,j,s2.length());
	if(s2.length()==j && s1.length()>i)return sumdigits(s1,i,s1.length());
	if(s1[i]==s2[j])return recur(s1,s2,i+1,j+1);
	return min((toInt(s1[i])+recur(s1,s2,i+1,j)),(toInt(s2[j])+recur(s1,s2,i,j+1)));
} 


int main(){
	int t;
	cin >> t;
	for(int cs=1;cs<=t;cs++){
		string s1,s2;
		cin >> s1 >>s2;
		cout << recur(s1,s2,0,0) << endl;
	}

}
