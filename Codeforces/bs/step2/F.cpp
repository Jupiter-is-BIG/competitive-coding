#include<bits/stdc++.h>
using namespace std;

int n;
string t, p;
vector<int> a;

bool good(int x) {
    string c = t;
    for(int i = 0; i < x; ++i) {
        c[a[i] - 1] = '-';
    }

    int j = 0, m = p.size();
    for(int i = 0; i < n; ++i) {
        if (c[i] == p[j]) j++;
        if (j == m) return true;
    }
    
    return false;
}

int main() {
    cin >> t;
    cin >> p;
    n = t.size();
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    int l = 0; // good
    int r = n; // bad

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (good(m)) l = m;
        else r = m;
    }
    
    cout << l << "\n";
    return 0;
}
