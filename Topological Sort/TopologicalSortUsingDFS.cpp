#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];
stack<int> result;

void dfs(int source) {
    visited[source] = true;
    for (int v : graph[source]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    result.push(source);
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << "Topological Order: ";
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> graph[1000];
//bool visited[1000];
//stack<int> result;
//
//void dfs(int source) {
//    visited[source] = true;
//    for (int v : graph[source]) {
//        if (!visited[v]) {
//            cout << "\t" << source << " is connected with " << v << " and DFS(" << v << ") is called" << endl;
//            dfs(v);
//        }
//    }
//
//    cout << "\t\t" << source << " is paused and added to the result stack." << endl;
//    result.push(source);
//}
//
//int main() {
//    int nodes, edges;
//    cin >> nodes >> edges;
//
//    for (int i = 0; i < edges; i++) {
//        int u, v;
//        cin >> u >> v;
//        graph[u].push_back(v);
//    }
//
//
//    for (int i = 0; i < nodes; i++) {
//        if (!visited[i]) {
//            cout << i << "th node is unvisited, and DFS is called." << endl;
//            dfs(i);
//        }
//    }
//
//    cout << "Topological Order: ";
//    while (!result.empty()) {
//        cout << result.top() << " ";
//        result.pop();
//    }
//    cout << endl;
//
//    return 0;
//}
