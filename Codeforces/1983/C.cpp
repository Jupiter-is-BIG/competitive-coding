// File generated on 24/07/21 20:54 by Anand

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

// thr = ceil(tot/3)
//
// [1 ... p-1] [p ... mid-1] [mid ... n]
bool f(vec& a, vec& b, vec& c, ll thr, pll& p) {
    ll n = a.size()-1;
    ll lb = 2;
    bool f1 = false;
    rep(i,2,n+1) {
        if (a[lb-1] >= thr) {f1 = true; break;}
        else lb++;
    }
    if (!f1) return false;
    ll lc = lb+1;
    bool f2 = false;
    rep(i,lc,n+1) {
        if (b[lc-1] - b[lb-1] >= thr) {f2 = true; break;}
        else lc++;
    }
    if (!f2) return false;
    if (c[n]-c[lc-1] < thr) return false;
    p = {lb, lc};
    return true;
}

void pr(ll la, ll ra, ll lb, ll rb, ll lc, ll rc) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
}

void SOLVE() {
    ll n;
    cin >> n;
    vec a(n+1), b(n+1), c(n+1);
    rep(i,1,n+1) {ll m; cin >> m; a[i] = a[i-1] + m;}
    rep(i,1,n+1) {ll m; cin >> m; b[i] = b[i-1] + m;}
    rep(i,1,n+1) {ll m; cin >> m; c[i] = c[i-1] + m;}
    pll p = {-1ll,-1ll};

    ll thr = ceil(a[n]/3.0);
    // p.first = la p.second = lc
    if (f(a,b,c,thr,p)) pr(1,p.first-1, p.first, p.second -1, p.second , n);
    else if (f(a,c,b,thr,p)) pr(1, p.first - 1, p.second, n, p.first, p.second - 1);
    else if (f(b,a,c, thr,p)) pr(p.first, p.second - 1,1 ,p.first -1 ,p.second, n);
    else if (f(b,c,a,thr,p)) pr(p.second, n, 1, p.first - 1, p.first, p.second - 1);
    else if (f(c,a,b,thr,p)) pr(p.first, p.second - 1, p.second, n, 1, p.first - 1);
    else if (f(c,b,a,thr,p)) pr(p.second, n, p.first, p.second - 1, 1, p.first - 1);
    else cout << "-1\n";

}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

