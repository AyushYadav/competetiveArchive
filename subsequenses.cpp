#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
Number of distinct subsequences
http://www.practice.geeksforgeeks.org/problem-page.php?pid=1017
*/

long long int bruteSub(string s){
	long long count=1;
	map<string,int> mp;
	for(int i=0;i<s.length();i++){
		int l=0;
		string ch(1,s[i]);
		map<string,int>::iterator itr=mp.find(ch);
		if(itr==mp.end()){
			count++;
			// cout << ch << endl;
			mp.insert(make_pair(ch,1));
		}
		while((l+i)<=s.length()){ 
			for(int j=i+1;j<s.length();j++){
				string ss= s.substr(j,j+l);
				ss=ch+ss;
				map<string,int>::iterator itr=mp.find(ss);
				if(itr==mp.end()){
					count++;
					// cout << ss << endl;
					mp.insert(make_pair(ss,1));
				}
			}
			l++;		
		}
	}
	return count;
}

long long int optimized(string s){
	if(s.length()==0)return 1;
	long long int n=s.length();
	long long int dp[n+1];
	dp[0]=1;
	vector<int> lastOccu(256,-1); 
	for(int i=1;i<=n;i++){
		char ch=s[i-1];
		dp[i]=2*dp[i-1];
		if(lastOccu[ch]!=-1){
			dp[i]=dp[i]-dp[lastOccu[ch]];
			
		}
		lastOccu[ch]=i-1;
	}
	// for(int i=0;i<=s.length();i++)cout << dp[i] << " ";
	// cout << endl;
	return dp[n];
}

long long int countSub(string str){
    // Create an array to store index
    // of last
    vector<int> last(256, -1);
 
    // Length of input string
    long long int n = str.length();
 
    // dp[i] is going to store count of distinct
    // subsequences of length i.
    long long int dp[n+1];
 
    // Empty substring has only one subsequence
    dp[0] = 1;
 
    // Traverse through all lengths from 1 to n.
    for (int i=1; i<=n; i++)
    {
        // Number of subsequences with substring
        // str[0..i-1]
        dp[i] = 2*dp[i-1];
 
        // If current character has appeared
        // before, then remove all subsequences
        // ending with previous occurrence.
        if (last[str[i-1]] != -1)
            dp[i] = dp[i] - dp[last[str[i-1]]];
 
        // Mark occurrence of current character
        last[str[i-1]] = (i-1);
    }
 	//for(int i=0;i<=n;i++)cout << dp[i] << " ";
	//cout << endl;
	
    return dp[n];
}


int main(){
	int t;
	cin >> t;
	for(int p=1;p<=t;p++){
		string s;
		cin >> s;
		cout << (countSub(s)%1000000007) << endl;	
	}
	
	return 0;
}