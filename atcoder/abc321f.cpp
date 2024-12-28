#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

signed main() {
    int q, k;
    cin >> q >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    while (q--) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] += dp[i - x];
                dp[i] %= MOD;
            }
        } else {
            for (int i = x; i <= k; i++) {
                dp[i] += MOD;
                dp[i] -= dp[i - x];
                dp[i] %= MOD;
            }
        }
        cout << dp[k] << endl;
    }
}