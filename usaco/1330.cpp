#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, INF = 0x3f3f3f3f;

int n;
string s, bessie = "bessie";
int a[MXN];
pair<int, int> dp[MXN][7];

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 7; j++) {
            dp[i][j] = {1, INF};
        }
    }
    dp[0][0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 7; j++) {
            if (s[i - 1] == bessie[j - 1]) {
                dp[i][j] = min(dp[i - 1][j - 1], {dp[i - 1][j].first, dp[i - 1][j].second + a[i - 1]});
            } else {
                dp[i][j] = {dp[i - 1][j].first, dp[i - 1][j].second + a[i - 1]};
            }
        }
        dp[i][0] = min(dp[i - 1][0], {dp[i][6].first - 1, dp[i][6].second});
    }
    cout << -dp[n][0].first << endl << dp[n][0].second << endl;
}