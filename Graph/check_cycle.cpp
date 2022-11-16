int cycle = 0;

void check (int u) {
    vis[u] = 1;

    for (int v: adj[u]) {
        if (!vis[v]) {
            check(v);
        }

        else if (vis[v] == 1) {
            cycle = 1;
        }
    }

    vis[u] = 2;
}