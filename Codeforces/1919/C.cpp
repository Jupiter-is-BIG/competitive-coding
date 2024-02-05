// File generated on 24/01/06 06:57 by i24

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
    ll ans = 0;
    ll a = 1e6, b = 1e6;
    rep(i,0,n) {
        ll m;
        cin >> m;
        if (m == a || m == b) continue;
        if (m < a && m < b) {
            if (a <= b) {a = m;}
            else b = m;
        } else if (m > a && m < b) {
            b = m;
        } else if (m < a && m > b) {
            a = m;
        } else {
            if (a<=b) a = m;
            else b = m;
            ans++;
        }
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

