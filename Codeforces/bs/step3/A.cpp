#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> x, v;

bool good(double t) {
    double ma = x[0] - v[0]*t;
    double mi = x[0] + v[0]*t;

    for(ll i = 0; i < n; ++i) {
        ma = max(ma, x[i] - v[i] * t);
        mi = min(mi, x[i] + v[i] * t);
    }

    return ma <= mi;
}

int main() {
    cin >> n;
    x.resize(n);
    v.resize(n);

    bool flag = true;

    for(ll i = 0; i < n; ++i) {
        cin >> x[i];
        cin >> v[i];
        if (i > 0 && x[i] != x[i-1]) flag = false;
    }

    if (flag) {cout << 0 << "\n"; return 0;}

    double l = 0; // bad
    double r = 1;
    while (!good(r)) r*=2;

    for(int _ = 0; _ < 100; ++_) {
        double m = (l + r) / 2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << setprecision(20) << r << "\n";

    return 0;
}
