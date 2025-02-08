#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge
{
    int v, weight;
};

void dijkstra(vector<vector<Edge>> &graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const Edge &edge : graph[u])
        {
            int v = edge.v;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter edges (format: u v weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For an undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source, V);

    return 0;
}
