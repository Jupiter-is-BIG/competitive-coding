// File generated on 24/06/01 23:01 by Anand

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
    ll n, m; 
    cin >> n >> m;
    if (m == 0) {cout << n << "\n"; return;}
    bitset<32> bm(n+m), bmm(max(0ll, n-m));
    ll ans = 0;
    for(int i = 31; i >= 0; --i) {
        if (bmm[i] != bm[i]) {ans+=((1<<(i+1)) - 1); cout << ans << "\n"; return;}
        ans += (1<<i) * max(bmm[i], bm[i]);
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

