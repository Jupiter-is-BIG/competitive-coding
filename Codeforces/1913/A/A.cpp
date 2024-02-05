// File A generated on 24/01/01 12:03 by Anand

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
    string x;
    cin >> x;
    int n = x.length();
    int ab = stoi(x);
        int beam = 1;
    rep(i,1,n) beam *= 10;
    rep(i,1,n) {
        if (((ab*10)/beam)%10 != 0) {
            int a = ab/beam, b = ab%beam;

            if (ab/beam < ab%beam) cout << a << " " << b << endl;
            else cout << -1 << endl;
            return;
        } 
        else beam /=10;
    }
    cout << -1 <<  endl;
}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

