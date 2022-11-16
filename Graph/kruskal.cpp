int find (int x) {
    if (par[x] == x) {
        return x;
    }

    return par[x] = find(par[x]);
}

void join (int x, int y) {
    x = find(x), y = find(y);

    if (rnk[x] > rnk[y]) {
        par[y] = x;
    }

    else {
        par[x] = y;

        if (rnk[x] == rnk[y]) {
            rnk[y]++;
        }
    }
}

int kruskal () {
    int cost = 0;

    sort(edges.begin(), edges.end());

    for (auto e: edges) {
        int w = e.first; auto [u, v] = e.second;

        if (find(u) != find(v)) {
            cost += w;
            join(u, v);
        }
    }

    return cost;
}