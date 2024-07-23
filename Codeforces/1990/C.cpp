// File generated on 24/07/22 19:53 by Anand

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
    vec A(n);
    map<ll, ll> m;
    set<ll> s;
    s.insert(0);
    ll ans = 0;
    rep(i,0,n) {
        ll x;
        cin >> x;
        ans += x;
        m[x]++;
        if (m[x] == 2) s.insert(-x);
        A[i] = *(s.begin());
    }
    map<ll, ll> M;
    rep(i,0,n) M[A[i]]++;
    vecp B;
    for(auto& p: M) B.pb({-p.first, p.second});
    sort(B.begin(), B.end());
    ll b = 0, num = 0;
    for(ll i = B.size() - 1; i >= 0; --i) {
        if (B[i].second == 1) {b++; ans += B[i].first; num++; continue;}
        num += B[i].second;
        ll sum = B[i].first * B[i].second;
        ans+=sum;
        ll repeat = (num - B[i].second - b) * (B[i].second + b) * B[i].first;
        if (repeat >= 0) ans += repeat;
        ll r2 = (((B[i].second + b - 1) * (B[i].second + b)) / 2) * B[i].first;
        ans += r2;
        b = 0;
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    ll N; cin >> N;
    while(N--) SOLVE();

    return 0;
}

