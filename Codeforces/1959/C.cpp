#include<bits/stdc++.h>
using namespace std;

pair<int, int> idx(int x) {
    x = x - 'A';
    int i = 0;
    if (x >= 26) {x -= 32; i = 1;}
    return {x, i};
}

void solve() {
    int ans = 0;
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> a(26);

    for(int i = 0; i < n; ++i) {
        pair<int, int> x = idx(s[i]);
        if (x.second == 1) {
            if (a[x.first].first > 0) {a[x.first].first--; ans++;}
            else a[x.first].second++;
        }
        else {
            if (a[x.first].second > 0) {a[x.first].second--; ans++;}
            else a[x.first].first++;
        }
    }

    for(int i = 0; i < 26 && k > 0; ++i) {
        int val = max(a[i].first, a[i].second);
        if (val == 0) continue;
        
        if (val / 2 <= k) {ans += (val/2); k -= (val/2);}
        else {ans+=k; k = 0;}
    }
    
    cout << ans << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) solve();
}
