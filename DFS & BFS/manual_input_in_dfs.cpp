#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1000];
bool visited[1000];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int v : edge[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the degree of each node:" << endl;
    for (int i = 1; i <= n; i++) {
        int degree;
        cout << "Degree of node " << i << ": ";
        cin >> degree;
        cout << "Enter neighbors of node " << i << ": ";
        for (int j = 0; j < degree; j++) {
            int neighbor;
            cin >> neighbor;
            edge[i].push_back(neighbor);  // Add neighbor to node i's adjacency list
            edge[neighbor].push_back(i);  // Add node i to neighbor's adjacency list (undirected graph)
        }
    }

    cout << "DFS starting from node 1: ";
    dfs(1);  // Start DFS from node 1
    cout << endl;

    return 0;
}
