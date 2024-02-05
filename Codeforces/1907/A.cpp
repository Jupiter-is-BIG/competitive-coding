// File A generated on 24/01/02 01:07 by Anand

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
    string s;
    cin >> s;
    char a = s[0];
    int b = s[1] - '0';
    int c = s[0] - 'a';
    char x = 'a';
    rep(i,1,9) {
        if (i == b) continue;
        cout << a << i << "\n";
    }
    rep(i,0,8) {
        if (i == c) continue;
        char t = x+i;
        cout << t << b << "\n";
    }
}

signed main() {
    ANAND;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

