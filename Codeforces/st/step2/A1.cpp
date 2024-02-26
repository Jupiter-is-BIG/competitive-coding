#include<bits/stdc++.h>
using namespace std;

struct item {
    long long val;
};

struct segtree {
    long long size;
    vector<long long> values;

    void init(long n) {
        size = 1;
        while (size < n) size *= 2;
        values.resize(2 * size);
    }

    void build(vector<long long> &a, long long x, long long lx, long long rx) {
        if (rx - lx == 1) {if (lx < a.size()) values[x] = a[lx]; return;}

        long long m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void build(vector<long long> &a) {
        build(a, 0, 0, size);
    }

    void set(long long i, long long v, long long x, long long lx, long long rx) {
        if (rx - lx == 1) {values[x] = v; return;}

        long long m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);

        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void set(long long i, long long v) {
        set(i,v,0,0,size);
    }

    long long calc(long long l, long long r, long long x, long long lx, long long rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return values[x];

        long long m = (lx + rx) / 2;
        long long c1 = calc(l, r, 2 * x + 1, lx, m);
        long long c2 = calc(l, r, 2 * x + 2, m, rx);

        return c1 + c2;
    }

    long long calc(long long l, long long r) {
        return calc(l, r, 0, 0, size);
    }
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    segtree s;
    s.init(n);
    s.build(a);
    while(m--) {
        long long q;
        cin >> q;
        if (q == 1) {
            long long i, v;
            cin >> i >> v;
            s.set(i, v);
        } else {
            long long l, r;
            cin >> l >> r;
            cout << s.calc(l, r) << "\n";
        }
    }
    return 0;
}
