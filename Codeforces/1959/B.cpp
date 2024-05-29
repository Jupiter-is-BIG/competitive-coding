#include<bits/stdc++.h>
using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    if (a == b) {cout << "=\n"; return;}
    if (a[a.size() - 1] == b[b.size() - 1]) {
        if (a.size() > b.size()) {if (a[a.size() - 1] == 'L') cout << ">\n"; else cout << "<\n";}
        else {if (a[a.size() - 1] == 'L') cout << "<\n"; else cout << ">\n";}
    } else {
        if (a[a.size() - 1] > b[b.size() - 1]) cout << "<\n";
        else cout << ">\n";
    }
}

int main() {
    int _;
    cin >> _;
    while(_--) solve();
}
