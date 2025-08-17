#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    vector<vector<int>> adj;

    graph(int n){
        adj.resize(n);
    }
   
    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }

    void dfsSolve(int node, unordered_map<int, bool>&visited, vector<int> &ans){
        ans.push_back(node);
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                dfsSolve(neighbour, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<int> &ans){
        unordered_map<int, bool> visited;
        for(int i=0; i<adj.size(); i++){
            if(!visited[i])
                dfsSolve(i, visited, ans);
        }
        return ans;
    }
};


int main(){
    int n;
    cout<<"Enter the no of nodes :";
    cin>>n;

    int m;
    cout<<"Enter the no of edges :";
    cin>>m;
    vector<int> ans;
    graph g(n);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }
    g.dfs(ans);
    
    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}