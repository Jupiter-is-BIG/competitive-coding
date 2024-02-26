#include<bits/stdc++.h>
using namespace std;

int main() {
   /* set<int> s;
    s.insert(3);
    s.insert(1);
    s.erase(s.begin());
    int x = *s.begin();
    cout << s.count(3) << "\n"; */

    deque<int> d;
    d.push_back(3);
    d.push_back(5);
    d.pop_front();
    cout << d.at(0) << "\n";
    return 0;
}
