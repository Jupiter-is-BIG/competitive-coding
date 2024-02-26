#include<stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n , k;
    int x = 1;
     ans = 0;
    for (int i = 0; i < n; ++i) {
        if (x%k == 0) ans++;
        if (x < 9) x = x * 10 + (x + 1);
        if (x < 999) x = x * 100 + (x + 1);
        if (x < 9999) x = x * 1000 + (x + 1);
        x%=k;
    }
    return 0;
}
