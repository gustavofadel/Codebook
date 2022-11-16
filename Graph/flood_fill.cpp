int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int is_valid (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void flood_fill (int x, int y, char c1, char c2) {
    if (!is_valid(x, y)) return;
    if (grid[x][y] != c1) return;
    for (int i = 0; i < 8; i++) flood_fill(x + dx[i], y + dy[i], c1, c2);
}