// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class graph{
    public:
    vector<vector<pair<int,int>>> adj;
    graph(int n){
        adj.resize(n);
    }

    void addEdge(int u, int v, int wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int spanningTree(int V) {
        
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;
        parent[0] = -1;
        
        for(int i=0; i<V; i++){
            int mini = INT_MAX;
            int u;
            
            for(int v = 0; v<V; v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }
            mst[u] = true;
            
            for(auto it: adj[u]){
                int v = it.first;
                int w = it.second;
                if(mst[v] == false && key[v] > w){
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        
        int sum = 0;
        for(int i=1; i<V; i++){
            sum += key[i];
        }
        
        return sum;
    }
};

int main(){
    int n=3;
    int m = 3;
    graph g(n);
    g.addEdge(0,1,5);
    g.addEdge(0,2,1);
    g.addEdge(1,2,3);

    int ans;

    ans = g.spanningTree(n);
    cout<<ans;
    return 0;
}