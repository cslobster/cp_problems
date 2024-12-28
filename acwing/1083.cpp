#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll x, y, k, b;

ll memo[32][2][21];

vector<int> conv(ll a) {
    vector<int> ans;
    while (a > 0) {
        ans.push_back(a % b);
        a /= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll dp(int i, bool under, vector<int> &targ, int cnt) {
    if (memo[i][under][cnt] != -1) return memo[i][under][cnt];
    if (cnt > k) return 0;
    if (i == targ.size()) {
        if (cnt == k) return 1;
        return 0;
    }
    int ans = 0;
    // add a 0
    ans += dp(i + 1, under || (0 < targ[i]), targ, cnt);
    // add a 1
    if ((under || targ[i] >= 1) && cnt < k) {
        ans += dp(i + 1, under || (1 < targ[i]), targ, cnt + 1);
    }
    return memo[i][under][cnt] = ans;
}

ll solve(vector<int> &a) {
    memset(memo, -1, sizeof(memo));
    return dp(0, false, a, 0);
}

int main() {
    cin >> x >> y >> k >> b;
    x--;
    vector<int> xx = conv(x), yy = conv(y);
    cout << solve(yy) - solve(xx) << endl;
}