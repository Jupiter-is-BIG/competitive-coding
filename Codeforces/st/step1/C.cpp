#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item {
    ll v;
    ll c;
};

struct segtree {
    ll size;
    vector<item> values;
    item NEUTRAL_ELE = {static_cast<ll>(1e10 + 3), 1};

    item single(ll x) {
        return {x, 1};
    }

    item merge(item a, item b) {
        if (a.v > b.v) return b;
        if (a.v < b.v) return a;

        return {a.v, a.c + b.c};
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

    item calc(ll l, ll r, ll x, ll lx ,ll rx) {
        if (lx >= r || rx <= l) return NEUTRAL_ELE;
        if (l <= lx && rx <= r) return values[x];

        ll m = (lx + rx) / 2;
        item val1 = calc(l, r, 2 * x + 1, lx, m);
        item val2 = calc(l, r, 2 * x + 2, m, rx);

        return merge(val1, val2);
    }

    item calc(ll l, ll r) {
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
            auto val = s.calc(l, r);
            cout << val.v << " " << val.c << "\n";
        }
    }
    return 0;
}

