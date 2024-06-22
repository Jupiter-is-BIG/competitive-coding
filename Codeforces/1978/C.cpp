// File generated on 24/06/16 02:27 by Anand

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
    ll n, k;
    cin >> n >> k;
    ll m = 2 * (n-((n+1)/2)) * ((n+1)/2);
    if (k&1 || k > m) {NO; return;}
    YES;
    vec ans(n+1);
    ll l = 1, r = n;
    while(l <= r && k > 0) {
        if (2*(r-l) > k) l++;
        else {ans[l] = r; ans[r] = l; k-=(2*(r-l)); l++; r--;}
    }
    rep(i,1,n+1) {if (ans[i] == 0) cout << i << " "; else cout << ans[i] << " ";}
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

