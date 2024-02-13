// File generated on 24/02/13 06:48 by Anand

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
    ll l = 0, r = n - 1;
    while (l + 1 < n) {
        if (a[l] == a[l + 1]) l++;
        else break;
    }

    while (r > 0) {
        if (a[r]  == a[r - 1]) r--;
        else break;
    }

    if (a[0] == a[n - 1]) {
        cout << max(r - l - 1,0ll) << "\n";
    } else {
        cout << min(n - 1 - l, r) << "\n";
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

