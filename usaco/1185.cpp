#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 102, MOD = 1e9 + 7;;

int n;
int h[MX];
ll dp[MX][1001], pre[MX][1001];

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    int ub = 1001;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        ub = min(ub, h[i]);
    }
    if (!(n & 1)) ub = 0;
    ll ans = 0;
    for (int b = 0; b <= ub; b++) {
        memset(dp[i], 0, sizeof(dp[i]));
        memset(pre[i], 0, sizeof(pre[i]));
        for (int i = 0; i < n; i++) {

            h[i] -= b;
        }
        for (int j = 0; j <= h[0]; j++) {
            dp[0][j] = 1;
        }
        pre[0][0] = 1;
        for (int j = 1; j < 1001; j++) {
            pre[0][j] = (pre[0][j - 1] + dp[0][j]) % MOD;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= h[i]; j++) {
                dp[i][j] = pre[i - 1][h[i] - j];
            }
            // set up pre[i]
            for (int j = 0; j < 1001; j++) {
                pre[i][j] = dp[i][j];
                 if (j) pre[i][j] += pre[i][j - 1];
                pre[i][j] %= MOD;
                // cout << dp[i][j] << " " << i << " " << j << " " << pre[i][j] << endl;
            }
        }
        ans += dp[n - 1][0];
        ans %= MOD;
        for (int i = 0; i < n; i++) {
            h[i] += b;
        }
    }
    cout << ans << endl;
}