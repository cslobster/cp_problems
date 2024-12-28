#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e6 + 3, MOD = 1e9 + 7;

int n;
ll dp[MXN][2];

void add(ll &a, ll b) {
    a += b;
    a %= MOD;
}

int main() {
    dp[0][0] = 1, dp[0][1] = 1;
    for (int i = 1; i < MXN; i++) {
        add( dp[i][0], dp[i - 1][0] * 4 + dp[i - 1][1]);
        add(dp[i][1], dp[i - 1][0] + dp[i - 1][1] * 2);
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n; n--;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
}