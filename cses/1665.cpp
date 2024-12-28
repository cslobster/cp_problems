#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXX = 5003, K = 100;

int n, x;
int t[MXN], dp[2][MXN][MXX];
int ii = 0, a, b;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
    dp[0][0][K] = 1;
    for (int i = 1; i <= n; i++) {
        // int a = ii, b = 1 - ii;
        a = i, b = i - 1;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= x + K; k++) {
                // if (k == K) {
                // cout << "SDF" << endl;
                // }
                int &val = dp[a][j][k];
                val += dp[b][j][k];
                if (j && k + t[i] <= x + K) {
                    // if (i == 2 && dp[b][j - 1][k + t[i]]) {
                    // cout << "F" << endl;
                    // }
                    val += dp[b][j - 1][k - (-t[i])];
                }
                val += dp[b][j][k] * j;
                if (j + 1 < MXN && k >= t[i]) {
                    // if (dp[b][j + 1][k - t[i]]) cout << "FSDFOSUFDSIFDSF" << endl;
                    val += dp[b][j + 1][k - t[i]];
                }
            }
        }
        ii = 1 - ii;
    }
    // for (int i = 1; i <= 2; i++) {
    //     for (int j= 0; j < 3; j++) {
    //         for (int k = -5 + K; k <= 5 + K; k++) {
    //             cout << i << " " << j << " " << k - K << "\t" << dp[i][j][k] << endl;
    //         }
    //     }
    // }
    int ans = 0;
    for (int i = K; i <= x + K; i++) {
        ans += dp[n][0][i];
    }
    cout << ans << endl;
}
