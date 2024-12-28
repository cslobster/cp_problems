#include <bits/stdc++.h>
using namespace std;
vector<int> base;

set<int> f(int i, set<int> s, int a) {
    if (a == 4) return f(i + 1, s, 0);
    if (i >= 8) {
        return s;
    }
    set<int> c;
    for (auto x : s) {
        c.insert(x);
        if (base[i] * x <= 1e5)
            c.insert(base[i] * x);
    }
    return f(i, c, a + 1);
}

int main() {
    int t; cin >> t;
    set<int> s;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    for (int e = 0; e < 2; e++) {
                        base.push_back(1e4*a+1e3*b+100*c+10*d+e);
                        s.insert(1e4*a+1e3*b+100*c+10*d+e);
                    }
                }
            }
        }
    }
    base.push_back(1e5);
    s.insert(1e5);
    // 1, 10, 11, 100, 101, 110, 111,
    // 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10010
    // 10011,...
    set<int> c = f(0, s, 0);
    while (t--) {
        int n;
        cin >> n;
        if (c.count(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}