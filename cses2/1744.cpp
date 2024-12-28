#include <bits/stdc++.h>
using namespace std;

const int MXN = 503;

int a, b;
int dp[MXN][MXN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> a >> b;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) dp[i][j] = 0;
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
}