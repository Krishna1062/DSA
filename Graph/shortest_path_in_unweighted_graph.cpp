// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>

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

    
    vector<int> shortestPath(int s , int t){

	// create visited and parent vector
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	
	// do bfs
	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(int neighbour: adj[front]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}

	// go from destination to source using parent array
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);
	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());

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

    graph g(n+1);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }

    vector<int> ans = g.shortestPath(1, 8);
    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}
// 1 2
// 2 5
// 5 8
// 3 8
// 4 6
// 6 7
// 7 8
// 1 3
// 1 4