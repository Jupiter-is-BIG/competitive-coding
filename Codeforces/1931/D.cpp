// File generated on 24/02/13 06:59 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
#define PRINT(x,n) rep(i,0,n) cout << (x[i]) << " "; cout << "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> vecc;
typedef vector<pll> vecp;

void SOLVE() {
    ll n, x, y;
    cin >> n >> x >> y;
    map<pll, ll> m;
    rep(i,0,n) {ll t; cin >> t; pll ok = {t%y, t%x}; m[ok]++;}
    ll ans = 0;
    for (auto& i: m) {
        if (i.first.second == 0 || x - i.first.second == i.first.second) {ans += (i.second*(i.second - 1)) / 2; continue;}
        pll ok = {i.first.first, x - i.first.second};
        ans += m[ok] * i.second;
        m[ok] = 0;
    }
    cout << ans << "\n";

}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

