vector<int> dijkstra (int s) {
    priority_queue<ii, pair<ii>, greater<ii>> pq;
    vector<int> dist(n, INF);

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}