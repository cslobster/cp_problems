#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXW = 2e5 + 3, MOD = 1e9 + 7;

int n;
ll dp[MXW];

ll exp(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n % 2 == 1) { ans = ans * x % MOD; }
        x = x * x % MOD;
        n /= 2;
    }
    return ans;
}

ll inv(ll a) {
    return exp(a, MOD - 2) % MOD;
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    sum /= 2;
    for (int i = 1; i <= n; i++) {
        for (int w = sum; w >= i; w--) {
            dp[w] += dp[w - i];
            dp[w] %= MOD;
        }
    }
    cout << (dp[sum] * inv(2)) % MOD << endl;
}