// https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;

class graph
{
public:
    void dfs(int node, int timer, vector<vector<int>> &result, vector<int> &disc, vector<int> &low, vector<bool> &visited, int parent, vector<vector<int>> &adj){
        visited[node] = true;
        disc[node] = low[node] = timer++;

        for(int nbr: adj[node]){
            if(nbr == parent)
                continue;
            if(!visited[nbr]){
                dfs(nbr, timer, result, disc, low, visited, node, adj);
                low[node] = min(low[node], low[nbr]);
                // check edge is a brige
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else{
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }    
    }
    vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<bool> visited(v, false);

    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, timer, result, disc, low, visited, parent, adj);
        }
    }
    return result;

    }
};

int main()
{
    int n = 5;
    int m = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {3, 1},
        {1, 2},
        {3 ,4},
        {3 ,3},
        {0 ,1},
        {1 ,2},
        {2 ,0}};
    graph g;

    vector<vector<int>> ans;

    ans = g.findBridges(edges, n, m);
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}