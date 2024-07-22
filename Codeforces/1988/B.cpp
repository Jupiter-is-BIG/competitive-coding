// File generated on 24/07/17 20:35 by Anand

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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0, b = 0;
    ll c = 0;
    if (s[0] == '0') b++; else a++;
    rep(i,1,n) {
        if (s[i] == '1') a++;
        if (s[i] == s[c]) continue;
        else {
            c = i;
            if (s[i] == '0') b++;
        }
    }

    if (a>b) YES;
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

