#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> conv(ll a, ll b) {
    vector<int> ans;
    while (a > 0) {
        ans.push_back(a % b);
        a /= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll dp[12][2][10];

ll f(int i, bool under, vector<int> &targ, int prev) {
    if (dp[i][under][prev] != -1) return dp[i][under][prev];
    if (i == targ.size()) {
        return 1;
    }
    ll ans = 0;
    int limit = under ? 9 : targ[i];
    for (int d = prev; d <= limit; d++) {
        ans += f(i + 1, under || (d < targ[i]), targ, d);
    }
    return dp[i][under][prev] = ans;
}

ll solve(int x) {
    memset(dp, -1, sizeof(dp));
    vector<int> d = conv(x, 10);
    return f(0, false, d, 0);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << solve(b) - solve(a - 1) << endl;
    }
}