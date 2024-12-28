#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        int x = __builtin_popcount(i);
        for (int y = 0; y < n; y++) {
            if ((i & (1 << y)) || !c[x][y]) continue;
            dp[i | (1 << y)] = (dp[i | (1 << y)] + dp[i]) % MOD;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}