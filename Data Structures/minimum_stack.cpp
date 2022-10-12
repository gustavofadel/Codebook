stack<pair<int, int>> st;

void add_element (int new_elem) {
    int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
    st.push({new_elem, new_min});
}

int remove_element () {
    int removed_element = st.top().first;
    st.pop();
    return removed_element;
}

int get_minimum_element () {
    int minimum = st.top().second;
    return minimum;
}