#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

using ll = long long;

int n;
ll s[MXN], dp[MXN][MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    for (int len = 0; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = len + i;
            dp[i][j] = 1e18;
            if (len == 0) {
                dp[i][j] = 0;
                continue;
            }
            // subtract the left side (i + 1 -> j)
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + s[j] - s[i]);
            // subtract right side (i -> j - 1)
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + s[j] - s[i]);
        }
    }
    cout << dp[0][n - 1] << endl;
}