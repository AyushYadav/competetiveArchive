#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define MAX 101
//MAX of the input M*N

using namespace std;
vector<vector<int> > arr_num; // used to store all the possible combinations
vector<string> vec;
int a[MAX] = {0};


// Generate a combination of function, the combination of preservation in the arr
void comb_number(int n, int r){
    if (r == 1){
        a[r - 1] = n;
        int j = 0;
        while (a[j] != 0){
            j++;
        }
        vector<int> tmp;
        for (int  i = j - 1; i >= 0; i--){
            tmp.push_back(a[i]);
        }
        arr_num.push_back(tmp);
    }
    else{
        a[r - 1] = n;
        for (int j = n - 1; j >= r - 1; j--){
            comb_number(j, r - 1);
        }
    }
}

void comb_str(vector<vector<string> > &str,int K){
    for(int i = 0; i < arr_num.size(); i++){
        vector<string> str_tmp;
        for (int j = 0; j < K; j++){
            string tmp;
            for (int m = 0; m < arr_num[0].size(); m++){
                tmp += vec[j][arr_num[i][m]-1];
            }
            str_tmp.push_back(tmp);
        }
        str.push_back(str_tmp);
    }
}

bool judge(vector<vector<string> > &str){
    for (int i = 0; i < str.size();i++){
        int flag = -1;
        vector<string> tmp(str[i]);
        for (int j = 0; j<str[0].size();j++){
            for (int k = 0;k < str[0].size(); k++){
                if (k==j){
                    continue;
                }
                else
                {
                    flag = (tmp[j]).compare(tmp[k]);
                }               
                if (flag == 0)
                    break;
            }
        }
        if (flag == -1)
            return true;
    }
    return false;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    //Input
    while (K--){
        string str;
        for (int i = 0; i<N; i++){
            string tmp;
            cin >> tmp;
            str += tmp;
        }
        vec.push_back(str);  // vec express all the characters in there
    }
    // Try all possible 1 to N * M lengths
    int len = 1;
    for (; len <= N*M; len++){
        arr_num.clear();
        for (int i = N*M; i >= len;i--){
            comb_number(i, len);
        }

        vector<vector<string> > str;
        comb_str(str,vec.size());
        if (judge(str))
            break;  
    }
    cout << len << endl;
    return 0;
}