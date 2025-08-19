// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;

class graph
{
public:
    vector<vector<int>> adj;
    graph(int n)
    {
        adj.resize(n);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = true;

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, st, adj);
            }
        }
        st.push(node);
    }
    void revDfs(int node, vector<bool> &visited, vector<vector<int>> &transpose)
    {
        visited[node] = true;

        for (int nbr : transpose[node])
        {
            if (!visited[nbr])
            {
                revDfs(nbr, visited, transpose);
            }
        }
    }
    int kosaraju()
    {
        int n = adj.size();
        vector<bool> visited(n, false);

        // topo sort
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }

        vector<vector<int>> transpose(n);

        // transpose graph
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            for (int nbr : adj[i])
            {
                transpose[nbr].push_back(i);
            }
        }

        // dfs call for above ordering
        int count = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!visited[top])
            {
                count++;
                revDfs(top, visited, transpose);
            }
        }

        return count;
    }
};

int main()
{
    int n = 5;
    int m = 5;
    graph g(n);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    int ans;

    ans = g.kosaraju();
    cout << ans;
    return 0;
}