void process (int u) {
    vis[u] = 1;

    for (auto [v, w]: adj[u]) {
        if (!vis[v]) {
            pq.push({-w, -v})
        }
    }
}

int prim () {
    int cost = 0;

    process(0);

    while (!pq.empty()) {
        auto [w, u] = pq.top(); q.pop();
        u = -u, w = -w;

        if (!vis[u]) {
            cost += w;
            process(u);
        }
    }

    return cost;
}