// File generated on 24/07/19 21:47 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define sz size

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> vecc;
typedef vector<pll> vecp;

void dfs(ll node, ll parent, vec& a, vecc& g, vecc& r) {
        rep(i,1,20) r[node][i] = i * a[node];
        for(ll& x : g[node]) {
            if (x == parent) continue;
            dfs(x, node, a, g, r);
            rep(i,1,20) {
                ll extra = -1;
                rep(j,1,20) {
                    if (i == j) continue;
                    if (extra == -1) extra = r[x][j];
                    else extra = min(extra, r[x][j]);
                }
                r[node][i] += extra;
            }
        }
}

void SOLVE() {
    ll n;
    cin >> n;
    vec a(n+1);
    rep(i,1,n+1) cin >> a[i];
    vecc g(n+1);
    rep(i,0,n-1) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vecc r(n+1, vector<ll>(20));
    dfs(1, 0, a, g, r);
    ll ans = r[1][1];
    rep(i,1,20) ans = min(ans, r[1][i]);
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

