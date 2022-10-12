for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask; submask = (submask - 1) & mask) {
        // Rest of code
    }
}