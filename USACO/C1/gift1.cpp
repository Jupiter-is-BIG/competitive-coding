/*
ID: clef.an1
TASK: gift1
LANG: C++14           
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream cout ("gift1.out");
    ifstream cin ("gift1.in");

    int n; cin >> n;
    map<string, int> m;
    vector<string> x(n);
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        x[i] = s;
    }

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;
        if (b == 0) {m[s] += a; continue;}
        m[s] += -a + (a - (a/b) * b);
        for(int j = 0; j < b; ++j) {
            string g; cin >> g;
            m[g] += (a/b);
        }
    }

    for(string& i: x)
        cout << i << " " << m[i] << "\n";
    
    return 0;
}


