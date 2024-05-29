// File generated on 24/05/28 21:10 by Anand

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
    vec f(n+1);
    rep(i,0,n) {ll m; cin >> m; f[m]++;}
    ll ans = 0;
    rep(i,1,n+1) {if (f[i] == 2) ans++;}
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

