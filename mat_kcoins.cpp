#include <cstdio>
#include <cstdlib>
#include <iostream>

#define R 3
#define C 3

using namespace std;
int master_count=0;
int countWays(int mat[][C],int k, int m, int n){
	if(m==3 || n==3)
		return 0;
	if(m==2&&n==2&&k==mat[m][n])
		return master_count++;
	return countWays(mat,k-mat[m][n],m+1,n)+countWays(mat,k-mat[m][n],m,n+1);
}

int main(){
	int k = 12;
    int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    countWays(mat,k,0,0);   

    cout << master_count << "\n";


	return 1;
}