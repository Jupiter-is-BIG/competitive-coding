// File generated on 24/07/17 20:58 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
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
    bitset<62> b(n);
    vec a;
    rep(i,0,62) if (b[i]) a.pb(i);
    if (a.size() == 1) {
        cout << 1 << "\n";
        cout << n << "\n";
        return;
    }
    cout << a.size() + 1 << "\n";
    vec z;
    z.pb(n);
    rep(i,0,a.size()) z.pb(n ^ (1ll<<a[i]));
    for(ll i = a.size(); i>=0; --i) cout << z[i] << " ";
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

