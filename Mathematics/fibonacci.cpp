int fibonacci (int n) {
    return (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
}