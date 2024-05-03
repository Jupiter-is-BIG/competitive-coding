#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int x; cin >> x;

    int l = -1; // a[l] <= m
    int r = n; // a[r] > m

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }

    if (a[l] == x) cout << "YES\n";
    else cout << "NO\n";
}
