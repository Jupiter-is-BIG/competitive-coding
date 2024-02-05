// File generated on 24/01/08 16:24 by i24

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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a = 0, b = 0;
    rep(i,0,n) {
        if (s[i] == 'A') a++;
        else b++;
    }

    if (b == k) {cout << 0 << endl; return;}

    if (b > k) {
        rep(i,0,n) {
            if (s[i] == 'B') b--;
            if (b == k) {cout << 1 << endl << 1 + i << " " << "A" << endl; return;}
        }
    } else {
        rep(i,0,n) {
                      if (s[i] == 'A') b++;
 if (b == k) {cout << 1 << endl << 1 + i << " " << "B" << endl; return;}

        }
    }
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

