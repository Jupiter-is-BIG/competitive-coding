// File B generated on 24/01/06 02:56 by Anand

#include <bits/stdc++.h>
using namespace std;

#define ANAND ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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

ll floor(ll x, ll m) {
    ll r = (x % m + m) % m;
    return (x - r) / m;
}

void SOLVE() {
    ll a, m, l , r;
    cin >> a>>m>>l>>r;
    ll ans = floor(r-a,m) - floor(l-1-a,m);
    cout << ans << endl;
}

signed main() {
    ANAND;

   // ll _;
   // cin >> _;

   // while(_--) 
		SOLVE();

    return 0;
}

