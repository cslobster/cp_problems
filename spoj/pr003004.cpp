#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[16][2][140];

int getSum(int i, bool smaller, int s, string targ) {
    if (i == targ.size()) return s;
    if (dp[i][smaller][s] != -1) return dp[i][smaller][s];
    int small = (smaller ? 9 : targ[i] - '0');
    int ans = 0;
    for (int d = 0; d <= small; d++) {
        ans += getSum(i + 1, smaller || (d < targ[i] - '0'), s + d, targ);
    }
    return dp[i][smaller][s] = ans;
}

int solve(int x) {
    if (x == -1) return 0;
    string targ = to_string(x);
    memset(dp, -1, sizeof(dp));
    return getSum(0, 0, 0, targ);
}


signed main() {
//    cout << solve(1) << endl << solve(2) << endl << solve(3);
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
}