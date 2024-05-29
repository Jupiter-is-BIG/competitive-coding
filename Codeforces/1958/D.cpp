// File generated on 24/05/13 20:53 by Anand

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
    ll x = 0, c = 0, j = -1;
    vec a(n);
    rep(i,0,n) cin >> a[i];
    ll ans = 0;
    rep(i,0,n) {
        ll m = a[i];
        if (m == 0) {
            if (c&1) {
                if (c == 0) continue;
                ll oo = 0;
                for (int k = j + 1; k < i; k += 2) {
                    oo = max(oo, a[k]);
                }
                ans += 2*x - oo;
            }
            else ans+=2*x;
            x = 0; c = 0; j = i;
            continue;
        }

        c++;
        x+=m;}

    ll oo = 0;
    for(int k = j + 1; k < n; k+=2) {oo = max(oo, a[k]);}
    if (c&1) {ans+=2*x-oo;}
    else ans+=2*x;
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
