#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5003;

int n;
ll x[MXN], dp[MXN][MXN][2]; // max score if it is your turn, or other person's turn

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int sz = 0; sz < n; sz++) {
        for (int i = 0; i + sz < n; i++) {
            int j = sz + i;
            dp[i][j][0] = LLONG_MIN / 2, dp[i][j][1] = LLONG_MAX / 2;
            if (i == j) {
                dp[i][i][0] = x[i];
                dp[i][i][1] = 0;
                continue;
            }
            dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][1] + x[j]);
            dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][1] + x[i]);

            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0]);
            dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][0]);
        }
    }
    cout << dp[0][n - 1][0] << endl;
}