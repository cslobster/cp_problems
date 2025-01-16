#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503, MXM = 1003, MOD = 998244353;

int n;
ll c[MXN][MXN], dp[MXN][MXM];
int a[MXN];

void init() {
    for (int i = 0; i < MXN; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i][j] + c[i - 1][j]) % MOD;
            c[i][j] = (c[i][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a, a + n + 1, 0), curSum = a[n];
    dp[n][a[n]] = 1;
    for (int i = n; i >= 2; i--) {
        // cout << i - 1 << " " << accumulate(a + i - 1, a + n + 1, 0) << endl;
        dp[i - 1][accumulate(a + i - 1, a + n + 1, 0)] = 1;
        // cout << endl << "SET: dp[" << i - 1 << "][" << accumulate(a + i - 1, a + n + 1, 0) << "] = " << 1 << endl;
        for (int j = 0; j <= curSum + a[i - 1]; j++) {
            // if (!dp[i][j]) continue;
            // dp[i - 1][j + a[i - 1]] += dp[i][j]; // if you just place all x + 1s in the very front
            // cout << "ADDED: dp[" << i - 1 << "][" << j + a[i - 1] << "] = " << dp[i - 1][j + a[i - 1]] << " += dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            for (int x = 0; x < a[i - 1]; x++) {
                // case for k = 0
                // dp[i - 1][[[]]]
                for (int k = 1; k <= j; k++) {
                    if (x + k + 1 > sum) continue;
                    dp[i - 1][x + k + 1] += dp[i][j] * c[a[i - 1] - x - 1 + curSum - k][a[i - 1] - x - 1] % MOD;
                    dp[i - 1][x + k + 1] %= MOD;
                    // place (a[i - 1] - x - 1) x-1's into j - k + a[i] - x - 1 slots
                    // use sticks and stones
                    // cout << "dp[" << i - 1 << "][" << x + k + 1 << "] = " << dp[i - 1][x + k + 1] <<
                        // " from dp[" << i << "][" << j << "] = " << dp[i][j] << "\t x = " << x << " k = " << k <<
                            // ", c(" <<j - k + a[i - 1] - x - 1 << ", " << a[i - 1] - x - 1 << ")" << endl;
                    // cout << "dp[" << i - 1 << "][" << x + k + 1 << "] = " << dp[i - 1][x + k + 1] <<
                        // " from dp[" << i << "][" << j << "] = " << dp[i][j] << "\t x = " << x << " k = " << k <<
                            // ", c(" <<a[i - 1] - x - 1 + curSum - k << ", " <<a[i - 1] - x - 1 << ") = " << c[a[i - 1] - x - 1 + curSum - k][a[i - 1] - x - 1] << endl;
                }
            }
        }
        curSum += a[i - 1];
    }
    ll ans = 0;
    for (int j = 0; j <= sum; j++) {
        ans += dp[1][j];
        ans %= MOD;
    }
    cout << ans << endl;
}