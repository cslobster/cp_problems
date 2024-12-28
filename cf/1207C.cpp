#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s; cin >> s; s += '0';
        vector<array<ll, 2>> dp(n + 1, {(ll)1e18, (ll)1e18});
        dp[0][0] = b;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                dp[i][0] = min(dp[i - 1][0],
                    dp[i - 1][1] + a);
            }
            dp[i][1] = min(dp[i - 1][0] + a + b,
                dp[i - 1][1] + b);
        }
        cout << dp[n][0] << endl;
    }
}