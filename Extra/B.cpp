#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, c; cin >> n >> c;
    vector<int> price(n);
    for (int i = 0; i < n; ++i) cin >> price[i];

    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = price[i];
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + price[j - 1] - c);
        }
    }

    cout << dp[n - 1] << "\n";


    return 0;
}
