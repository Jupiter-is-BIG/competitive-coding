// File generated on 24/06/11 09:20 by Anand

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

bool good(vec& a, vec& c, ll t, ll h) {
    ll dmg = 0;
    rep(i,0,a.size()) dmg += a[i] * (1 + ((t-1)/c[i]));
    return dmg >= h;
}

void SOLVE() {
    ll h, n;
    cin >> h >> n;
    vec a(n), c(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> c[i];
    ll l = 0, r = 1;
    while(!good(a, c, r, h)) r*=2;
    while(r > l + 1) {
        ll mid = (l + r) / 2;
        if (good(a, c, mid, h)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

