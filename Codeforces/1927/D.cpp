// File generated on 24/02/06 07:12 by Anand

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
    vecp d;
    ll t; cin >> t;
    ll p1 = 0, p2 = 0;
    rep(i,0,n-1) {
        ll x;
        cin >> x;
        if (x == t) p2++;
        else {d.pb({p1, p2}); p2++; p1 = p2; t = x;}
    }
    d.pb({p1, p2});
    ll m = d.size();
    //rep(i,0,m) {cout << "ok" << d[i].first << " " << d[i].second << "\n";}

    
    ll q; cin >> q;
    while(q--) {
        //DEBUG("ok");
        ll a , b;
        cin >> a >> b;
        a--; b--;

        ll l = -1; // a lies after l
        ll r = m; // a lies in or before m;
                  //

        while(r > l + 1) {
           // DEBUG(r);
            ll mo = (l + r) / 2;
            if (a <= d[mo].second) r = mo;
            else l = mo;
        }

        ll ind1 = r;
        l = -1;
        r = m;

        while(r > l + 1) {
            ll mo = (l + r) / 2;
            if (b <= d[mo].second) r = mo;
            else l = mo;
        }

        if (ind1 == r) {cout << -1 << " " << -1 << "\n";}
        else {cout << d[ind1].second + 1  << " " << d[ind1+1].first + 1 << "\n";}
 
    
    }
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

