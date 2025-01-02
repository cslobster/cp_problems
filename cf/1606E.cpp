#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503, MOD = 998244353;

int n, x;
ll dp[MXN][MXN];
ll f[MXN];

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

void init() {
    f[0] = 1;
    for (int i = 1; i < MXN; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
}

ll inv(ll a) {
    return power(a, MOD - 2) % MOD;
}

ll c(int a, int b) {
    assert(a >= b);
    ll ans = f[a];
    ans = (ans * inv(f[b])) % MOD;
    ans = (ans * inv(f[a - b])) % MOD;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> x;
    ll ans = 0;
    dp[n][0] = 1;
    for (int i = n; i > 1; i--) {
        for (int j = 0; j < x; j++) {
            if (dp[i][j] == 0) continue;
            for (int k = i; k >= 0; k--) {
                int jj = min(x, j + i - 1);
                dp[k][jj] = (dp[k][jj] + ((dp[i][j] * c(i, k)) % MOD * power(jj - j, i - k)) % MOD) % MOD;
            }
        }
    }
    for (int j = 0; j <= x; j++) {
        ans = (ans + dp[0][j]) % MOD;
    }
    cout << ans << "\n";
}