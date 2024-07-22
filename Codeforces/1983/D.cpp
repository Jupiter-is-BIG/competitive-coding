// File generated on 24/07/22 09:04 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define sz size

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> vecc;
typedef vector<pll> vecp;

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

    ll offset(ll l) {
        return sum(l, size+1);
    }

    void up(ll i) {
        set(i, sum(i,i+1)+1);
    }

    void down(ll i) {
        set(i, sum(i,i+1)-1);
    }

};

void SOLVE() {
    ll n;
    cin >> n;
    map<ll, pll> A;
    bool flag = false;
    rep(i,1,n+1) {ll x; cin >> x; A[x].second = i;}
    rep(i,1,n+1) {ll x; cin >> x; if (A[x].second == 0) flag = true; A[x].first = i;}
    if (flag) {NO; return;}

    vecp B;
    B.pb({0,0});
    for(auto& i: A) B.pb(i.second);
    sort(B.begin(), B.end());
    
    ll p = 0;
    segtree s;
    s.init(n+2);

    rep(i,1,n+1) {
        ll cur = B[i].second + s.offset(B[i].second + 1);
        ll des = B[i].first;
        p = (p+cur-des)%2;
        s.up(B[i].second);
        //s.down(des);
    }
    if(p&1) NO;
    else YES;
}

signed main() {
    fastio;
    ll _;
    cin >> _;
    while(_--) SOLVE();
    return 0;
}

