// File generated on 24/01/13 06:37 by Anand

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
    ll l = 0, h = 1e10;
    vec a;
    rep(i,0,n) {
        ll x, y;
        cin>> x>>y;
        if (x == 1) l = max(l , y);
        else if (x == 2) h = min(h, y);
        else a.pb(y);
    }
    ll c = 0;
    for(ll i: a) {if (l <= i && i <= h) c++;}
    cout << max(h - l + 1 - c, 0ll) << endl;
    
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

