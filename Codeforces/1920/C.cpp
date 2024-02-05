// File generated on 24/01/13 07:14 by Anand

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


ll countDivisors(ll n, vec& b) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) {
                cnt++; 
                b.pb(i);
            }
  
            else // Otherwise count both 
            {
                cnt = cnt + 2; 
                b.pb(i);
                b.pb(n/i);

            }
        } 
    } 
    return cnt; 
}

bool check(vec& a, ll p, ll n) {
    if (p == n) return true;
    ll g = abs(a[p+1] - a[1]);
    for (ll i = 1; i <= p; i++) {
        for(ll j = 0; i + j <= n - p; j+=p) {
            g = __gcd(g, abs(a[i+j] - a[i + j + p]));
           // cout << abs(a[i+j] - a[i+j+p]) << " " << g << endl;
        }
    }
    return g > 1 || g ==0;
}

void SOLVE() {
    ll n;
    cin >> n;
    vec b;
    ll d = countDivisors(n, b);
    vec a(n+1);
    
    rep(i,1,n+1) {
        cin >> a[i];
    }

    if(check(a,1,n)) {cout << d<<endl;  return;}
    
    ll ans = 0;
    for(ll i: b) {if(check(a,i,n)) ans++; 
        //DEBUG(i);
        //
        }
    cout << ans << endl;
    /*
    ll m = n;
    ll k = 2;
    ll gg = 1;
    while(n != 1) {
        //DEBUG(n);
        ll t = 0;
        while (n%k == 0) {
            n = n/k;
            t++;
        }
        
        if (check(a,k,m)) {
            //DEBUG(k);
                           gg*=(t+1);}
        k++;
    }

    //cout << "mmm"<<gg<<endl;
    cout << max((d/gg)*(gg-1), 1ll) << endl;
    
    */
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

