#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXW = 1e6 + 3;

int n, x;
int c[MXN], dp[MXW];

int main() {
    cin >> n >> x;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int w = c[i]; w <= x; w++) {
            dp[w] = min(dp[w], dp[w - c[i]] + 1);
        }
    }
    cout << ((dp[x] == 0x3f3f3f3f) ? -1 : dp[x]) << endl;
}