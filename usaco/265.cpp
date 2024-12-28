#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("cowrun.in");
    ofstream cout("cowrun.out");

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {0x3f3f3f3f, 0x3f3f3f3f}));
    // dp[l][r] = {min cost on left, min cost on right}

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j].first = (dp[i][j].second = abs(p[i]) * n);
            } else {
                if (i < n - 1) {
                    dp[i][j].first = min(dp[i + 1][j].first + (p[i + 1] - p[i]) * (n - j + i),
                                         dp[i + 1][j].second + (p[j] - p[i]) * (n - j + i));
                }
                if (j) {
                    dp[i][j].second = min(dp[i][j - 1].second + (p[j] - p[j - 1]) * (n - j + i),
                                         dp[i][j - 1].first + (p[j] - p[i]) * (n - j + i));
                }
            }
        }
    }
    cout << min(dp[0][n - 1].first, dp[0][n - 1].second) << endl;
}