int numCC () {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    return cnt;
}