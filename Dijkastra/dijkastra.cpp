#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[105];
bool vis[105];
bool node[105];
vector<int> previous(105, -1);
vector<int> distTo(105, INT_MAX);
int n;

void printParents()
{
    cout << "Parents of Every Node: ";
    for (int i = 1; i <= n; i++)
    {
        if (node[i])
            cout << i << "(" << previous[i] << ") ";
    }
    cout << endl;
}

void printDist()
{
    cout << "Distance of Every Node: ";
    for (int i = 1; i <= n; i++)
    {
        if (node[i])
            cout << i << "(" << distTo[i] << ") ";
    }
    cout << endl;
}

void printVis()
{
    cout << "Visit Status of Every Node: ";
    for (int i = 1; i <= n; i++)
    {
        if (node[i])
            cout << i << "(" << vis[i] << ") ";
    }
    cout << endl;
}

void dijkstra(int V, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distTo[S] = 0;
    pq.push({0, S});
    vis[S] = true;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (!vis[v] || dist + w < distTo[v])
            {
                distTo[v] = dist + w;
                pq.push({distTo[v], v});
                previous[v] = u;
                vis[v] = true;
            }
        }

        printParents();
        printDist();
        printVis();
        cout << endl;
    }
}

int main()
{
    int V, E, S;
    cout << "Enter Number of nodes and Edges: ";
    cin >> V >> E;
    n = V;

    cout << "Enter edges (u -> v w):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        node[u] = node[v] = true;
    }

    cout << "Enter the source node: ";
    cin >> S;

    printParents();
    printDist();
    printVis();
    cout << endl;

    dijkstra(V, S);

    return 0;
}
