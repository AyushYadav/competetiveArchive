#include <bits/stdc++.h>

using namespace std;

void printOnlineDelhi(vector <int> delhi, vector <int> online){
  map <int,int> mp;
  for(int i=0;i<delhi.size();i++)
    mp.insert(make_pair(delhi[i],1));
  map<int, int>::iterator it;
  for(int i=0;i<online.size();i++){
    it=mp.find(online[i]);
    if(it!=mp.end())
      cout << online[i] << endl;
  }  
}

// To execute C++, please define "int main()"
int main() {
  // auto words = { "Hello, ", "World!", "\n" };
  vector <int> delhi={1,3,4,6,9};
  vector <int> online={1,2,3,5,7,8,9};
  printOnlineDelhi(delhi, online);
  return 0;
}
