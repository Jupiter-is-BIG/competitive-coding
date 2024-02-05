// File generated on 24/01/13 06:43 by Anand

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
    ll n, k ,x;
    cin >> n >> k>>x;
    vec a(n+1);
    ll s = 0;
    rep(i,1,n+1) {ll m; cin >> m; s+=m; a[i] = m;}
    sort(a.begin(), a.end());
    rep(i,1,n+1) {a[i] = a[i-1] + a[i];}
    ll t = 1e16;
   // PRINT(a,n+1);
    rep(i,0,k+1) {
        t = min(a[n] - a[max(n - i, 0ll)] + 2 * (a[max(n - i, 0ll)] - a[max(n-i-x, 0ll)]), t);
       // DEBUG(a[n] - a[max(n - i, 0ll)] + 2 * (a[max(n - i, 0ll) - a[max(n-i-x, 0ll)]]));
    }
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

