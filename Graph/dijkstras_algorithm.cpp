// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<iostream>
#include<vector>
#include<set>
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
        adj[v].push_back({u,wt});
    }
    vector<int> dijkstra(int V, int src) {
        //create set and distance array;
        set<pair<int,int>> st;
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            st.erase(st.begin());
            
            for(auto neighbour: adj[node]){
                if(nodeDistance + neighbour.second < distance[neighbour.first]){
                    auto record = st.find({distance[neighbour.first], neighbour.first});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    distance[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({distance[neighbour.first], neighbour.first});
                }    
            }
        }
        
        for(int i=0; i<V; i++){
            if(distance[i] == INT_MAX) distance[i] = -1;
        }
        return distance;
    }
};

int main(){
    int n=5;
    int m = 7;
    graph g(n);
    g.addEdge(0,1,7);
    g.addEdge(0,2,1);
    g.addEdge(0,3,2);
    g.addEdge(1,2,3);
    g.addEdge(1,3,5);
    g.addEdge(1,4,1);
    g.addEdge(3,4,7);

    vector<int> ans;

    ans = g.dijkstra(n, 0);

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}