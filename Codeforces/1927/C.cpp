// File generated on 24/02/06 06:58 by Anand

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
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll, ll> a;
    map<ll , ll> b;
    ll A = 0, B = 0 ,C = 0;
    rep(i,0,n) {ll x; cin >> x; a[x]++;}
    rep(i,0,m) {ll x; cin >> x; b[x]++;}
    vec t(k+1);
    rep(i,1,k+1) {
        if (a[i] > 0 && b[i] > 0) C++;
        else if (a[i] > 0) A++;
        else if (b[i] > 0) B++;
        else {NO; return;}
    }
    ll ok = k/2;
    if (A+B+C==k && ok>=A && B+C>=ok && ok-A <= C) YES;
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

