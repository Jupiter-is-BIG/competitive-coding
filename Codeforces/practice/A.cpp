#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string data[] = {
        "....",
        "*...",
        ".*..",
        "**..",
        "..*.",
        "*.*.",
        ".**.",
        "***.",
        "...*",
        "*..*"
    };

    string x;
    cin >> x;
    int ok = 4;
    while(ok--) {
        for (int i = 0; i < 4; ++i) {
            int num = x[i] - '0';
            if (i == 3) {cout << data[num][ok]; continue;}
            cout << data[num][ok] << " ";
            if (i == 1) cout << "  ";
        }
        cout << "\n";
    }
    return 0;
}
