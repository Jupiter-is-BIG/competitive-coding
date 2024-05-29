#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    if (c == 'g') {cout << 0 << "\n"; return;}

    int ans = 0;
    vector<int> g, o;
    for(int i = 0; i < n; ++i) {
        if (s[i] == 'g') g.push_back(i);
        else if (s[i] == c) o.push_back(i);
    }

    int x = g[g.size() - 1];
    for(int& i: o) {
        if (i > x) ans = max(ans, n - i + g[0]);
        else if (i < g[0]) ans = max(ans, g[0] - i);
        else {
            int l = 0; // good
            int r = g.size() - 1; // bad
            while (r > l + 1) {
                int m = (l + r) / 2;
                if (g[m] < i) l = m;
                else r = m;
            }
            ans = max(ans, g[r] - i);
        }
    }
    cout << ans << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) solve();
}
