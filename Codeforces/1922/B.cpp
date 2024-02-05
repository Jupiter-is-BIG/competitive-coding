// File generated on 24/01/18 14:45 by Anand

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
    ll n; cin >> n;
    vec a(n);
    rep(i,0,n) {cin >> a[i];}
    sort(a.begin(), a.end());
    ll ans = 0;
    ll lastAdd = 0;
    rep(i,0,n) {
        if (i <= 1) continue;
        if (a[i-1] == a[i]) {
            lastAdd += i - 1; ans += lastAdd;
        } else {lastAdd = 0;}
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

