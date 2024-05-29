// File generated on 24/05/28 20:57 by Anand

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
    ll k, q;
    cin >> k >> q;

    vec a(k);
    rep(i,0,k) cin >> a[i];

    while(q--) {
        ll n; cin >> n;
        if (n < a[0]) cout << n << " ";
        else cout << a[0] - 1 << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

