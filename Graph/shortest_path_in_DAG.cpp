// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// 1 is src
#include<iostream>
#include<vector>
#include<stack>
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
    }
    void dfs(int node, vector<int> &visited, stack<int> &s){
        visited[node] = true;
        
        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V) {
        
        stack<int> s;
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, s);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[1] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(dist[top] != INT_MAX){
                for(auto i:adj[top]){
                    int wt = i.second;
                    if(dist[top] + wt < dist[i.first]){
                        dist[i.first] = dist[top] + wt;
                    }
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

int main(){
    int n=6;
    int m = 9;
    graph g(6);
    g.addEdge(0,1,5);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(0,2,3);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(4,5,-2);
    g.addEdge(3,4,-1);

    vector<int> ans;

    ans = g.shortestPath(n);

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}