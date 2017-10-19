#include <bits/stdc++.h>

using namespace std;

typedef  pair<int, int> mypair;
 

struct Graph{
    int V, E;
    vector< pair<int, mypair> > edges;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});
    }
    int mst();
};
 

struct djsets{
    int *parent, *rank;
    int n;
    djsets(int n){        
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
        for (int i = 0; i <= n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u){
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
   
    void merge(int x, int y){
        x = find(x), y = find(y);
        if (rank[x] > rank[y])parent[y] = x;          
        else parent[x] = y;
        if (rank[x] == rank[y])rank[y]++;            
    }
};
 
int Graph::mst(){
    int wt = 0; 
    sort(edges.begin(), edges.end());
    djsets ds(V);
    vector< pair<int, mypair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v){
            wt += it->first;
            ds.merge(set_u, set_v);
        }
    } 
    return wt;
}
 

int main(){
    int V , E ;
    cin >> V >> E;
    Graph g(V, E);
    for(int i=0;i<E;i++){
        int a, b, c, d;
        cin >> a>> b >> c;
        if(c==1){
            cin >> d;
            g.addEdge(a-1, b-1, d);
        }
        else g.addEdge(a-1, b-1, 0);         
        
    }
    int wt = g.mst();
    cout << wt << endl;
    return 0;
}
