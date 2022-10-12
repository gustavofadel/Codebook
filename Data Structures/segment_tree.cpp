void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = array[left];
        return;
    }
    
    int mid = (left + right) / 2;
    
    build(2 * node + 1, left, mid);
    build(2 * node + 1, mid + 1, right);
    
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void update (int node, int left, int right, int index, int value) {
    if (left == right) {
        tree[node] = value;
        array[index] = value;
        return;
    }
    
    int mid = (left + right) / 2;
    
    if (left <= index && index <= mid) {
        update(2 * node + 1, left, mid, index, value);
    }
    
    else {
        update(2 * node + 2, mid + 1, right, index, value);
    }
    
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query (int node, int left, int right, int query_left, int query_right) {
    if (left > query_right || right < query_left) {
        return 0;
    }
    
    if (query_left <= left && right <= query_right) {
        return tree[node];
    }
    
    int mid = (left + right) / 2;
    
    return query(2 * node + 1, left, mid, query_left, query_right) + query(2 * node + 2, mid + 1, right, query_left, query_right);
}