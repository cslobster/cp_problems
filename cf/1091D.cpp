#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e6 + 3, MOD = 998244353;

int n;
ll pref[MXN]; // product from i...n;

int main() {
    cin >> n;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        pref[i] = i;
        if (i != n) {
            pref[i] = (pref[i] * pref[i + 1]) % MOD;
        }
    }
    ans += pref[1];
    ans %= MOD;
    for (int i = 1; i < n; i++) {
        int val = n - (i + 1);
        if (val <= 0) break;
        ll start = i;
        // go from i + 2 ... n
        assert(i + 2 <= n);
        start = (start * pref[i + 2]) % MOD;
        // cout << "counting: " << i << " with value " << val << " " << start << " " << pref[i + 2] << endl;

        ans += (val * start) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}