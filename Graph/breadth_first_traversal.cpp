//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;


class graph{
    public:
    unordered_map<int, list<int>> adj;
    
    void addEdge(int u, int v, bool direction){
        //create edge from u to v
        adj[u].push_back(v);
        if(direction==0)
            adj[v].push_back(u);
    }
    vector<int> bfs() {
        vector<int> ans;
        queue<int>q;
        unordered_map<int, bool> visited;
        

        //for loop for traveling every component even disconnected graph
        for(int i=0; i<adj.size(); i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            
            
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    
                    ans.push_back(front);
                    
                    for(auto neighbour: adj[front]){
                        if(!visited[neighbour]){
                            q.push(neighbour);
                            visited[neighbour] = true;
                        }
                    }
                }
            }
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

    graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }
    vector<int> ans = g.bfs();
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}