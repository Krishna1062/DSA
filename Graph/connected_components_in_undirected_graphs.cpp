#include<iostream>
#include<vector>
using namespace std;

class graph{
    public:
    vector<vector<int>> adj;
    graph(int n){
        adj.resize(n);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, vector<bool> &visited, vector<int> &component){
        visited[node] = true;
        component.push_back(node);
        
        for(int nbr: adj[node]){
            if(!visited[nbr]){
                dfs(nbr, visited, component);
            }
        }
        
    }

    vector<vector<int>> getComponents(int V) {
        vector<vector<int>> ans;
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, visited, component);
                ans.push_back(component);
            }
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {3, 4}};
    graph g(5);
    for(int i=0; i<edges.size(); i++){
        g.addEdge(edges[i][0], edges[i][1]);
    }

    vector<vector<int>> ans;
    ans = g.getComponents(5);

    cout << "Connected Components:\n";
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}