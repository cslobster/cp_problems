#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;
int n, m;

multiset<int> h;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        h.insert(a);
    }
    for (int j = 0; j < m; j++) {
        int x; cin >> x;
        auto it = h.upper_bound(x);
        if (it == h.begin()) {
            cout << -1 << endl; continue;
        }
        it--;
        cout << *it << endl;
        h.erase(it);
    }
}