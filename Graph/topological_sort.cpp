// Armazena a ordem dos vértices na ordem reversa
vector<int> order;

void dfs (int u) {
    vis[u] = 1;

    for (int v: adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    order.push_back(u);
}