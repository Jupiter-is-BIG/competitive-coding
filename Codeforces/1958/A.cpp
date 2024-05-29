// File generated on 24/05/13 20:06 by Anand

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
    if (n > 7 || n == 3 || n == 5 || n == 6) cout << 0 << "\n";
    else {
        if (n == 1 || n == 4 || n == 7) cout << 1 << "\n";
        else cout << 2 << "\n";
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

