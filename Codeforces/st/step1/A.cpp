#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {

    ll size;
    vector<ll> sums;

    void init(ll n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {if (lx < a.size()) sums[x] = a[lx]; return;}

        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<ll> &a) {
        build(a, 0, 0, size);    
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {sums[x] = v; return;}

        ll m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if (l >= rx || lx >= r) return 0;
        if (l <= lx && rx <= r) return sums[x];

        ll m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);

        return s1 + s2;
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }

};


int main() {
    ll n, m;
    cin >> n >> m;
    
    segtree s;
    s.init(n);
    vector<ll> a(n);
    
    for(ll i = 0; i < n; ++i) cin >> a[i];
    s.build(a);
    while(m--) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll i, v;
            cin >> i >> v;
            s.set(i, v);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << s.sum(l, r) << "\n";
        }
    } 

    return 0;
}
