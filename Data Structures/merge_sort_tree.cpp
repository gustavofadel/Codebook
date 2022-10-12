void build (int node, int left, int right) {
    if (left == right) {
        tree[node].push_back(array[left]);
        return;
    }
    
    int left_node = 2 * node, mid = (left + right) / 2, right_node = 2 * node + 1;
    
    build(left_node, left, mid);
    build(right_node, mid + 1, right);
    
    merge(tree[left_node].begin(), tree[left_node].end(), tree[right_node].begin(), tree[right_node].end(), back_inserter(tree[node]));
}

int query (int node, int left, int right, int query_left, int query_right, int value) {
    if (left > query_right || right < query_left) {
        return 0;
    }
    
    if (query_left <= left && right <= query_right) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
    }
    
    int mid = (left + right) / 2;
    
    return query(2 * node, left, mid, query_left, query_right, value) + query(2 * node + 1, mid + 1, right, query_left, query_right, value);
}