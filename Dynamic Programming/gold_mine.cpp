int gold_mine (int gold[][], int n, int m) {
    int dp[m][2];
    
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            int right = (j == m - 1 ? 0 : dp[i][(j + 1) & 1]);
            int right_down = (i == n - 1 || j == m - 1 ? 0 : dp[i + 1][(j + 1) & 1]);
            int right_up = (i == 0 || j == m - 1 ? 0 : dp[i - 1][(j + 1) & 1]);
            
            dp[i][j & 1] = gold[i][j] + max({right_up, right, right_down});
        }
    }
    
    int ans = dp[0][0];
    
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp[i][0]);
    }
    
    return ans;
}