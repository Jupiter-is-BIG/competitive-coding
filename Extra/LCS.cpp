#include<bits/stdc++.h>
using namespace std;

vector<string> A;
vector<string> B;

string a, b;
int n, m;


pair<int, string> solve(int ai, int bi, map<char,stack<int>> s) {
    int res = 0;
    string gg = "";
    if (ai >= n || bi >= m) return {0,""};
    for(int i = bi; i < m; ++i) {
        if (!s[b[i]].empty()) {
            while(!s[b[i]].empty() && s[b[i]].top() < ai) s[b[i]].pop();
            if (!s[b[i]].empty()) {
                int tai = s[b[i]].top();
                s[b[i]].pop();
                pair<int, string> next = solve(tai + 1, i + 1, s);
                if (res < next.first + 1) {
                    res = next.first + 1;
                    gg = string(1,b[i]) + next.second;
                }
            }
        }
    }
    return {res, gg};
}

int main() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    map<char, stack<int>> s;
    for(int i = n - 1; i >= 0; --i) s[a[i]].push(i);
 
    cout << solve(0,0,s).second << "\n";

    return 0;
}
