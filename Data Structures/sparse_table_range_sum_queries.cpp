ll st[MAXN][k + 1];

void build (int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
        }
    }
}

ll query (int l, int r) {
    ll sum = 0;
    
    for (int j = k; j >= 0; j--) {
        if ((1 << j) <= r - l + 1) {
            sum += st[l][j];
            l += 1 << j;
        }
    }
    
    return sum;
}