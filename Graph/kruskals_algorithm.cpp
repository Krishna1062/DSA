// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class graph{
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2]; // [2] is taken because at weight is at 2 index
    }
    void makeSet(int n, vector<int> &parent, vector<int> &rank){
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent, parent[node]);
    }
    
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent, u);
        v = findParent(parent, v);
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        
    }
    public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), cmp);
        
        vector<int> parent(V);
        vector<int> rank(V);
        makeSet(V, parent, rank);
        int minWt = 0;
        
        for(int i=0; i<edges.size(); i++){
            int v = findParent(parent, edges[i][0]);
            int u = findParent(parent, edges[i][1]);
            int w = edges[i][2];
            if(u != v){
                minWt += w;
                unionSet(u, v, parent , rank);
            }
        }
        return minWt;
    }
};

int main(){
    int n=3;
    int m = 3;
    graph g;
    vector<vector<int>> edges = {{0,1,5}, 
                                 {0,2,1}, 
                                 {1,2,3}};


    int ans;

    ans = g.kruskalsMST(n, edges);
    cout<<ans;
    return 0;
}