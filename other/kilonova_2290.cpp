#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503, MXM = 300000, MXXX = 400000;

int n; ll m;
ll dp[MXXX], t[MXN], p[MXN];
int order[MXN];

bool comp(int i, int j) {
    return p[i] * t[j] > p[j] * t[i];
}

int main() {
    cin >> n >> m;
    iota(order, order + n, 0);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> p[i];
    ll ans = 0, cur = 0;
    if (m >= MXM) {
        sort(order, order + n, comp);
        cur = ((m - (MXN - 1LL)) / t[order[0]]) * p[order[0]];
        m = (m - (MXN - 1LL)) % t[order[0]] + MXN - 1LL;
    }
    for (int i = 1; i <= m; i++) dp[i] = -1e18;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (ll w = t[i]; w <= m; w++) {
            if (dp[w - t[i]] == -1e18) continue;
            dp[w] = max(dp[w], dp[w - t[i]] + p[i]);
            ans = max(ans, dp[w]);
        }
    }
    cout << ans + cur << endl;
}