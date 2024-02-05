#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, d;
vector<ll> a;
ll ta = 1, tb = 1;

bool good(double x) {
    vector<double> p(n+1);
    vector<pair<double, ll>> mi(n+1);
   // mi[0] = a[0] - x;
    for(ll i = 1; i <= n; ++i) {p[i] = p[i - 1] + (a[i - 1] - x); if (mi[i - 1].first > p[i]) {mi[i].first = p[i]; mi[i].second = i;} else {mi[i] = mi[i-1];}}
    for(ll i = n; i >= d; --i) {if (p[i] >= mi[i - d].first) {ta = mi[i - d].second + 1; tb = i; return true;}}
    return false;
}

int main() {
    cin >> n >> d;

    a.resize(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    double l = 0; // good
    double r = 1;
    while(good(r)) r*=2;

    for(ll _ = 0; _ < 100; ++_) {
        double m = (l + r) / 2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << ta << " " << tb << "\n";
    return 0;
}
