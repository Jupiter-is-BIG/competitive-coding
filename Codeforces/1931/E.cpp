// File generated on 24/02/13 07:22 by Anand

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
struct ComparePairs {
    bool operator()(const pll& a, const pll& b) const {
        // Compare based on the first element of the pair
        // If they are equal, compare based on the second element
        if (a.first != b.first) {
            return a.first > b.first; // Sort in decreasing order of first element
        } else {
            return a.second > b.second; // If first elements are equal, sort in decreasing order of second element
        }
    }
};

void SOLVE() {
    ll n, m;
    cin >> n >> m;
    multiset<pll, ComparePairs> s;
    rep(i,0,n) {
        ll x;
        cin >> x;
        ll a = 0, b = 0;
        while(x%10 == 0) {a++; x/=10;}
        while(x != 0) {b++; x/=10;}
        s.insert({a,b});
    }

    while(s.size() > 1) {
        pll ok = *s.begin();
       
        pll ups = {0, ok.second};
        s.erase(s.begin());
        s.insert(ups);


        ok = *s.begin();
        pll dw = *s.rbegin();
        ups = {dw.first, ok.first + ok.second + dw.second};
        s.erase(s.begin());
        s.erase(--s.end());
        s.insert(ups);
    }
    pll ok = *s.begin();

    if (ok.second > m) cout << "Sasha" << "\n";
    else cout << "Anna" << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

