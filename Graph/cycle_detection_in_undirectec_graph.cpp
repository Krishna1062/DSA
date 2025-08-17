//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include<iostream>
#include<vector>
#include<queue>

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

    bool cycleDSF(int node, int parent, vector<bool> &visited){
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = cycleDSF(neighbour, node, visited);
                if(cycleDetected){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }

    bool isCycle(int n){
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool ans = cycleDSF(i, -1, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }


    bool cycleBSF(int n){
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        queue<int> q;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = -1;

                while(!q.empty()){
                    int front = q.front();
                    q.pop();

                    for(auto neighbour: adj[front]){
                        if(!visited[neighbour]){
                            visited[neighbour] = true;
                            parent[neighbour] = front;
                            q.push(neighbour);
                        }
                        else if(parent[front] != neighbour){ // neighbour is visisted and its parent if not - cycle exist;
                            return true;
                        }
                    }
                }
            }
        }

        return false;

    }
};

int main(){
    int n;
    cout<<"Enter the no of node :";
    cin>>n;
    int m;
    cout<<"Enter the no of edges :";
    cin>>m;
    
    graph g(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    if(g.isCycle(n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}