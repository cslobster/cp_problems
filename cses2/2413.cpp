#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e6 + 3, MOD = 1e9 + 7;

int n;
ll dp[2][MXN], dpsq[MXN];

void add(ll &a, ll b) {
    a += b;
    a %= MOD;
}

void mult(ll &a, ll b) {
    a *= b;
    a %= MOD;
}

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) mult(ans, a);
        mult(a, a);
        b /= 2;
    }
    return ans;
}

int main() {
    for (int i = 1; i < MXN; i++) {
        dpsq[i] = power(2, i + 1);
        if (i < 10) cout << dpsq[i] << endl;
    }
    dp[0][0] = 1, dp[1][0] = 1;
    ll sum4 = 1, totSum = 0; // sum of all dp[1][i]s so far
    for (int i = 1; i < 7; i++) {
        // if (i == 1) {
        //     dp[0][i] = 1, dp[1][i] = 1;
        //     sum4 = 1, totSum = 2;
        //     continue;
        // }
        add(dp[0][i], totSum + 1);
        add(dp[1][i], sum4);
        mult(sum4, 4);
        add(sum4, dp[0][i]);
        add(totSum, dp[1][i]);
        add(totSum, dp[0][i]);
        cout << i << " " << sum4 << " " << dp[0][i] << endl;
    }
    cout << dp[0][6] + dp[1][6] << endl;
}