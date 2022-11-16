ull binomial_coefficient (int n, int k) {
    ull ret = 1;
    
    k = min(k, n - k);
    
    for (int i = 0; i < k; i++) {
        (ret *= (n - i)) /= (i + 1);
    }
    
    return ret;
}