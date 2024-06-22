// File generated on 24/06/11 07:22 by Anand

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = s[n - 1] - '0';
    int c = 0;
    char cur = s[n - 1];
    int flag = 0;
    int p = n - 1;
    int issue = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == cur) {
            if (c < k) {c++;}
            else {p = i; flag = 1; issue = 1; break;}
        } else {
            if (c == k) {p = i; flag = 1; c = 1; cur = s[i];}
            else {
                issue = 1;
                if (flag == 1) {break;}
                else {c = 1; cur = s[i];}
            }
        }
    }

    if (issue == 0) {cout << n << "\n"; return;}
    if (flag == 0) {cout << -1 << "\n"; return;}

    vector<int> fin;
    
    for(int i = p + 1; i < n; ++i) fin.push_back(s[i] - '0');
    for(int i = p; i >= 0; --i) fin.push_back(s[i] - '0');

    int start = fin[0];
    for(int i = 0; i < n; i+=k) {
        for(int j = i; j < i + k; ++j) {
            if (fin[j] != start) {cout << -1 << "\n"; return;}
        }
        start = abs(start - 1);
    }

    cout << p + 1 << "\n";
}

signed main() {
    fastio;

    ll _;
    cin >> _;

    while(_--) 
		SOLVE();

    return 0;
}

