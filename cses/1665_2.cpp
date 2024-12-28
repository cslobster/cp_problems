#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXX = 5003, MXY = 10000, K = 5000, MOD = 1e9 + 7;

using ll = long long;

ll n, x;
ll t[MXN], dp[2][MXN][MXY];
int ii = 0;

void add(ll &a, ll b) {
    a = (a + b) % MOD;
}

void reset() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < MXN; j++)
            for (int k = 0; k < MXY; k++) {
                dp[i][j][k] = 0;
            }
    }
}

int main() {
    reset();
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    dp[0][0][K] = 1;
    for (int i = 1; i <= n; i++) {
        ii = 1 - ii;
        int a = ii, b = 1 - ii;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < MXY; k++) {
                dp[a][j][k] = dp[b][j][k];
                add(dp[a][j][k], dp[b][j][k] * j);
                if (j && k + t[i] < MXY) add(dp[a][j][k], dp[b][j - 1][k + t[i]]);
                if (j + 1 < MXN && k >= t[i]) add(dp[a][j][k], (1 + j) * dp[b][j + 1][k - t[i]]);
            }
        }
    }
    ll ans = 0;
    for (int k = K; k <= K + x; k++) {
        // cout << dp[ii][0][k] << " " << k - K << endl;
        add(ans, dp[ii][0][k]);
    }
    cout << ans % MOD << endl;
}