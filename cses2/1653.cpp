#include <bits/stdc++.h>
using namespace std;

const int MXN = 20, MXM = (1 << 20);

int n, x;
int w[MXN];
array<int, 2> dp[MXM];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    dp[0][0] = 1, dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask][0] = n + 1, dp[mask][1] = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                array<int, 2> opt = dp[mask ^ (1 << i)];
                if (opt[1] + w[i] <= x) {
                    opt[1] += w[i];
                } else {
                    opt[0]++;
                    opt[1] = w[i];
                }
                dp[mask] = min(dp[mask], opt);
            }
        }
    }
    cout << dp[(1 << n) - 1][0] << endl;
}



/*
 *

6 15
1 3

*
 *
 */