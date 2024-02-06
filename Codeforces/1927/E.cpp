// File generated on 24/02/06 07:45 by Anand

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
    ll n , k;
    cin >> n >> k;
    vec a(n+1);
    ll off = 0;

    ll ins = 1;
    bool front = true;
    ll c = 0;
    ll ma = (n/k)*k+1;
    //if (n%k == 0) ma = (n/k)*k;
    while(c != n) {
        //bool went = false;
        if (front) {
            for(ll i = 1 + off; i <= n; i+=k) {
               // went = true;
                a[i] = ins; c++;
                ins++;
            }
        } else {
            for(ll i = ma + off; i >= 1; i-=k) {
                if (i > n) continue;
                //went = true;
                a[i] = ins; c++;
                ins++;
            }
        }
        //if (went) off++;
        off++;
        front = !front;
    }
    rep(i,1,n+1) cout << a[i] << " ";
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

