#include<bits/stdc++.h>
using namespace std;

int main() {
    // max value less than given index
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    while(k--) {
        int x; cin >> x;

        int l = -1; // a[l] < x
        int r = n; // a[r] >= x
        
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (a[m] < x) l = m;
            else r = m;
        }

        cout << r + 1 << "\n";
    }
    return 0;
}

