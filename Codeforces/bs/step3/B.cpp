#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
vector<ll> a;

bool good(ll t) {
    ll c = 0;
    ll cc = 0;
    for(ll i = 1; i <= n; ++i) {
        if (cc == k) return false;
        if (a[i] - a[c] > t) {if (c == i - 1) return false; c = i - 1; cc++; i--;}
    }
    return true;
}

int main() {
    cin >> n >> k;
    a.resize(n+1);

    for(ll i = 1; i <= n; ++i) {cin >> a[i]; a[i] += a[i-1];}

    ll l = 0; // bad
    ll r = 1;
    while(!good(r)) r*=2;
    while(r > l + 1) {
        ll m = (l + r) / 2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << r << "\n";

    return 0;
}
