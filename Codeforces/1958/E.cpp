// File generated on 24/05/13 21:26 by Anand

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
    int n, k;
    cin >> n >> k;
    //ll x = 1, c = 0;
    //while (x <= n) {c++; x*=2;}
    //if (k > c || k > 7) {cout << -1 << "\n"; return;}
    vector<stack<int>> v;
    int cur = 1, len = n;

    while (k != 1) {
       if (len == 2) {cout << -1 << "\n"; return;}
       stack<int> s;
        rep(i, cur, cur + ceil(len / 2.0)) s.push(i);
        v.push_back(s);
        cur = cur + ceil(len / 2.0);
        len /= 2;
        k--;
    }
    if (len == 2) {cout << -1 << "\n"; return;}
    stack<int> s;
    rep(i, cur, n + 1) s.push(i);
    v.push_back(s);
   rep(i,0,v.size()) {
        while(!v[i].empty()) {cout << v[i].top() << " "; v[i].pop();}
       cout << "\n";
    }
    /*ll pick = 0;
    rep(i,0,n) {  
        if (!v[pick].empty()) {cout << v[pick].top() << " "; v[pick].pop();}
        else i--;
            pick = (pick+1)%(v.size());
    }
    cout << "\n";*/
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

