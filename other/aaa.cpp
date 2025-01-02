#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
static const uint16_t NMAX = 500;
static const int64_t bulan = 3000;
int64_t n, m, i, j, ans, maxx, dp[bulan + NMAX + 2];
struct job {
    int64_t val, cost;
}v[NMAX + 1];
inline bool cond(job &a, job &b) {
    return a.val * b.cost > a.cost * b.val;
}
int main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(nullptr);
    std :: cin >> n >> m;
    for (i = 0; i != n; ++ i)
        std :: cin >> v[i].cost;
    for (i = 0; i != n; ++ i)
        std :: cin >> v[i].val;
    if (m > bulan) {
        std :: sort(v, v + n, cond);
        ans = (m - bulan) / v[0].cost * v[0].val;
        m = (m - bulan) % v[0].cost + bulan;
    }
    for (i = 1; i <= m; ++ i) {
        for (j = 0; j != n; ++ j)
            if (i >= v[j].cost)
                dp[i] = std :: max(dp[i], dp[i - v[j].cost] + v[j].val);
        maxx = std :: max(maxx, dp[i]);
    }
    ans += maxx;
    std :: cout << ans;
    return 0;
}