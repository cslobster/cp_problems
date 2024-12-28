#include <bits/stdc++.h>
using namespace std;

const int MXN = 503;

int n;
int c[MXN], dp[MXN][MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int l = 0; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            // if (!l) {dp[i][i] = 1; continue;}
            // int j = l + i;
            // dp[i][j] = 1 + dp[i + 1][j];
            // if (c[i] == c[i + 1]) {
            //     dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            // }
            // for (int k = i + 1; k <= j; k++) {
            //     if (c[i] == c[k]) {
            //         dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
            //     }
            // }
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 1 + dp[i + 1][j];
                if (c[i] == c[i + 1]) {
                    dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);
                }
                for (int match = i + 2; match <= j; match++) {
                    if (c[i] == c[match]) {
                        dp[i][j] = min(dp[i + 1][match - 1] + dp[match + 1][j], dp[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}