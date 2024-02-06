// File generated on 24/02/06 08:10 by Anand

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

ll n, m;

pair<ll, vec> dfs(ll x, vec &visited, ll root, vector<vector<pair<ll,ll>>> &g) {
    //if (visited[root]) return false;
    visited[root] = 1;
    vec route;
    ll k = g[root].size();
    ll ans = x;
    rep(i,0,k) {
       // if (g[root][i].second > x) continue;
        if (visited[g[root][i].first] == 1) {
            ans = min(ans, g[root][i].second);
            if (g[root][i].second < ans) {
                ans = g[root][i].second;
                vec temp;
                route = temp;
            } 
            continue;
        }
        pair<ll, vec> outp = dfs(x, visited, g[root][i].first, g);
        if (outp.first < ans) {
            route = outp.second;
            ans = outp.first;
        }
    }
    visited[root] = 0;
    route.pb(root);
    return {ans, route};
}

pair<ll , vec> good(vector<vector<pair<ll,ll>>> &g) {
    ll x = 1e7;
    ll ans = x;
    vec R;
    vec visited(n+1);
    rep(i,1,n+1) {
        if (visited[i] == 1) continue;
        pair<ll, vec> outp = dfs(x, visited, i, g);
        if (ans > outp.first){ans = outp.first; R = outp.second;}
    }
    return {ans, R};
}

void SOLVE() {
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n+1);
    
    rep(i,0,m) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    
    //ll l = 0; // bad
    //ll r = 1;
    //while(!good(r)) r*=2;

    //while(r > l + 1) {
      //  ll mo = (l + r) / 2;
        //if (good(mo)) r = mo;
        //else l = mo;
    //}
    pair<ll, vec> ans = good(g);

    cout << ans.first << " " << ans.second.size() << "\n";
    rep(i,0,ans.second.size()) {
        cout << ans.second[i] << " ";
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

