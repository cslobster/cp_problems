#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3, MXM = 103, MOD = 1e9 + 7;

int n, m;
int x[MXN], dp[MXN][MXM];

void add(int &a, int b) {
    a += b;
    a %= MOD;
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        if (x[i] != 0) {
            if (i == 1) {
                dp[i][x[i]] = 1;
                continue;
            }
            add(dp[i][x[i]], dp[i - 1][x[i]]);
            if (x[i]) add(dp[i][x[i]], dp[i - 1][x[i] - 1]);
            if (x[i] + 1 <= m) add(dp[i][x[i]], dp[i - 1][x[i] + 1]);
            continue;
        }
        for (int prev = 1; prev <= m; prev++) {
            if (i == 1) {
                dp[i][prev] = 1;
                continue;
            }
            if (prev) add(dp[i][prev], dp[i - 1][prev - 1]);
            add(dp[i][prev] , dp[i - 1][prev]);
            if (prev + 1 <= m) add(dp[i][prev], dp[i - 1][prev + 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) add(ans, dp[n][i]);
    cout << ans << endl;
}