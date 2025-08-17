// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<iostream>
#include<vector>
using namespace std;

class graph{
    public:
    vector<vector<int>> adj;

    graph(int n){
        adj.resize(n);
    }

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    bool isCycleDSF(int node, vector<bool>& visited, vector<bool> &dsfVisited){
        visited[node] = true;
        dsfVisited[node] = true;
        
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleFound = isCycleDSF(neighbour, visited, dsfVisited);
                if(cycleFound) return true;
            }
            else if(dsfVisited[neighbour]) return true;// when both dsfvisited and visited are true
        }
        dsfVisited[node] = false;
        return false;
    }

    bool isCyclic(int V) {        
        vector<bool> visited(V, false);
        vector<bool> dsfVisited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCycleDSF(i, visited, dsfVisited);
                if (ans) return true;
            }
        }
        return false;
    }

};

int main(){
    int n;
    cout<<"Enter the no of vertices :";
    cin>>n;

    int m;
    cout<<"Enter the no of edges :";
    cin>>m;

    graph g(n);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v, 1);
    }

    if(g.isCyclic(n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}