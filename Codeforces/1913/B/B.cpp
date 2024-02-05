// File C generated on 24/01/01 12:41 by Anand

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
    int n; cin >> n;
    vec f(30);
    while(n--) {
        ll m; cin >> m;
        if (m == 1) {cin >> m; f[m]++;}
        else {
            cin >> m;
            if (m==0) {YES; continue;}
            vec g(30);
            rep(i,0,30) g[i] = f[i];

            int p = 0;
            bool flag = false;
            while(m!=0 && !flag) {
                //DEBUG(m);
                while(m%2 == 0) {p++; m/=2;}
                int load = 1;
                int lvl = p;
                while (load != 0) {
                    if (lvl < 0) {NO; flag = true; break;}
                    if (g[lvl] < load) {load -= g[lvl]; g[lvl] = 0; load *= 2; lvl--;}
                    else {g[lvl] -= load; load = 0;}
                }
                m/=2;p++;
           }
            if (!flag) YES;
        }
    }
    
}

signed main() {
    ANAND;

    //ll _;
    //cin >> _;

    //while(_--) 
		SOLVE();

    return 0;
}

