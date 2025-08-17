#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class graph{
    vector<vector<int>> adj;
    public:
    graph(int n){
        adj.resize(n);
    }
    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
    }

    void topoSolve(int node, vector<bool> &visited, stack<int> &s){
        visited[node] = true;

        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                topoSolve(neighbour, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> topoSort(int n){
        vector<bool> visited(n, false);
        stack<int> s;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                topoSolve(i, visited, s);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter the no of node :";
    cin>>n;

    int m;
    cout<<"Enter the no of edge :"; 
    cin>>m;

    graph g(n);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 1);
    }

    vector<int> ans = g.topoSort(n);
    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}