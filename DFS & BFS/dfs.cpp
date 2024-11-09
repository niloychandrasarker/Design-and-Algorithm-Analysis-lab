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
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);
    return 0;
}
