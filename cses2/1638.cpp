#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1003, MOD = 1e9 + 7;

int n;
char grid[MXN][MXN];
ll dp[MXN][MXN];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    dp[0][0] = (grid[0][0] != '*');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;
            if (i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}