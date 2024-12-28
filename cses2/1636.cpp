#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXW = 1e6 + 3, MOD = 1e9 + 7;

int n, x;
int c[MXN], dp[MXW];

int main() {
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int w = c[i]; w <= x; w++) {
            dp[w] += dp[w - c[i]];
            dp[w] %= MOD;
        }
    }
    cout << dp[x] << endl;
}