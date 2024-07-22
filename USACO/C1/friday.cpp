/*
ID: clef.an1
TASK: friday
LANG: C++14           
*/

#include<bits/stdc++.h>

using namespace std;

int upd(vector<int>& f, int s, bool leap) {
        for(int i = 0; i < 12; ++i) {
            f[s]++;
            if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) s = (s+3)%7;
            else if (i == 1) { if (!leap) continue; s = (s+1)%7;}
            else s = (s+2)%7;
        }
        return s;
}

int main() {
    ofstream cout ("friday.out");
    ifstream cin ("friday.in");

    int n; cin >> n;
    vector<int> f(7);
    int s = 0;
    for(int i = 1900; i < 1900 + n; ++i) {
        bool leap = 0;
        if (i%100 == 0) leap = i%400 == 0;
        else leap = i%4 == 0;
        s = upd(f, s, leap);
    }
    for(int i = 0; i < 7; ++i) {cout << f[i]; if (i < 6) cout << " "; else cout << "\n";}
    return 0;
}



