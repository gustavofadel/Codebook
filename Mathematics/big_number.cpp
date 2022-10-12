typedef vector<int> big_num;

const int base = (int) 1e9;

void print (big_num a) {
    cout << (a.empty() ? 0 : a.back());
    
    for (int i = (int) a.size() - 2; i >= 0; i--) {
        cout << setw(9) << setfill('0') << a[i];
    }
}

big_num convert (string s) {
    big_num a;
    
    for (int i = s.length(); i > 0; i -= 9) {
        if (i < 9) {
            a.push_back(atoi(s.substr(0, i).c_str()));
        }
        
        else {
            a.push_back(atoi(s.substr(i - 9, 9).c_str()));
        }
    }
    
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
    
    return a;
}

big_num addition (big_num a, big_num b, int base) {
    int carry = 0;
    
    for (int i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i == a.size()) {
            a.push_back(0);
        }
        
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        
        if (carry) {
            a[i] -= base;
        }
    }
    
    return a;
}

big_num subtraction (big_num a, big_num b, int base) {
    int carry = 0;
    
    for (int i = 0; i < b.size() || carry; i++) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        
        if (carry) {
            a[i] += base;
        }
    }
    
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
    
    return a;
}

big_num multiplication (big_num a, big_num b, int base) {
    big_num c(a.size() + b.size());
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0, carry = 0; j < b.size() || carry; j++) {
            ll cur = c[i + j] + a[i] * 1LL * (j < b.size() ? b[j] : 0) + carry;
            c[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    }
    
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    
    return c;
}

big_num division (big_num a, int b, int base) {
    int carry = 0;
    
    for (int i = (int) a.size() - 1; i >= 0; i--) {
        ll cur = a[i] + carry * 1LL * base;
        a[i] = int(cur / b);
        carry = int(cur % b);
    }
    
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
    
    return a;
}