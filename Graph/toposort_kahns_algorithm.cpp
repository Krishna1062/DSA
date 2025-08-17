#include<iostream>
#include<vector>
#include<queue>
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

    vector<int> topoSort(int V) {
        // find indegrees
        vector<int> indegree(V);
        for(int i=0; i<V; i++){
            for(int neighbour: adj[i]){
                indegree[neighbour]++;
            }
        }
        
        // push all values with indegree 0;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // do bfs, 
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(int neighbour: adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        if (ans.size() != V) {
            cout << "Cycle detected! Topological sort not possible.\n";
            return {};
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