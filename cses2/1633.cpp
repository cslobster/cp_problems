#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e6 + 3, MOD = 1e9 + 7;;

int n;
ll dp[MXN];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
        if (i <= 6) dp[i]++;
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
}