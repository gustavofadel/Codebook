void print_path (int s, int u) {
    if (u == s) {
        cout << u;
        return;
    }

    print_path(s, par[u]);
    cout << " " << u;
}

void sssp (int s, int t) {
    queue<int> q;
    vector<int> dist(n, INF);

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v: adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    print_path(s, t);
}