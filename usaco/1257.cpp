#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

int dp[MXN][4007];
int p[MXN], c[MXN], x[MXN];

int n, a, b;

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i] >> x[i];
    }
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int moonies = a; moonies >= 0; moonies--) {
            for (int cones = b; cones >= 0; cones--) {
                for (int amt = (int) c[i]; amt >= 0; amt--) {
                    if (moonies - c[i] + amt >= 0 && cones - x[i] * amt >= 0 &&
                        dp[moonies - c[i] + amt][cones - x[i] * amt] != -1) {
                        dp[moonies][cones] = max(dp[moonies][cones],
                        dp[moonies - c[i] + amt][cones - x[i] * amt] + p[i]);
                        ans = max(ans, dp[moonies][cones]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}