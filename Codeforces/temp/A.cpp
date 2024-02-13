#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i].push_back(s[0] - 'a');
        a[i].push_back(s[1] - 'a');
        a[i].push_back(s[2] - 'a');
        sort(a[i].begin(), a[i].end());
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i) {
        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
    }

    return 0;
}
