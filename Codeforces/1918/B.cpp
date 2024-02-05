// File generated on 24/01/30 06:45 by Anand

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
    ll n; cin >> n;
    vecp a(n);
    
    rep(i,0,n) {cin >> a[i].first;}
    rep(i,0,n) {cin >> a[i].second;}
    sort(a.begin(), a.end());
    rep(i,0,n) {cout << a[i].first << " ";}
    cout << "\n";
    rep(i,0,n) {cout << a[i].second << " ";}
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

