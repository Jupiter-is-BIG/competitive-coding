#include<iostream>
using namespace std;

int main() {
    int* a = new int[3];
    for(int i = 0; i < 3; ++i) {
        a[i] = 2;
        cout << a[i] << " ";
    }
    cout << "\n";
    delete[] a;

    vector<int>* b = new vector<int>(3);
    for(int i = 0; i < 3; ++i) {
        b[i] = 2;
        cout << b[i] << " ";
    }
    cout << "\n";

}
