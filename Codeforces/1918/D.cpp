// File generated on 24/01/30 08:09 by Anand

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

ll n;
vec a;

bool good(ll x) {
    vec dp(n+1); // dp[i] = block at a_i min cost
    ll p = 0;
    ll segsum = 0;
    set<pll> s;
    s.insert({0,0});
    for (ll i = 1; i < n + 1; ++i) {
        while (segsum > x + a[p]) {
            segsum -= a[p];
            s.erase({dp[p], p});
            p++;
            if (s.empty()) return false;
        }
        dp[i] = a[i] + s.begin()->first;
        s.insert({dp[i], i});
        segsum += a[i];
    }
   // PRINT(dp, n+1);
    ll opt = x+1;
    ll prog = 0;
    ll ind = n;
    while(prog <= x && ind >= 0) {
        opt = min(dp[ind], opt);
  //      cout << " ok " << dp[ind] << " " << opt << " " << prog << "\n";
        prog+=a[ind];
        ind--;
    }
  //  DEBUG(opt);
    return opt <= x;
}

void SOLVE() {
    cin >> n;
    a.resize(n + 1);
    rep(i,1,n+1) cin >> a[i];
    
    ll l = 0; // bad
    ll r = 1;
    while(!good(r)) r*=2;
//    DEBUG(r);
    while (r > l + 1) {
//        cout <<  l << " " << r << "\n";
        ll m = (l + r) / 2;
        if (good(m)) r = m;
        else l = m;
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

