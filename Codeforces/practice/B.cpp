#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 2) {
        if (s[0] == s[1]) cout << 0 << "\n";
        else cout << 1 << "\n";
        return 0;
    }
    string z = "";
    int x = 0;
    for(int i = 0; i < (n + 1) / 2; ++i) {
        if (s[i] == s[n - 1 - i]) z += "1";
        else z += "0";
        x++;
    }

    int b = 0, a = 1e9;
    for(int i = 0; i < x; i++) {
        if (z[i] == '0') {
            int xa = min(a, b) + 1;
            int xb = min(a, b + 2);
            a = xa;
            b = xb;
        } else if (z[i] == '1') {
            int xa = a + 1;
            int xb = min(a + 2, b);
            a = xa;
            b = xb;
        }
    }

    cout << min(a,b) << "\n";
    return 0;
}
