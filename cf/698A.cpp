#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 3>> dp(n + 1, {100, 100, 100});
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 2; k++) {
            if (a[i] & k) {
                dp[i][k] = min(dp[i - 1][0], dp[i - 1][3 - k]);
            }
        }
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}