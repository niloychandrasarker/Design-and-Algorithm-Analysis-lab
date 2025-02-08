#include <bits/stdc++.h>
using namespace std;

bool vis[105];
vector<int> adj[105], adjT[105];
stack<int> st;

void dfs(int node)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    st.push(node);
}

void dfs3(int node)
{
    vis[node] = true;
    cout << node << " ";
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it);
        }
    }
}

int kosaraju(int V)
{
    // Step 1: DFS on original graph to fill the stack
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    // Step 2: Reverse the graph
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // Step 3: Reset visited array for the second DFS
    memset(vis, 0, sizeof(vis));

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            cout << scc << " SCC is: ";
            dfs3(node);
            cout << endl;
        }
    }
    return scc;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = kosaraju(nodes); // Pass the number of nodes, not edges
    cout << "The number of strongly connected components is: " << ans << endl;

    return 0;
}
