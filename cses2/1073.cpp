#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
int k[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i];
    multiset<int> t;
    for (int i = 0; i < n; i++) {
        auto it = t.lower_bound(-k[i]);
        if (it == t.begin()) {
            t.insert(-k[i]);
        } else {
            it--;
            t.erase(it);
            t.insert(-k[i]);
        }
    }
    cout << t.size() << endl;
}