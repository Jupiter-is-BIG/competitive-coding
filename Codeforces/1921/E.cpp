// File generated on 24/01/15 07:40 by Anand

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
    ll h, w, xa, ya, xb, yb;
    cin >> h >> w>> ya >> xa >> yb >> xb;
    if (ya >= yb) {cout << "Draw\n"; return;}
    
    ll mid = ceil((ya+yb)/2.0);
    ll sa = mid - ya;
    ll sb = yb - mid;
    ll k = yb - ya;

    ll bL = max(1ll, xb - sb);
    ll bR = min(w, xb + sb);
    ll aL = max(1ll, xa - sa);
    ll aR = min(w, xa + sa);
    //cout << bL << " " << bR << " " << aL << " " << aR << endl;
    if (k&1) {
        // Alice
        if (aL <= bL && aR >= bR) {cout << "Alice" << "\n";}
        else cout << "Draw" << "\n";
    } else {
        // Bob
        if (bL <= aL && bR >= aR) {cout << "Bob" << "\n";}
        else cout << "Draw" << "\n";
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

