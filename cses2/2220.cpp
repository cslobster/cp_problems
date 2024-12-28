#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXD = 20;

ll a, b;
ll dp[MXD][2][2][10];

ll f(int i, bool under, bool started, int prev, vector<ll> c) {
    if (prev != -1 && dp[i][under][started][prev] != -1) return dp[i][under][started][prev];
    if (i >= c.size()) {
        return 1;
    }
    ll ans = 0;
    ll digMax = 9;
    if (!under) digMax = c[i];
    for (int d = 0; d <= digMax; d++) {
        if (d == prev && started) continue;
        ans += f(i + 1, under || (d < c[i]), started || (d != 0), d, c);
    }
    return dp[i][under][started][prev] = ans;
}

vector<ll> read(ll c) {
    vector<ll> ans;
    while (c > 0) {
        ans.push_back(c % 10LL);
        c /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll solve(ll x) {
    for (auto &i : dp)
        for (auto &j : i)
            for (auto &k : j)
                for (auto &l : k)
                    l = -1;
    if (x < 0) return 0;
    return f(0, false, false, -1, read(x));
}

int main() {
    cin >> a >> b;
    a--;
    cout << solve(b) - solve(a) << endl;
}