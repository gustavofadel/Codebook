vector<ll> factorization (ll n, vector<ll> primes) {
    vector<ll> factors;
    
    for (ll d: primes) {
        if (d * d > n) {
            break;
        }
        
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    
    if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
} 