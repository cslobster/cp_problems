#include <bits/stdc++.h>
using namespace std;

const int MXN = 5003;

int n;
string s;
int dp[MXN][MXN]; // is val-palindrome
int ans[MXN];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> s;
    n = s.size();
    for (int len = 0; len < n; len++) {
        for (int i = 0; i < n; i++) {
            int j = len + i;
            if (len == 0) {
                dp[i][j] = 1;
                ans[1]++;
                continue;
            }
            if (len == 1) {
                ans[dp[i][j] = (s[i] == s[j]) * 2]++;
                continue;
            }
            if (i + 1 < n && j && s[i] == s[j]) {
                if (!dp[i + 1][j - 1]) {
                    dp[i][j] = 0;
                } else {
                    int mid = (i + j + 1) / 2 - 1;
                    if (dp[i][mid]) {
                        dp[i][j] = dp[i][mid] + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                }
            }
            ans[dp[i][j]]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}