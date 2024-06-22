// File generated on 24/06/11 06:21 by Anand

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
    ll n;
    cin >> n;
    double k = 0;
    vec a(n);
    rep(i,0,n) {cin >> a[i]; k += (1.0/a[i]);}
    if (k >= 0.9999999) {cout << -1 << "\n"; return;}
    ll s = 10000000*n;
    ll t = 0;
    rep(i,0,n - 1) {cout << (s/a[i]) + 1 << " "; t+=((s/a[i]) + 1);}
    cout << s - t << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

