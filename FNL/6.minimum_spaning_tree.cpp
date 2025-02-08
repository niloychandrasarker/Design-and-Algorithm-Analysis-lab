#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Function to implement Prim's algorithm
void primMST(vector<vector<int>> &graph, int V)
{
    vector<int> parent(V, -1);    // Array to store the MST
    vector<int> key(V, INF);      // Key values to select minimum weight edge
    vector<bool> inMST(V, false); // To track if the vertex is included in MST

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to pick the minimum weight edge

    key[0] = 0;      // Start with the first vertex
    pq.push({0, 0}); // {key, vertex}

    while (!pq.empty())
    {
        int u = pq.top().second; // Extract the vertex with minimum key value
        pq.pop();

        inMST[u] = true; // Include the vertex in MST

        // Update key values and parent for the adjacent vertices of u
        for (int v = 0; v < V; ++v)
        {
            // If v is not in MST and there is an edge from u to v
            if (!inMST[v] && graph[u][v] != 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                pq.push({key[v], v}); // Push the updated key value and vertex into the priority queue
                parent[v] = u;        // Update the parent of v
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0)); // Create an adjacency matrix

    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // For undirected graph
    }

    // Call Prim's algorithm to find the MST
    primMST(graph, V);

    return 0;
}
