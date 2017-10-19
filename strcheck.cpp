#include <iostream>

using namespace std;


#define ll long long int
 
int myFuncUsingDP(string a, string b,int la, int lb);

int min(int a, int b){
    return a<b?a:b;
}

int toInt(char ch){    
    return (int)(ch-'0');
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string a,b;
        cin >> a >> b;
        cout << myFuncUsingDP(a, b, a.length(), b.length())<<endl;
    }
    return 0;
}



int myFuncUsingDP(string a, string b, int la, int lb){
    int table[la+1][lb+1];
    for (int i=0; i<=la; i++){
        for (int j=0; j<=lb; j++){
            table[i][j] = 0;
        }
    }
    for (int i=0; i<=la; i++){
        for (int j=0; j<=lb; j++){
            if (i==0 && j == 0)
                table[i][j] = 0;
            else if (i==0 && j != 0)
                table[i][j] = table[i][j - 1] + toInt(b[j - 1]);
            else if (j==0 && i > 0)
                table[i][j] = table[i - 1][j] +  toInt(a[i - 1]);
            
            else if (a[i-1] == b[j-1])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = min(toInt(b[j - 1]) + table[i][j-1],toInt(a[i - 1]) + table[i-1][j]);                                   
        }
    }
    return table[la][lb];
}
