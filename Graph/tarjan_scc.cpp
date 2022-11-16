int dfs_low[N], dfs_num[N], dfs_num_cnt, num_scc, vis[N];
vector<int> st;

void tarjan_scc (int u) {
    dfs_low[u] = dfs_num[u] = dfs_num_cnt++;
    st.push_back(u);
    vis[u] = 1;

    for (int v: adj[u]) {
        if (dfs_num[v] == -1) tarjan_scc(v);
        if (vis[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        num_scc++;

        while (1) {
            int v = st.back(); st.pop_back(); vis[v] = 0;
            if (u == v) break;
        }
    }
}

// dentro da main
memset(dfs_num, -1, sizeof(dfs_num));

for (int i = 0; i < n; i++) {
    if (dfs_num[i] == -1) tarjan_scc(i);
}