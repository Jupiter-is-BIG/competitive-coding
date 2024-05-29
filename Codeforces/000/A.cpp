// File generated on 24/05/21 13:30 by Anand

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
    vec a(n);
    rep(i,0,n) cin >> a[i];
    map<pair<ll ,ll>, ll> m1, m2, m3;
    map<pair<ll, pair<ll, ll>>,ll> f;
    rep(i,0,n-2) {
        m1[{a[i+1],a[i+2]}]++;
        m2[{a[i],a[i+2]}]++;
        m3[{a[i],a[i+1]}]++;
        f[{a[i],{a[i+1],a[i+2]}}]++;
    }

    ll ans = 0;

    for(auto& i: f) {
        ll x = i.first.first;
        ll y = i.first.second.first;
        ll z = i.first.second.second;
        ans += i.second * (m1[{y,z}] + m2[{x,z}] + m3[{x,y}] - 3 * i.second);
    }

    cout << ans/2 << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

