ll bin_pow (ll a, ll b, ll m) {
    ll res = 1;
    
    a %= m;
    
    while (b) {
        if (b & 1) {
            (res *= a) %= m;
        }
        
        (a *= a) %= m;
        b >>= 1;
    }
    
    return res;
}