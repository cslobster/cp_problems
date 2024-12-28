#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MXN = 10, MXM = 1003, MXNM = (1 << 10), MOD = 1e9 + 7;

int n, m;
ll dp[MXM][MXNM];

void dfs(int d, int i, int mask, int nwmask) {
    if (d >= n) {
        dp[i + 1][nwmask] += dp[i][mask];
        dp[i + 1][nwmask] %= MOD;
        return;
    }
    if (mask & (1 << d)) {
        dfs(d + 1, i, mask, nwmask);
        return;
    }
    if (!(mask & (1 << d))) {
        dfs(d + 1, i, mask, nwmask ^ (1 << d));
    }
    if (d + 1 < n && !(mask & (1 << d)) && (!(mask & (1 << (d + 1))))) {
        dfs(d + 2, i, mask, nwmask);
    }
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i][mask] == 0) continue;
            // dfs(0, i, mask, 0);
            dfs(0, i, mask, 0);
        }
    }
    cout << dp[m][0] << endl;
}