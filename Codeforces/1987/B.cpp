// File generated on 24/06/30 22:38 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
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
    vec a(n);
    rep(i,0,n) cin >> a[i];
    ll b = 0;
    ll ans = 0;
    ll p = a[0];
    rep(i,1,n) {
        ll o = max(p-a[i], 0ll);
        ans+=o;
        b = max(b, o);
        p = a[i] + o;
    }
    cout << ans + b << "\n";

}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

