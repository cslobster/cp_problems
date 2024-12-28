#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, k;
int x[MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
    multiset<int> small, big;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            small.insert(x[i]);
            if (i >= k - 1) cout << *small.rbegin() << " ";
            continue;
        }
        if (i >= k) {
            int j = x[i - k];
            if (small.count(j)) {
                small.erase(small.find(j));
            } else {
                big.erase(big.find(j));
            }
        }
        if (!small.empty() && x[i] > *small.rbegin()) {
            big.insert(x[i]);
        } else {
            small.insert(x[i]);
        }
        if (small.size() + 1 > big.size()) {
            big.insert(*small.rbegin());
            small.erase(small.find(*small.rbegin()));
        }
        if (big.size() > small.size()) {
            small.insert(*big.begin());
            big.erase(big.begin());
        }
        if (i >= k - 1) cout << *small.rbegin() << " ";
    }
}