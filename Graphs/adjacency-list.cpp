#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> &adj_list, int u, int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void printGraph(vector<vector<int>> &adj_list, int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << v << " -> ";
        for (auto i : adj_list[v])
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cin >> V;

    // vector<vector<int>> adj_list(V, vector<int>(0, 0));
    vector<int> adj_list[V];
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 4);
    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 1, 3);
    addEdge(adj_list, 1, 4);
    addEdge(adj_list, 2, 3);
    addEdge(adj_list, 3, 4);
    // printGraph(adj_list, V);

    return 0;
}