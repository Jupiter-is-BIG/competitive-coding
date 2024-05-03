// File generated on 24/04/30 22:12 by Anand

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
    ll n, m;
    cin >> n >> m;
    ll x = 1e6;
    ll ans = 0;
    ll temp = 0,fac = 1;
    while(true){

    rep(d,2,2*x+1) {
        if (d*fac > (m/d) + (n/d)) break;
        temp += m/d + n / d - fac*d + 1;
    }
    if (temp == 0) break;
    ans+=temp;
    fac++;
    temp = 0;

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

