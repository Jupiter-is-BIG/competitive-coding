#include<bits/stdc++.h>
using namespace std;

int n, x, y;

bool good(int T) {
    return (T / x) + (T / y) >= n;
}

int main() {
    cin >> n >> x >> y;

    if (n == 1) {cout << min(x, y) << "\n"; return 0;}

    int t = min(x, y);
    n--;

    int l = 0; // bad
    int r = 1; // good
    while(!good(r)) r*=2;

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << r + t << "\n";


    return 0;
}





