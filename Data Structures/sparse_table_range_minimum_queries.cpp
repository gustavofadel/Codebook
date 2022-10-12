int lg[MAXN + 1], st[MAXN][k + 1];

void build (int n) {
    lg[1] = 0;
    
    for (int i = 2; i <= MAXN; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = array[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query (int l, int r) {
    int j = lg[r - l + 1];
    int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
    return minimum;
}