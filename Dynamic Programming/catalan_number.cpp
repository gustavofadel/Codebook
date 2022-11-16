ull catalan (int n) {
    return binomial_coefficient(2 * n, n) / (n + 1);
}