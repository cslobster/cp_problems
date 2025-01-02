#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2003;

int n, m, w;
pair<ll, ll> dp[MXN][MXN];
ll a[MXN], b[MXN];

int main() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    dp[0][0] = {0, w};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = {n + m, w};
            if (i) {
                pair<ll, ll> nw = {dp[i - 1][j].first, dp[i - 1][j].second + a[i]};
                if (nw.second > w) {
                    nw.second = a[i];
                    nw.first++;
                }
                dp[i][j] = min(dp[i][j], nw);
            }
            if (j) {
                pair<ll, ll> nw = {dp[i][j - 1].first, dp[i][j - 1].second + b[j]};
                if (nw.second > w) {
                    nw.second = b[j];
                    nw.first++;
                }
                dp[i][j] = min(dp[i][j], nw);
            }
        }
    }
    cout << dp[n][m].first << endl;
}