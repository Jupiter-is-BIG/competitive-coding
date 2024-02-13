// File generated on 24/02/13 07:55 by Anand

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
    ll n, k;
    cin >> n >> k;
    vec a(n);
    map<ll, ll> m;
    ll x; cin >> x;
    bool flag = false;
    ll c = 1;
    rep(i,1,n) {
        ll y;
        cin >> y;
        m[y] = c;
        c+=2;
    }
    k--;
    if (k == 0) {YES; return;}
    ll xx; cin >> xx;
    ll pre = 0;
    bool amb = false;
    rep(i,1,n) {
        ll y;
        cin >> y;
        if (flag) continue;
        if (y == x) {
            if (i == 1 && m[xx] == 1) {m[x] = 1; amb = true;}
            else if (i == 1) {m[x] = 0;}
            else if (pre+2 == m[xx]) {m[x] = pre + 2; amb = true;}
            else {m[x] = pre + 1;}
            pre = m[x];
        } else {
            if (m[y] < pre) {NO; flag = true;}
            pre = m[y];
        }
    }
    k--;
    if (k==0) {if(!flag) YES; return;}
    if (amb) {
        k--;
        ll xy;
         cin >> xy;
         ll pre = 0;
         rep(i,1,n) {
            ll y;
            cin >> y;
            if (flag) continue;
            if (amb && y == xx) {m[xx]--; amb = false;}
            if (amb && y == x) {m[x]--; amb = false;}
            if (m[y] < pre) {NO; flag = true;}
            pre = m[y];
        }
    }
    while(k--) {
        ll q;
        cin >> q;
        ll pre = 0;
        rep(i,1,n) {
            ll y; cin >> y;
            if (flag) continue;
            if (m[y] < pre) {NO; flag = true;}
            pre = m[y];
        }
    }
   if (!flag) YES;
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

