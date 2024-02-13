#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> use(1 + k);
    stack<int> ok;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = n - 1; i >= 0; --i) {
        if (use[a[i]] == 0) {use[a[i]] = 1; ok.push(i);}
    }
    

    set<pair<int, int>> q;
    int x = 0;
    vector<int> seen(1 + k);
    int clean = 0; // if index < clean then remove
    for(int i = 0; i < n; ++i) {
        if (x == k) break;

        if (seen[a[i]] == 0) {
            q.insert({a[i], i});
        }

        if (i == ok.top()) {
            ok.pop();
            while (seen[a[i]] == 0) {
                pair<int, int> in = *q.begin();
                if (in.second < clean || seen[in.first] == 1) {q.erase(in); continue;}
                clean = in.second;
                cout << in.first << " ";
                seen[in.first] = 1;
                q.erase(in);
                x++;
            }
        }
    }

    /*while (x < k && q.size() != 0) {
        pair<int, int> in = *q.begin();
        if (in.second < clean || seen[in.first] == 1) {q.erase(in); in = *q.begin(); continue;}
        clean = in.second;
        cout << in.first << "\n";
        seen[in.first] = 1;
        q.erase(in);
        x++;
        in = *q.begin();
    }*/

    cout << "\n";


    return 0;
}
