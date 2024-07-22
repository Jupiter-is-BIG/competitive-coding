// File generated on 24/07/12 23:28 by Anand

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
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<pair<ll, ll>> dp(n+1);
    dp[0] = {1ll, 0ll};
    ll x = 0, y = 0;

    // dp[i].first = reachable? dp[i].second = swam so far

    rep(i,1,n+1) {
        if (s[i-1] == 'C') {dp[i] = {0ll, 0ll}; continue;}
        if (i-x<=m) {
            dp[i] = {1ll, y};
            if (s[i-1] == 'L') x = i;
        } else {
            if (dp[i-1].first == 0ll || dp[i-1].second == k) dp[i] = {0ll, 0ll};
            else {y++; dp[i] = {1ll, y}; if (s[i-1] == 'L') x = i;}
        }
    }
    if (n+1-x<=m || (dp[n].first == 1ll && y < k)) YES;
    else NO;
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

