#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item {
    ll pre, suf, sum, seg;
};

struct segtree {
    ll size;
    item NEUTRAL_ELE = {0ll, 0ll, 0ll, 0ll};
    vector<item> values;
    item single(ll x) {
        return {max(0ll, x), max(0ll, x), x, max(0ll, x)};
    }

    item merge(item a, item b) {
        item c;
        c.seg = max(a.seg, max(b.seg, a.suf + b.pre));
        c.pre = max(a.pre, a.sum + b.pre);
        c.suf = max(a.suf + b.sum, b.suf);
        c.sum = a.sum + b.sum;
        return c;
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

    item calc(ll l, ll r, ll x, ll lx, ll rx) {
        if (rx <= l || r <= lx) return NEUTRAL_ELE;
        if (l <= lx && rx <= r) return values[x];

        ll m = (lx + rx) / 2;
        item c1 = calc(l, r, 2 * x + 1, lx, m);
        item c2 = calc(l, r, 2 * x + 2, m, rx);

        return merge(c1, c2);
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
    cout << s.calc(0, n).seg << "\n";
    while(m--) {
        ll i, v;
        cin >> i >> v;
        s.set(i, v);
        cout << s.calc(0,n).seg << "\n";
    }
    return 0;
}
