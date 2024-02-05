// File generated on 24/01/08 11:55 by i24

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
    vec a(n), next(n), prev(n), visited(n);
    priority_queue<pll> pq;
    bool isZ = false;
    rep(i,0,n) {
        ll m;
        cin >> m;
        if (m == 0) isZ = true;
        a[i] = m;
        next[i] = i + 1;
        prev[i] = i - 1;
    }

    if(!isZ) {NO; return;}

    auto gg = [&](ll i) -> bool {
        if (prev[i] < 0 && next[i] > n - 1) return 0;
        else if (prev[i] < 0) {
            if (a[i] == a[next[i]] + 1) {pq.push({a[i], i}); visited[i] = 1; return 1;}
        } if (next[i] > n - 1) {
            if (a[i] == a[prev[i]] + 1) {pq.push({a[i], i}); visited[i] = 1; return 1;}
        } else {
            if (a[i] == a[prev[i]] + 1 || a[i] == a[next[i]] + 1) {pq.push({a[i], i}); visited[i] = 1; return 1;}
        }
        return 0;
    };

    rep(i,0,n) gg(i);   

    while(!pq.empty()) {
       // DEBUG(pq.size());
        ll i = pq.top().second;
        if (prev[i] >= 0) next[prev[i]] = next[i];
        if (next[i] < n) prev[next[i]] = prev[i];
        pq.pop();

        if (visited[next[i]] != 1) gg(next[i]);
        if (visited[prev[i]] != 1) gg(prev[i]);
    }

    ll c = 0;
    rep(i,0,n) {if (visited[i] == 0) c++;}
    if (c > 1) NO;
    else YES;


}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

