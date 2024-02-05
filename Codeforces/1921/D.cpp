// File generated on 24/01/15 06:56 by Anand

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
    ll n, m;
    cin >> n >> m;
    vec a(n);
    vec b(m);
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    ll l = 0, r = m-1;
    ll ol = 0, orr = n - 1;
    rep(i,0,n) {
        //ll L, R;
        ll LL = abs(a[ol] - b[l]);
        ll LR = abs(a[ol] - b[r]);
        ll RL = abs(a[orr] - b[l]);
        ll RR = abs(a[orr] - b[r]);
        ll o1 = 0, o2 = 0;
        if (LL >= LR) {
            o1 = 0;
        } else o1 = 1;

        if (RL >= RR) {o2 = 0;} else o2 = 1;

        ll a1 = max(LL, LR);
        ll a2= max(RL, RR);
        if (a1 >= a2) {
            ol++;
            if (o1 == 0) {ans += a1; l++;}
            else {ans+=a1; r--;}
        } else {
            orr--;
            ans+=a2;
            if (o2 == 0) l++;
            else r--;
        }
        //if (L >= R) {ans+=L; l++;}
        //else {ans+=R; r--;}

        //if (L2 >= R2) {ans2+=L2; l2++;}
        //else {ans2+=R2; r2--;}
        //DEBUG(ans);
        //DEBUG(ans2);
    }
   // ans2 = ans;
    
    cout << ans << endl;
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

