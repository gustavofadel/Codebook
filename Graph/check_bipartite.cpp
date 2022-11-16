int is_bipartite (int s) {
    int ok = 1;
    queue<int> q;
    vector<int> color(n, INF);

    color[s] = 0;
    q.push(s);

    while (!q.empty() && ok) {
        int u = q.front(); q.pop();

        for (int v: adj[u]) {
            if (color[v] == INF) {
                color[v] = 1 - color[u];
                q.push(v);
            }

            else if (color[v] == color[u]) {
                ok = 0;
                break;
            }
        }
    }

    return ok;
}