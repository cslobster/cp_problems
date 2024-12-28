#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3, MXK = 12;

int n, k;
int a[MXN], dp[MXK][MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 1; j <= k + 1; j++) {
        for (int i = 0; i < n; i++) {
            if (j == 1) {
                dp[j][a[i]] = 1; continue;
            }
            for (int l = 0; l < i; l++) {
                if (a[l] < a[i]) {
                    dp[j][a[i]] += dp[j - 1][a[l]];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k + 1][i];
    }
    cout << ans << endl;
}