// File generated on 24/06/16 03:15 by Anand

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
    ll n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    vecp l(n), u(n);
    rep(i,0,n) {
        l[i] = {i,i};
        u[i] = {i,i};
    }
    rep(i,1,n-1) {
        if (b[i] == '0' && a[i-1] == '1' && a[i+1] == '1') {b[i] = '1'; l[i] = {i-1, i+1};}
    }
    rep(i,1,n-1) {
        if (a[i] == '0' && b[i-1] == '1' && b[i+1] == '1') {a[i] = '1'; u[i] = {l[i-1].first, l[i+1].second};}
    }
    vec s(n), e(n);
    vec x(n), y(n);
    rep(i,0,n) {if (a[i] == '1') {x[u[i].first]++; y[u[i].second]++;}}
    rep(i,1,n) {x[i] += x[i-1]; y[i] += y[i-1];}
    
    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l + 1 > 5) 
        if (l == 0) cout << s[r] << "\n";
        else cout << s[r] - s[l-1] << "\n";
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

