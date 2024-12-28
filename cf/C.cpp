#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

ll fast_power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) { // if b is odd
            ans *= a;
            ans %= MOD;
            b--;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}

int inv(int a) {
    return fast_power(a, MOD - 2) % MOD;
}

int main() {
    vector<pair<ll, ll>> dp(1e6 + 2);
    dp[1] = {1, 1}, dp[2] = {1, 1};
    for (int i = 3; i <= 1e6 + 1; i++) {
        int pa = inv(i - 1), pb = (inv(i - 1) * (i - 2)) % MOD;
        dp[i] = {(dp[i - 1].first * pa) % MOD + ((dp[i - 1].second + 1) * pb) % MOD,
                    (dp[i - 1].first * pa) % MOD + (dp[i - 1].second * pb) % MOD};
        dp[i].first %= MOD, dp[i].second %= MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n + 1].second << endl;
    }
}