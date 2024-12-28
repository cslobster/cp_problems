#include <bits/stdc++.h>
using namespace std;

const int MXN = 1003, MXW = 1e5 + 3;

int n, x;
int h[MXN], s[MXN], dp[MXW];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int j = 0; j < n; j++) cin >> s[j];
    for (int i = 0; i < n; i++) {
        for (int w = x; w >= h[i]; w--) {
            dp[w] = max(dp[w], dp[w - h[i]] + s[i]);
        }
    }
    cout << dp[x] << endl;
}