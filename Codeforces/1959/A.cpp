#include<bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;
        int xx;
        map<int, int> a;
        vector<int> b(n);
        for(int i = 0; i < n; ++i) {int m = 0; cin >> m; a[m]++; b[i] = m;}
        for(pair<int, int> x: a) {
            if (x.second == 1) {xx = x.first; break;} 
        }
        for(int i = 0; i < n; ++i) {if (b[i] == xx) {cout << (i+1) << "\n"; return;}}

}

int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();    
    }
}
