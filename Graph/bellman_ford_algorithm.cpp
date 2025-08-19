// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;

class graph
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i=0; i<V; i++){
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // check negative cycle;
        bool flag = 0;
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                flag = 1;
            }
        }
        
        if(flag == 0){
            return dist;
        }
        return {-1};
    }
};

int main()
{
    int n = 5;
    int m = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    graph g;

    vector<int> ans;

    ans = g.bellmanFord(5, edges, 0);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}