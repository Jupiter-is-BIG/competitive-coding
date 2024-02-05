#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
vector<ll> a;

bool good(ll t) {
    ll c = 0, cc = 1;
    for(ll i = 1; i < n; ++i) {
        if (a[i] >= a[c] + t) {c = i; cc++;}
    }
    return cc >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    ll l = 0;
    ll r = 1;
    while(good(r)) r*=2;

    while(r > l + 1) {
        ll m = (l + r) / 2;
        if (good(m)) l = m;
        else r = m;
    }
    cout << l << "\n";
    return 0;
}
