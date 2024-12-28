#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, k;
ll x[MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
    multiset<ll> small, big;
    ll sumS = 0, sumB = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            small.insert(x[i]);
            sumS += x[i];
            if (i >= k - 1) {
                cout << 0 << " ";
            }
            continue;
        }
        if (i >= k) {
            ll j = x[i - k];
            if (small.count(j)) {
                small.erase(small.find(j));
                sumS -= j;
            } else {
                big.erase(big.find(j));
                sumB -= j;
            }
        }
        if (!small.empty() && x[i] > *small.rbegin()) {
            big.insert(x[i]);
            sumB += x[i];
        } else {
            small.insert(x[i]);
            sumS += x[i];
        }
        if (small.size() + 1 > big.size()) {
            big.insert(*small.rbegin());
            sumB += *small.rbegin();
            sumS -= *small.rbegin();
            small.erase(small.find(*small.rbegin()));
        }
        if (big.size() > small.size()) {
            small.insert(*big.begin());
            sumS += *big.begin();
            sumB -= *big.begin();
            big.erase(big.begin());
        }
        if (i >= k - 1) {
            ll ans = small.size() * *small.rbegin();
            ans -= sumS;
            ans += sumB;
            ans -= big.size() * *small.rbegin();
            cout << ans << " ";
        }
    }
}