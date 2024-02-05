// File B generated on 24/01/02 01:12 by Anand

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
    vec l, u;
    string s;
    cin >> s;
    int n = s.length();
    rep(i,0,n) {
        if (s[i] == 'b') {if (l.size() != 0) l.pop_back(); continue;}
        if (s[i] == 'B') {if (u.size() != 0) u.pop_back(); continue;}
        if (islower(s[i])) l.push_back(i);
        else u.push_back(i);
    }
    string ans = "";
    for (int a = 0, b = 0; a < l.size() || b < u.size();){
        if (a >= l.size()) {ans += s[u[b]]; b++; continue;}
        if (b >= u.size()) {ans += s[l[a]]; a++; continue;}
        if (l[a] < u[b]) {ans += s[l[a]]; a++;}
        else {ans += s[u[b]]; b++;}
    }

    cout << ans << "\n";

}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

