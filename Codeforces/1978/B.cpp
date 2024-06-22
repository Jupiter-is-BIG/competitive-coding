// File generated on 24/06/16 02:12 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    ll x = min(n,b);
    if (-x+b+0.5-a >= 0) cout << (x*(b+1) + a*(n-x) - (x*(x+1))/2) << "\n";
    else {
        if (b+0.5-a <= 0) cout << (a*n) << "\n";
        else {
            ll t = b+1-a;
            if (t > x) t= b-a;
            ll t2 = b-a;
            cout << max(t*(b+1) + a*(n-t) - (t*(t+1))/2, t2*(b+1) + a*(n-t2) - (t2*(t2+1))/2) << "\n";
        }
    }
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

