// File generated on 24/07/19 23:30 by Anand

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
    string a, b;
    cin >> a >> b;
    ll n = a.size();
    ll m = b.size();
    ll ans = 0;
    rep(i,0,m) {
        ll c = 0;
        ll cur = i;
        rep(j,0,n) {
            if (cur== m) break;
            if (a[j] == b[cur]) {c++; cur++;}
        }
        ans = max(ans, c);
    }
    cout << n + m - ans << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

