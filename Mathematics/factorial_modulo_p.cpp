int fat_mod (int n, int p) {
    int res = 1;
    vector<int> fat(p);
    
    fat[0] = 1;
    
    for (int i = 1; i < p; i++) {
        fat[i] = (fat[i - 1] * i) % p;
    }
    
    while (n > 1) {
        if ((n / p) & 1) {
            res = p - res;
        }
        
        (res *= fat[n % p]) %= p;
        n /= p;
    }
    
    return res;
}