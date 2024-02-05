// File C generated on 24/01/05 11:09 by Anand

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

void SOLVE() {
    ll n,k;
    cin >> n >> k;
    vec a(n);
    rep(i,0,n) cin >> a[i];
    ll s = n-1;
    set<ll> g;
    rep(i,0,k) {
        if (g.count(s) == 1) break;
        else g.insert(s);
        if (a[s] <= n) {
            ll x =  (s - a[s]);
            if (x < 0) x += n;
            s=x%n;
        }
        else {cout << "No\n"; return;}
    }
    cout << "Yes\n";
}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

