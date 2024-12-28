#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 3;

int n;
int dp[MXN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (auto d : s) {
            dp[i] = min(dp[i], dp[i - (d - '0')] + 1);
        }
    }
    cout << dp[n] << endl;
}