#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0x3f3f3f3f));
        // dp[i][j] = min number of skips to kill i bosses, right when j's turn ends
        dp[0][1] = 0;
        // 0 = friend, 1 = you
        for (int i = 1; i <= n; i++) {
            int one = 0, two = 0;
            if (a[i] == 1) one++;
            if (a[i - 1] == 1) two++;
            dp[i][0] = dp[i - 1][1] + one;
            dp[i][1] = dp[i - 1][0];
            if (i - 1) {
                dp[i][0] = min(dp[i][0], dp[i - 2][1] + one + two);
                dp[i][1] = min(dp[i][1], dp[i - 2][0]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}