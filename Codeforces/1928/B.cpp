// File generated on 24/02/11 11:50 by Anand

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
    ll n; cin >> n;
    set<ll> s;
    vec a;
    rep(i,0,n) {ll m; cin >> m; if (s.count(m)) continue; a.pb(m); s.insert(m);}
    sort(a.begin(), a.end());

    ll k = a.size();
    ll l = 0, r = 0, ans = 1;
    while (r < k) {
       // cout << l << " " << r << "\n";
        if (a[r] - a[l] > n - 1) {ans = max(ans, r - l); if (r - l > 1) l = r - 1; else l = r; ans = 1; continue;}
        r++;
    }
    ans = max(ans, r - l);
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

