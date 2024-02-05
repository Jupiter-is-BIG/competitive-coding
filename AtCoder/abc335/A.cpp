// File A generated on 24/01/06 03:59 by Anand

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
ll score = 0;
void dfs(ll root, vecc& g, vec& a) {
    //if (visited[root]) {return 0;}
    //if (a[root] != a[pre]) score++;
    //if (root == n) return score;
    //visited[root] = true;
    score++;
    for(ll i: g[root]) {
        dfs(i, g, a);
    }
}

void SOLVE() {
    ll n;
    cin >>n;
    vec a(n+1);
    rep(i,1,n+1) cin >> a[i];
    vecc g(n+1);
    rep(i,1,n+1) {
        ll t = i;
        while(t <= n) {
            t+=a[i];
            g[i].pb(t);
        }
        
    }
   /* while(m--) {
        ll u, v;
        cin >> u>>v;
        if (a[u] == a[v]) {
            g[u].pb(v);
            g[v].pb(u);
        } else if (a[u] > a[v]) {
            g[v].pb(u);
        } else {
            g[u].pb(v);
        }
    }*/
    //if (a[1] > a[n]) {cout << "0\n"; return;}
   
    dfs(1, g, a);
    cout << score << "\n";
}

signed main() {
    ANAND;

    //ll _;
    //cin >> _;

   // while(_--) 
		SOLVE();

    return 0;
}

