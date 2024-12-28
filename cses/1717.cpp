#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[0] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (((dp[i - 1] + dp[i - 2]) % MOD) * (i - 1)) % MOD;
    }
    cout << dp[n] << endl;
}