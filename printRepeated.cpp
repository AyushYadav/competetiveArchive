#include <iostream>

using namespace std;

#define V 4
#define INF INT_MAX
#define ui unsigned int 
#define INT_BIT 32

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}


int findRepeating(int ar[],int n){
    for(int i=0;i<n;i++){
        if(ar[abs(ar[i])]<0)return abs(ar[i]);
        else ar[abs(ar[i])]=-1*ar[abs(ar[i])];
    }
    return -1;
}

void binomialCoefficient(int n,int k){
    if(k>n-k)k=n-k;
    int res=1;
    for(int i=0;i<k;i++){
        res*=n-i;
        res/=i+1;
    }
    cout << res << endl;
}

int knapsack(int W, int n, int val[],int wt[]){
    int k[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)k[i][j]=0;
            else if(wt[i-1]<=j){
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            }
            else 
                k[i][j]=k[i-1][j];
        }
    }
    return k[n][W];
}

int recurEggDrop(int n, int k){
    if(k==0||k==1)return k;
    if(n==1)return k;
    int minn=INT_MAX,res;
    for(int i=1;i<=k;i++){
        res=min(recurEggDrop(n-1,i-1),recurEggDrop(n,k-i));
        if(res<minn)minn=res;
    }
    return minn+1;
}

int eggDrop(int n, int k){
    int dp[n+1][k+1];
    int res;
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int j=0;j<=k;j++){
        dp[1][j]=j;
    }

    for(int i=2;i<=n;i++){

        for(int j=2;j<=k;j++){
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++){
                res=1+max(dp[i][j-x],dp[i-1][x-1]);
                if(res<dp[i][j])dp[i][j]=res;
            }

        }
    }
    return dp[n][k];    
}

void printMatrix(int dist[][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF)cout << "INF\t";
            else cout << dist[i][j] << "\t"; 
        }
        cout << endl;
    }
}


void floydWarshall(int graph[][V]){
    int dist[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if( dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printMatrix(dist);
}

// Given a array with each element repeated 3 times and one element only once. Find x
// http://www.geeksforgeeks.org/find-the-element-that-appears-once/
void findUnique(int ar[],int n){
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        int x=ar[i];
        two|=one&x;
        one^=x;
        three=~(one&two);
        one&=three;
        two&=three;
    }
    cout << one << endl;
}

int swapTwoBit(ui p1,ui p2, ui x, ui n){
    ui s1 = (x>>p1)&((1U<<n)-1);
    ui s2 = (x>>p2)&((1U<<n)-1);
    ui xo = s1^s2;
    xo=(xo<<p1)|(xo<<p2);
    return xo^x;
}

int leaftRotate(int n,int d){
    return ((n<<d)|(n>>(INT_BIT-d)));
}
int rightRotate(int n,int d){
    return ((n>>d)|(n<<(INT_BIT-d)));
}

void findNonRepeating(int ar[],int n, int *x, int *y){
    int i=0;
    int xo=ar[i];
    *x=0;
    *y=0;
    for(i=1;i<n;i++)xo^=ar[i];
    int set_bit = xo & ~(xo-1);
    for(i=0;i<n;i++){
        if(set_bit & ar[i])
            *x^=ar[i];
        else
            *y^=ar[i];
    }
}


int coinChange(int s[], int m, int n){
    int val[n+1];
    memset(val,0,sizeof(val));
    val[0]=1;
    for(int i=0;i<m;i++){
        for(int j=s[i];j<=n;j++){
            val[j]+=val[j-s[i]];
        }
    }
    return val[n];
}


int main(){



    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout << coinChange(arr,m,n) << endl;

    // int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    // int *x = (int *)malloc(sizeof(int));
    // int *y = (int *)malloc(sizeof(int));
    // findNonRepeating(arr, 8, x, y);
    // cout << *x << " " << *y << endl;
    // cout << swapTwoBit(0,3,28,2) << endl;
    // int ar[]={1,1,2,1,2,3,4,4,2,4};
    // findUnique(ar,10);

    // int graph[V][V] = { {0,   5,  INF, 10},
    //                     {INF, 0,   3, INF},
    //                     {INF, INF, 0,   1},
    //                     {INF, INF, INF, 0}
    //                   }; 
    // floydWarshall(graph);

    // int W= 50;
    // int n=3;
    // int val[] = {60, 100, 120};
    // int wt[] = {10, 20, 30};
    // cout << knapsack(W,n,val,wt) << endl;
    // binomialCoefficient(8,2);
    // int ar[]={1,1,2,3,4,2,2};
    // cout << findRepeating(ar,7) << endl;
    return 0;
}
