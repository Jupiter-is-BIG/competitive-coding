// File generated on 24/04/30 20:34 by Anand

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

bool good(vec& a, ll k, ll mid, ll n) {
    ll x = 0;
    rep(i,0,n) {
        if (a[i] >= mid) return x <= k;
        x+=(mid-a[i]);
    }
    return x <= k;
}

void SOLVE() {
    ll n, k;
    cin >> n >> k;
    vec a(n);
    rep(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());

    ll l = 1, r = 1e13;
    while (r > l + 1) {
        ll mid = (l + r) / 2;
        if (good(a, k, mid, n)) l = mid;
        else r = mid;
    }

    ll minv = l, maxv = a[n-1];
    rep(i,0,n) if (a[i] < l) {k-=(l-a[i]); a[i] = 0;} else a[i] -= l;
    ll ans = l*n-(n-1);
    rep(i,0,n) {
        if (a[i] == 0) {if (k>=1) {k--; ans++;}}
        else ans++;
    }
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

