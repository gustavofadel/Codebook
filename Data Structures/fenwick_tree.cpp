struct FenwickTreeSum {
    int n;
    vector<int> bit;
    
    FenwickTreeSum (int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    
    FenwickTreeSum (vector<int> a) : FenwickTreeSum (a.size()) {
        for (int i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }
    
    void add (int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += val;
        }
    }
    
    int sum (int r) {
        int ret = 0;
        
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
        }
        
        return ret;
    }
    
    int sum (int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct FenwickTreeMin {
    const int INF = 0x3f3f3f3f;
    int n;
    vector<int> bit;
    
    FenwickTreeMin (int n) {
        this->n = n;
        bit.assign(n, INF);
    }
    
    FenwickTreeMin (vector<int> a) : FenwickTreeMin (a.size()) {
        for (int i = 0; i < a.size(); i++) {
            update(i, a[i]);
        }
    }
    
    void update (int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] = min(bit[idx], val);
        }
    }
    
    int get (int r) {
        int ret = INF;
        
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret = min(ret, bit[r]);
        }
        
        return ret;
    }
};

struct FenwickTree2D {
    int m, n;
    vector<vector<int>> bit;
    
    FenwickTree2D (int n, int m) {
        this->m = m
        this->n = n;
        bit = vector<vector<int>>(n, vector<int>(m, 0));
    }
    
    FenwickTree2D (vector<vector<int>> a, int n, int m) : FenwickTree2D (n, m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i, j, a[i][j]);
            }
        }
    }
    
    void add (int x, int y, int val) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                bit[i][j] += val;
            }
        }
    }
    
    int sum (int x, int y) {
        int ret = 0;
        
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                ret += bit[i][j];
            }
        }
        
        return ret;
    }
};