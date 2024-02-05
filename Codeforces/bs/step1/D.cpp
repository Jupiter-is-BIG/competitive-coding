#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int k;
    cin >> k;
    while(k--) {
        int l, r;
        cin >> l >> r;
        
        int L = -1; // a[L] < l
        int R = n; // a[R] >= l
        
        while(R > L + 1) {
            int m = (L + R) / 2;
            if (a[m] < l) L = m;
            else R = m;
        }
        int temp = R;
        L = -1; // a[L] <= r
        R = n; // a[R] > r
        while (R > L + 1) {
            int m = (L+R)/2;

            if (a[m] <= r) L = m;
            else R = m;
        }

        cout << L  - temp + 1 << " ";
    }
    cout << "\n";

    return 0;
}


