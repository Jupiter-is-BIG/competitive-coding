// File generated on 24/07/19 23:40 by Anand

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, m, n)  for (long long i = m; i < n; i++)
#define DEBUG(x) cout << "debug: " << x << "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define sz size

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> vecc;
typedef vector<pll> vecp;

void SOLVE() {
    ll n;
    cin >> n;
    ll a = 0, b = 0;
    ll p = 0, q = 0;
    vec A(n), B(n);
    rep(i,0,n) cin >> A[i];
    rep(i,0,n) cin >> B[i];
    rep(i,0,n) {
        ll x = A[i];
        ll y = B[i];
        if (x == 0 && y == 1) b++;
        else if (x == 1 && y == 0) a++;
        else if (x == 1 && y == -1) a++;
        else if (x == -1 && y == 1) b++;
        else if (x == 1 && y == 1) p++;
        else if (x == -1 && y == -1) q++;
    }

    
    if (a - b >= q) a-=q;
    else if (b - a >= q) b-=q;
    else if (a >= b) {q-=(a-b); a = b; a-=(q/2); b = a; if (q&1) a--;}
    else if (b >= a) {q-=(b-a); b = a; b-=(q/2); a = b; if (q&1) b--;}

    if (a - b >= p) b+=p;
    else if (b - a >= p) a+=p;
    else if (a >= b) {p-=(a-b); b = a; a+=(p/2); b = a; if (p&1) a++;}
    else if (b >= a) {p-=(b-a); a = b; b+=(p/2); a = b; if (p&1) b++;}

    cout << min(a,b) << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;
    while(_--)
        SOLVE();

    return 0;
}

