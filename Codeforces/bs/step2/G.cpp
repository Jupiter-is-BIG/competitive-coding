#include<bits/stdc++.h>
using namespace std;

long long k, n;
vector<long long> a;
// (....) (....) (....) x = 3
bool good(long long x) {
    long long t = 0;
    for(long long i = 0; i < n; ++i) {
        t += min(x, a[i]);
    }
    return t >= k*x;
}

int main() {
    cin >> k;
    cin >> n;

    a.resize(n);

    for(long long i = 0; i < n; ++i) {cin >> a[i];}
    
    long long l = 0; // good
    long long r = 1;
    while(good(r)) r*=2;

    while(r > l + 1) {
        long long m = (l + r) / 2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << l << "\n";
    return 0;
}
