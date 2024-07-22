/*
ID: clef.an1
TASK: ride
LANG: C++14           
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream cout ("ride.out");
    ifstream cin ("ride.in");
    string a, b;
    cin >> a >> b;
    int x = 1, y = 1;
    for(int i = 0; i < a.size(); ++i) 
        x = (x * (a[i] - 'A' + 1)) % 47;
    for(int i = 0; i < b.size(); ++i)
        y = (y * (b[i] - 'A' + 1)) % 47;
    if (x == y) cout << "GO\n";
    else cout << "STAY\n";
    return 0;
}

