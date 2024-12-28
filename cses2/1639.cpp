#include <bits/stdc++.h>
using namespace std;

const int MXN = 5003;

int n, m;
string s, t;
int dp[MXN][MXN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> s >> t;
    dp[0][0] = 0;
    n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    for (int i = 1; i <= n; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            if (s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
}