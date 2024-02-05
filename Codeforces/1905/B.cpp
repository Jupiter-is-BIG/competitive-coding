// File B generated on 24/01/01 23:38 by Anand

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
    vec fre(n);
    rep(i,0,n-1) {int a, b; cin >>a >> b; fre[a-1]++; fre[b-1]++;}
    int ans = 0, g = 0;
    rep(i,0,n) {
        if (fre[i] > 3) {
            if (fre[i]&1) {ans+=(fre[i]-3)>>1;g++;}
            else ans+=(fre[i]-2)>>1;
        } else if (fre[i] == 3) g++;
    }
    cout << ans + ceil(g/2.0) + 1 << "\n";
    
}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

