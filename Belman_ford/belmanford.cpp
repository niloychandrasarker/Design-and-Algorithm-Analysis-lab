#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj[105];
bool node[105];
vector<int> previous(105, 0);
vector<int> distTo(105, INT_MAX);
int n;
void printParents()
{
    cout << "Parents of Every Nodes: ";
    for (int i = 0; i <= n; i++)
    {
        if (node[i])
        {
            cout << i << "(" << previous[i] << ") ";
        }
    }
    cout << endl;
}
void printDist()
{
    cout << "Distance of Every Nodes: ";
    for (int i = 1; i <= n; i++)
    {
        if (node[i])
        {
            cout << i << "(" << distTo[i] << ") ";
        }
    }
    cout << endl;
}

void BellmanFord(int V, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distTo[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            cout << "\tPresent Minimum Node: " << v << " and weight is: " << w << endl;
            cout << "\tSource = " << node << " and Destination = " << v << endl;
            cout << "\t\tdistance[" << node << "] + " << w << " = " << (dis + w) << " and distance[" << v << "]= " << distTo[v] << endl;
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
                previous[v] = node;
                it[1] = dis + w;
            }
            printParents();
            printDist();
            cout << endl;
        }
    }
}
int main()
{
    // Driver code.
    int V, E, S;
    cout << "Enter Number of nodes and Edges: ";
    cin >> V >> E;
    n = V;
    cout << "Enter source and destination with weight format as(u->v w)" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        node[u] = true;
        node[v] = true;
    }
    cout << "Enter the source: " << endl;
    cin >> S;
    printParents();
    printDist();
    cout << endl;
    BellmanFord(V, S);
    cout << "Final Results of Shortest Path: " << endl;
    printParents();
    printDist();
    cout << endl;
    return 0;
}