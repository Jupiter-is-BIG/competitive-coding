// File C generated on 24/01/02 01:32 by Anand

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
    string s; 
    cin >> s;
    int ok = -1;
    map<char, int> m;
    rep(i,0,n) ok = max(ok, ++m[s[i]]);
    cout << max(2*ok - n, n%2) << "\n";
    /*if (ok < (n/2)) {
        if (n&1) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else {
        cout << 2*ok - n << "\n";
    }*/
}

signed main() {
    ANAND;

    ll TT;
    cin >> TT;

    rep(i,1,TT+1)
    {
        //if (i == 408) {int n; cin >> n; string s; cin >> s; cout << s << endl;}
		SOLVE();
    }
    return 0;
}

