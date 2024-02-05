// File generated on 24/01/30 07:05 by Anand

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
    ll a, b, r;
    cin >> a >> b >> r;
    if (r == 0) {cout << abs(a - b) << "\n"; return;}
    if (a == b) {cout << 0 << "\n"; return;}
    bitset<62> x(a);
    bitset<62> y(b);
    bitset<62> z(r);
    ll t = 1,c = 0;
    while (t <= r) {c++; t*=2;}
    ll better = 1; // 0: a, 1: draw, 2: b
    ll x1 = a>>c;
    ll y1 = b>>c;
    if (x1 == y1);
    else if (x1 > y1) better = 0;
    else better = 2;
    
    if (better == 1) {
        ll bb;
        bool flag = false;
        for(ll i = c-1; i >= 0; i--) {
            if (flag) {
            
                    if (bb == 0 && x[i] == 1 && y[i] == 0) {x.flip(i); y.flip(i);}
                    if (bb == 1 && x[i] == 0 && y[i] == 1) {x.flip(i); y.flip(i);}
            
            }
            else {
                if (x[i] == 1 && y[i] == 0) {flag = true; bb = 0;}
                else if (x[i] == 0 && y[i] == 1) {bb = 1; flag = true;}
            }
    }
    } else if (better == 0) {
        bool gg = false;
       // if (x[c-1] == y[c-1] || (x[c-1] == 0 && y[c-1] == 1)) gg = true;
        for(ll i = c-1; i >= 0; i--) {
            if ((x[i] == y[i] || (x[i] == 0 && y[i] == 1)) && z[i] == 1) {gg = true; continue;}
            if (x[i] == 1 && y[i] == 0) {
                if (gg)
                {x.flip(i); y.flip(i);}
                else {
                    if (z[i] == 1) {x.flip(i); y.flip(i);}
                }
            }
        }
    } else {
         bool gg = false;
        //if (x[c-1] == y[c-1] || (x[c-1] == 1 && y[c-1] == 0)) gg = true;

        for(ll i = c-1; i >= 0; i--) {
            if((x[i] == y[i] || (x[i]== 1 && y[i] == 0)) && z[i] == 1) {gg = true; continue;}
            if (x[i] == 0 && y[i] == 1) {
                if (gg)
                { x.flip(i); y.flip(i);}
                else {
                    if (z[i] == 1) {x.flip(i); y.flip(i);}
                }
            }

           // if (x[i] == 0 && y[i] == 1) {x.flip(i); y.flip(i);}
        }

    }
//    DEBUG(better);
//
   ll fina = 0, finb = 0;
   for (int i = 61; i >= 0; --i) {fina <<=1; finb<<=1; fina |= (x[i]); finb |= (y[i]);}
   // ll fina = (long long) (x.to_ulong());
    //ll finb = (long long) (y.to_ulong());
    cout << abs(fina - finb) << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

