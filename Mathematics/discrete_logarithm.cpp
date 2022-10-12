// Returns minimum x for which a ^ x % m = b % m
int discrete_log (int a, int b, int m) {
    int add = 0, an = 1, g, k = 0, n;
    unordered_map<int, int> vals;
    
    a %= m, b %= m;
    
    while((g = __gcd(a, m)) > 1) {
        if (b == k) {
            return add;
        }
        
        if (b % g) {
            return -1;
        }
        
        b /= g, m /= g, add++;
        k = (1LL * k * a / g) % m;
    }
    
    n = sqrt(m) + 1;
    
    for (int i = 0; i < n; i++) {
        an = (1LL * an * a) % m;
    }
    
    for (int cur = b, q = 0; q <= n; q++) {
        vals[cur] = q;
        cur = (1LL * cur * a) % m;
    }
    
    for (int cur = k, p = 1; p <= n; p++) {
        cur = (1LL * cur * an) % m;
        
        if (vals.count(cur)) {
            return n * p - vals[cur] + add;
        }
    }
    
    return -1;
}