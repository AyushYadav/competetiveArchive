#include <bits/stdc++.h>

using namespace std;

int longestLengthPositivity(vector <int> vec){
  int table[vec.size()];
  for(int i=0;i<(int)vec.size();i++)
    table[i]=0;
  int max_len=INT_MIN;
  int max_ind=-1;
  if(vec[0]>0) table[0]=1;
  else table[0]=0;
  for(int i=1;i<=((int)vec.size());i++){
    for(int j=0;j<i;j++){
      if(vec[j]>0 && vec[i]>0 && table[i]< table[j]+1 ){
        table[i]=table[j]+1;
        if(table[i]>max_len){
          max_ind=i;
        }
      }
      if(vec[i]<0)
        table[i]=0;
    }
  }
  cout << "Index from : to " << max_ind-table[vec.size()-1]+1 << " : " << max_ind << endl;
  return table[vec.size()-1];
}



int main() {
  vector <int> vec={-1,-2,-3,3,4,6,-9, -1 , -2 , -3,1,2,3,4,5,6,7,8};
  cout << "Size of the longest positive sequence : " << longestLengthPositivity(vec) << endl;
  return 0;
}
