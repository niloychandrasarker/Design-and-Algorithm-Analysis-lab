#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1000];
bool visited[1000];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int v : edge[current]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
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
            edge[i].push_back(neighbor);
            edge[neighbor].push_back(i);
        }
    }

    cout << "BFS starting from node 1: ";
    bfs(1);
    cout << endl;

    return 0;
}
