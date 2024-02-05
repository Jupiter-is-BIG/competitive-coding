// File generated on 24/01/15 06:47 by Anand

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
    ll n, f, x, b;
    cin >> n >> f >> x >> b;
    vec a(n+1);
    rep(i,1,n+1) cin >> a[i];
    rep(i,0,n) {
        ll t = (a[i+1] - a[i])*x;
        if (t > b) f-=b;
        else f-=t;
        if (f<=0) {NO; return;}
    }
    YES;
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

