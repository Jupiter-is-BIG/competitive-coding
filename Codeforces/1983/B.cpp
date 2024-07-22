// File generated on 24/07/21 20:15 by Anand

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

void SOLVE() {
    ll n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<string> h(n);
    rep(i,0,n) cin >> g[i];
    rep(i,0,n) cin >> h[i];
    rep(i,0,n) {
        ll r1 = 0, r2 = 0;
        rep(j, 0, m) {
            r1 += g[i][j];
            r2 += h[i][j];
        }
        if (abs(r1-r2)%3 != 0) {NO; return;}
    }
    rep(j,0,m) {
        ll c1 = 0, c2 = 0;
        rep(i,0,n) {
            c1 += g[i][j];
            c2 += h[i][j];
        }
        if (abs(c1-c2)%3 != 0) {NO; return;}
    }
    YES;
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

