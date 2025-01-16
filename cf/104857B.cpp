#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503, MOD = 998244353;

ll f[MXN];

void init() {
    f[0] = 1;
    for (int i = 1; i < MXN; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
}

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

ll inv(ll a) {
    return power(a, MOD - 2) % MOD;
}

ll c(int a, int b) {
    // assert(a >= b);
    ll ans = f[a];
    ans = (ans * inv(f[b])) % MOD;
    ans = (ans * inv(f[a - b])) % MOD;
    return ans;
}

int n;
int a[MXN]; ll dp[MXN][MXN];

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[n][1] = 1;
    ll ans = 0;
    for (int i = n; i >= 2; i--) {
        for (int j = 1; j <= n; j++) {
            if (!dp[i][j]) continue;
            for (int x = 0; x < a[i - 1]; x++) {
                dp[i - 1][j + a[i - 1]] = dp[i][j]; // if you just place all x + 1s in the very front
                for (int k = 0; k < j; k++) {
                    if (x + k + 1 > n) continue;
                    dp[i - 1][x + k + 1] += dp[i][j] * c(j - k + a[i - 1] - x - 1, a[i - 1] - x - 1) % MOD;
                    dp[i - 1][x + k + 1] %= MOD;
                    // place (a[i - 1] - x - 1) x+1's into j - k + a[i] - x - 1 slots
                    // use sticks and stones
                    // cout << "dp[" << i - 1 << "][" << x + k + 1 << "] = " << dp[i - 1][x + k + 1] << " from dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                }
            }
        }
    }
    for (int j = 0; j <= n; j++) {
        ans += dp[1][j];
        ans %= MOD;
    }
    cout << ans << "\n";
}