// File generated on 24/01/31 08:42 by Anand

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    while(k--) {
        int x; cin >> x;
        int l = -1; // a[l] < x
        int r = n; // a[r] >= x
        
        while (r > l + 1) {
            int m = (l+r) / 2;

            if (a[m] < x) l = m;
            else r = m;
        }

        if (a[r] == x) {cout << "YES\n";}
        else {cout << "NO\n";}
    }

    return 0;
}

