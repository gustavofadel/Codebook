stack<pair<int, int>> s1, s2;

void add_element (int new_element) {
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
}

int remove_element () {
    if (s2.empty()) {
        while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
        }
    }
    int removed_element = s2.top().first;
    s2.pop();
    return removed_element;
}

int get_minimum_element () {
    int minimum;
    
    if (s1.empty() || s2.empty()) {
        minimum = s1.empty() ? s2.top().second : s1.top().second;
    }
    
    else {
        minimum = min(s1.top().second, s2.top().second);
    }
    
    return minimum;
}