// File B generated on 24/01/05 09:30 by Anand

#include <bits/stdc++.h>
using namespace std;

#define ANAND ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
    if (n == 1) {ll m; cin >> m; cout << -1 << endl; return;}
    if (n == 2) {ll a, b; cin >> a >> b; cout << "-1\n"; return;}
    map<int, int> m;
    vec G(n);
    ll a = -1, fa = 0;
    ll b, fb = 0;
    rep(i,0,n) {
        ll k; cin >> k;
        G[i] = k;
        m[k]++;
        if (m[k] >= fa) {
            if (k == G[a]) fa++;
            else {b = a; fb = fa; fa = m[k]; a = i;}
        }
        else if (m[k] >= fb) {
            if (k == G[b]) fb++;
            else {b = i; fb = m[k];}
        }
    }
    if (m.size() == 1 || m.size() == n) {cout << -1 << endl; return;}
    if (m[G[b]] == 1) {cout <<  "-1\n"; return;}
    bool fla = false, flb = false;

    rep(i,0,n) {
        if (G[i] == G[a] && fla) cout << "2 ";
        else if (G[i] == G[a]) {cout << "1 "; fla = true;}
        else if (G[i] == G[b] && flb) cout << "2 ";
        else if (G[i] == G[b]) {cout << "3 "; flb = true;}
        else cout << "2 ";
    }
    cout << "\n";

}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

