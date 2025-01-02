#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 50, MXK = 2503, MXR = 13, MXM = (1 << 12);

ll n, m, k;
char grid[MXN][MXN];
ll dp[MXK][MXM], amt[MXK][MXR];;
ll x[MXK], y[MXK], p[MXK];

int dist(int i1, int j1, int i2, int j2) {
    return (i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int t = 1; t <= k; t++) {
        cin >> x[t] >> y[t] >> p[t];
        x[t]--, y[t]--;
        for (int r = 1; r <= MXR; r++) {
            amt[t][r - 1] = 0;
            for (int i = max(x[t] - r, 0LL); i < min(x[t] + r + 1, n); i++) {
                for (int j = max(y[t] - r, 0LL); j < min(y[t] + r + 1, m); j++) {
                    if (dist(i, j, x[t], y[t]) <= r * r && grid[i][j] == '#') {
                        // if (r == 1 && t == 2) {
                            // cout << i << " " << j << " " << dist(i, j, x[t], y[t]) << endl;
                        // }
                        amt[t][r - 1]++;
                    }
                }
            }
            // cout << x[t] << " " << y[t] << " " << r << " " << amt[t][r - 1] << endl;
        }
    }
    for (int mask = 0; mask < MXM; mask++) {
        for (int i = 0; i < k; i++) {
            dp[i][mask] = -1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int mask = 0; mask < MXM; mask++) {
            dp[i][mask] = dp[i - 1][mask];
            for (int r = 0; r < MXR; r++) {
                if (!(mask & (1 << r))) continue;
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << r)] + p[i] * amt[i][r]);
            }
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < MXM; mask++) {
        int sub = 0, power = 3;
        for (int i = 0; i < MXR; i++) {
            if (mask & (1 << i)) {
                sub += power;
            }
            power *= 3;
        }
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dp[i][mask] - sub);
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}