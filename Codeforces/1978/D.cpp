// File generated on 24/06/16 02:58 by Anand

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
    ll n, c;
    cin >> n >> c;
    vec a(n), l(n), r(n), s(n);
    l[0] = -1;
    r[n-1] = -1;
    rep(i,0,n) cin >> a[i];
    a[0] += c;
    s[0] = a[0];
    rep(i,1,n) l[i] = max(a[i-1], l[i-1]);
    for(ll i = n-2; i >=0; --i) r[i] = max(r[i+1], a[i+1]);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    rep(i,0,n) {
        if (a[i]>=r[i]) {
            if (a[i]>l[i]) cout << "0 ";
            else cout << i << " ";
        } else {
            if (s[i] >= r[i]) cout << i << " ";
            else cout << i + 1 << " ";
        }
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

