using u64 = uint64_t;
using u128 = __uint128_t;

u64 bin_pow (u64 a, u64 b, u64 m) {
    u64 res = 1;
    
    a %= m;
    
    while (b) {
        if (b & 1) {
            res = (u128) res * a % m;
        }
        
        a = (u128) a * a % m;
        b >>= 1;
    }
    
    return res;
}

bool check_composite (u64 n, u64 a, u64 d, int s) {
    u64 x = bin_pow(a, d, n);
    
    if (x == 1 || x == n - 1) {
        return false;
    }
    
    for (int r = 1; r < s; r++) {
        x = (u128) x * x % n;
        
        if (x == n - 1) {
            return false;
        }
    }
    
    return true;
}

bool miller_rabin (u64 n) {
    if (n < 2) {
        return false;
    }
    
    int r = 0;
    ull d = n - 1;
    
    while (!(d & 1)) {
        d >>= 1;
        r++;
    }
    
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) {
            return true;
        }
        
        if (check_composite(n, a, d, r)) {
            return false;
        }
    }
    
    return true;
}