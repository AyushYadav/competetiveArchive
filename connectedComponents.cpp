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


int getGridSize(vector< vector<int> > &grid, int n, int m, int i, int j,vector< vector<int> > &visited){
    if(i<n && i>=0 && j>=0 && j<m && grid[i][j]==1 && visited[i][j]==0){
        visited[i][j]=1;
        return 1+getGridSize(grid,n,m,i-1,j,visited)+getGridSize(grid,n,m,i+1,j,visited)+getGridSize(grid,n,m,i,j-1,visited)+getGridSize(grid,n,m,i,j+1,visited)+getGridSize(grid,n,m,i-1,j-1,visited)+getGridSize(grid,n,m,i+1,j+1,visited)+getGridSize(grid,n,m,i-1,j+1,visited)+getGridSize(grid,n,m,i+1,j-1,visited);
    }
    return 0;
    
}


int get_biggest_region(vector< vector<int> > grid,vector< vector<int> > visited) {
    int m=grid[0].size();
    int n=grid.size();
    int max_size=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                int size=getGridSize(grid,n,m,i,j,visited);
                max_size=max(size,max_size);
            }
        }
    }
    return max_size;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    vector< vector<int> > visited(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
           visited[grid_i][grid_j]=0;
       }
    }
    cout << get_biggest_region(grid,visited) << endl;
    return 0;
}


/*
7 5 
1 1 1 0 1 
0 0 1 0 0 
1 1 0 1 0 
0 1 1 0 0 
0 0 0 0 0 
0 1 0 0 0 
0 0 1 1 0
Answer : 9

*/