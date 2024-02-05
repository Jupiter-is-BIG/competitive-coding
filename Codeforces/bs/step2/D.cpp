#include<bits/stdc++.h>
using namespace std;

int m , n;
vector<int> t, z, y;

bool ver(int q, int x, int a, int b, int c) {
    return q*a + (ceil((q+0.0)/b) - 1) * c <= x;
}

int ball (int i, int x) {
    int a = t[i], b = z[i], c = y[i];
    // 1 1 2
    // 
    // Q balloons
    // Qa + (Q/b - 1)c <= Q*a + (ceil(Q/b) - 1)*c <= x
    // Q <= x/(a+c/b)
    // Q <= (x+c)/(a+c/b)
    //
    int l = 0; // good  
    int r = 1;
    while (ver(r, x, a, b, c)) r*=2;

    while(r  >  l + 1) {
        int m = (l+r)/2;
        if (ver(m , x,a,  b, c)) l = m;
        else r= m;
    }

    return l;
}

bool good(int x) {
    int s = 0;
    for(int i = 0; i < n; ++i) {
        s+= ball(i, x); // number of balloons filled by ith person in t mins.
    }

    return s >= m;
}

int main() {
    cin >> m >> n;

    t.resize(n);
    z.resize(n);
    y.resize(n);

    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        cin >> z[i];
        cin >> y[i];
    }

    if (m == 0) {
        cout << 0 << "\n";
        for(int i = 0; i < n; ++i) cout << 0 << " ";
        cout << "\n";
        return 0;
    }

    int l = 0; // bad
    int r = 1; // good
    while(!good(r)) r*= 2;

    while(r > l + 1) {
        int m = (l + r) / 2;
        if (good(m)) r = m;
        else l = m;
    }
    
    cout << r << "\n";
    int S = 0;
    for (int i = 0; i < n; ++i) {
        if(S>m) {cout << "0 "; continue;}
        int temp = ball(i,r);
        int pre = S;
        S += temp;
        if (S>m) {cout << m - pre << " "; continue;}
        cout << temp << " ";
    }
    cout << "\n";
    //cout << ball(1, 1) << "\n";
    return 0;
}






