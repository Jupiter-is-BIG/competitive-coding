#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segtree {
    ll size;
    vector<ll> values;
    ll NEUTRAL_ELE = 1e9 + 3;

    ll single(ll x) {
        return x;
    }

    ll merge(ll a, ll b) {
        return min(a, b);
    }


    void init(ll n) {
        size = 1;
        while (size < n) size *= 2;
        values.resize(2 * size);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) values[x] = single(a[lx]);
            return;
        }
        
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {values[x] = single(v); return;}

        ll m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll calc(ll l, ll r, ll x, ll lx ,ll rx) {
        if (lx >= r || rx <= l) return NEUTRAL_ELE;
        if (l <= lx && rx <= r) return values[x];

        ll m = (lx + rx) / 2;
        ll val1 = calc(l, r, 2 * x + 1, lx, m);
        ll val2 = calc(l, r, 2 * x + 2, m, rx);

        return merge(val1, val2);
    }

    ll calc(ll l, ll r) {
        return calc(l, r, 0, 0, size);
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    segtree s;
    s.init(n);
    s.build(a);

    while(m--) {
        ll q; cin >> q;
        if (q == 1) {
            ll i, v;
            cin >> i >> v;
            s.set(i, v);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << s.calc(l, r) << "\n";
        }
    }
    return 0;
}
