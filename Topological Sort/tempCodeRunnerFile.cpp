#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(int v, vector<int> adj[]) {
    int indegree[v] = {0};
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topological;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topological.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topological;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = topologicalsort(nodes, adj);

    cout << "Topological Order: ";
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
