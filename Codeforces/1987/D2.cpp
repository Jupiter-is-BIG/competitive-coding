// File generated on 24/07/03 08:11 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
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
    map<ll, ll> m, m2;
    rep(i,0,n) {ll x; cin >> x; m[x]++;}
    ll ans = m.size();
    set<pair<ll,ll>> s;
    ll x = 0, y = 0;
    for(auto& i: m) {m2[x] = i.second; s.insert({x - i.second, x}); x++;}
    while(!s.empty()) {
        pair<ll, ll> val = *(s.begin());
        s.erase(s.begin());
        if (val.first < 0) continue;
        ++y;
        vector<pair<ll, ll>> z, z2;
        for(auto& i: s) {
            ll o = m2[val.second];
            if (i.second > val.second) o++;
            z2.push_back(i);
            z.push_back({i.first-o, i.second});
        }
        for(auto& i: z2) s.erase(i);
        for(auto& i: z) s.insert(i);
    }
    cout << ans - y << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

