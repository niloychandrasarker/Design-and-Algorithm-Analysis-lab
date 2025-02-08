#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void floydWarshall(vector<vector<int>> &dist, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    cout << "Enter edges and weights (u v w):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floydWarshall(dist, n);

    cout << "Shortest Path Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
