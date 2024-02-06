// File generated on 24/02/06 06:31 by Anand

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
    string s; 
    cin >> s;

    ll st = -1;
    ll ed = -1;
    rep(i,0,n) {
        if (s[i] == 'B') {if (st == -1) st = i; else ed = i;}
    }

    if (st == -1 && ed == -1) cout << 0;
    else if (ed == -1) cout << 1;
    else {cout << ed - st + 1;}
    cout <<"\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

