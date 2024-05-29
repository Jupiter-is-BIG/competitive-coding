#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int _;
    cin >> _;
    while(_--) {
        ll n;
        cin >> n;
        ll ans = 0;
        ll a[n];
        for(ll i = 0; i < n; ++i) cin >> a[i];
        if (n == 2) {cout << min(a[0],a[1]) << "\n"; continue;}
        for(ll i = 1; i < n-1; ++i) {
            ll x[3] = {a[i-1],a[i],a[i+1]};
            sort(x,x+3);
            ans = max(ans, x[1]);
        }
        cout << ans << "\n";
    }
}
