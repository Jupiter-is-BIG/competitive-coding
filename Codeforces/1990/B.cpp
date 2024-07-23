// File generated on 24/07/22 19:18 by Anand

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

void SOLVE() {
    ll n, x, y;
    cin >> n >> x >> y;
    rep(i,0,y-1) cout << (((i-y)&1) ? 1 : -1) << " ";
    rep(i,y-1,x) cout << 1 << " ";
    rep(i,x,n) cout << (((i-x)&1) ? 1 : -1) << " ";
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

