#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> successor(vector<int> &a) {
    vector<int> res;
    int carry = 1;
    for (int i = 0; i < a.size(); ++i) {
        int val = (a[i] + carry) % 3;
        carry = max(0, a[i] + carry - 2);
        res.push_back(val);
   }

   if (carry != 0) res.push_back(carry);
   return res;
}

bool leq(vector<int> &a, vector<int> &b) {
    if (a.size() == 0) return true;
    if (b.size() == 0) return false;

    int start_a = a.size() - 1, start_b = b.size() - 1;
    while(a[start_a] == 0) {start_a--; if (start_a == -1) return true;}
    while(b[start_b] == 0) {start_b--; if (start_b == -1) return false;}

    if (start_b > start_a) return true;
    if (start_b < start_a) return false;
    
    int n = start_a;
    while (n >= 0) {
        if (b[n] == a[n]) {n--; continue;}
        if (b[n] > a[n]) return true;
        return false;
    }

    return true;
}

vector<int> tritwise_min(vector<int> &a, vector<int> &b) {
    vector<int> res(min(a.size(),b.size()));
    for (int i = 0; i < min(a.size(), b.size()); ++i) res[i] = min(a[i], b[i]);
    return res;
}

vector<int> f(vector<int> a, vector<int> &b) {
    vector<int> res = a;
    while(leq(a,b)) {
        res = tritwise_min(a, res);
        a = successor(a);
    }
    return res;
}

vector<int> f_eff(vector<int> &a, vector<int> &b) {
    if (a.size() == 0 || b.size() == 0) return {};

    int start_a = a.size() - 1, start_b = b.size() - 1;
    while(a[start_a] == 0) {start_a--; if (start_a == -1) return {};}
    while(b[start_b] == 0) {start_b--; if (start_b == -1) return {};}

    if (start_b > start_a) return {};
    
    // now start_b = start_a
    int n = start_a;
    int m = n + 1;
    while (n>0) {
        if (a[n] == b[n]) {n--; continue;}
        // else b[n] > a[n]
        break;
    }
 
    vector<int> res(m);
    for(int i = n; i < m; ++i) res[i] = a[i];
    return res;
}

int main() {
    vector<int> X = {2, 0, 1};
    vector<int> suc = successor(X);
    for (int& i: suc) cout << i << " ";
    cout << "\n";
    // prints [0, 1, 1]
    
    vector<int> A = {2, 0, 1, 0, 0};
    vector<int> B = {0, 1, 1};
    cout << leq(A,B) << "\n"; // returns true
   
    vector<int> ta = {2,1};
    vector<int> tb = {0,2,1};
    vector<int> tmin = tritwise_min(ta, tb);
    for(int& i: tmin) cout << i << " ";
    cout << "\n"; // returns [0, 1]
    
    vector<int> fa = {2, 0, 1};
    vector<int> fb = {1, 1, 1};
    vector<int> fmin = f(fa, fb);
    for(int& i: fmin) cout << i << " ";
    cout << "\n"; // returns [0, 0, 1]
    
    vector<int> f_eff_min = f_eff(fa, fb);
    for(int& i: f_eff_min) cout << i << " ";
    cout << "\n"; // returns [0, 0, 1]
    return 0;
}

