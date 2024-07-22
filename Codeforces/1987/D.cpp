// File generated on 24/07/01 00:27 by Anand

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
    vector<pair<ll,ll>> g(5001, {5002, -1});
    set<ll> s;
    rep(i,0,n) {ll m; cin >> m; s.insert(m); if (g[m].second == -1) g[m] = {1, m}; else g[m].first++;}
    sort(g.begin(), g.end());
    vec t(n+1, -1);
    ll x = 0;
    for(ll i: s){
        t[i] = x;
        x++;
    }
    
    rep(i,0,5001) {
       if (g[i].second == -1) break;
       if (t[g[i].second] >= g[i].first) {
            rep(j,1,g[i].second) t[j] -= g[i].first;
            rep(j,g[i].second+1,n+1) t[j] -= (g[i].first + 1);
            g[i].first = 0;
        }
    }
    ll ans = 0;
    rep(i,0,5001)
        if (g[i].second != -1 && g[i].first > 0) ans++;
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

