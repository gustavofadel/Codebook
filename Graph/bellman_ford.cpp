vector<int> bellman_ford (int s) {
    vector<int> dist(n, INF);

    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w]: adj[u]) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
}