#include<bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; ++i) cin >> price[i];

    vector<int> dp(n);
    vector<pair<int, int>> cuts(n); // first: refers to next cut, second: current cut length
    for (int i = 0; i < n; ++i) {
        int cutAt = -1;
        dp[i] = price[i];
        for (int j = 1; j <= i; ++j) {
            if (dp[i] < dp[i - j] + price[j - 1]) cutAt = j;
            dp[i] = max(dp[i], dp[i - j] + price[j - 1]);
        }
        if (cutAt == -1) cuts[i] = {-1, i + 1};
        else cuts[i] = {i - cutAt, cutAt};
    }
    
    int node = n - 1;
    cout << "Max price: " << dp[node] << "\nSplit in the following way:\n";
    while(node != -1) {
        cout << cuts[node].second << " ";
        node = cuts[node].first;
    }
    cout << "\n";

    return 0;
}

