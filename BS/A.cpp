#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int and_list(vector<int> &X) {
    int res = X[0]; // X is non-empty
    for (int i = 1; i < X.size(); ++i) res &= X[i];
    return res;
}

int xor_list(vector<int> &X) {
    int res = X[0]; // X is non-empty
    for (int i = 1; i < X.size(); ++i) res ^= X[i];
    return res;
}

int f(vector<int> &X) {
    if (X.size() == 0) return 0;
    vector<int> xor_values;
    for (int i = 0; i < X.size(); ++i) {
        for (int j = i; j < X.size(); ++j) {
            // we consider numbers [X_i ... X_j]
            vector<int> contList;
            for (int k = i; k <= j; ++k) contList.push_back(X[k]);
            xor_values.push_back(xor_list(contList));
        }
    }
    return and_list(xor_values);
}

int f_eff_2(vector<int> &X) {
    if (X.size() == 0) return 0;
    int res = X[0];

    vector<int> pre(X.size() + 1); // pre[i] = X_1 ^ X_2 ^ ... ^ X_i (1 - indexing)
    for (int i = 1; i < X.size() + 1; ++i) {
        pre[i] = X[i - 1] ^ pre[i - 1];
    }
   
    for (int i = 0; i < X.size(); ++i) {
        for (int j = i; j < X.size(); ++j) {res &= pre[j + 1] ^ pre[i];}
    }

    return res;
}

int f_eff(vector<int>& X) {
    if (X.empty()) return 0;

    int result = 0;
    int bits = 0;

    for (int i = 30; i >= 0; --i) { // 30 because 10^9 < 2^30
        int count = 0;
        for (int j = 0; j < X.size(); ++j) {
            if (X[j] & (1 << i)) // Check if the ith bit is set
                ++count;
        }
        // If there are at least two elements with ith bit set
        if (count >= 2) bits |= (1 << i); // Set ith bit in result
    }

    for (int num : X) {
        result |= (num & bits); // Take the bitwise AND with the bits we found
    }

    return result;
}


int main() {
    vector<int> X = {3, 5, 1};
    cout << and_list(X) << "\n"; // prints 1
    cout << xor_list(X) << "\n"; // prints 7
    cout << f(X) << "\n"; // prints 0
    cout << f_eff_2(X) << "\n"; // prints 0
    return 0;
}
