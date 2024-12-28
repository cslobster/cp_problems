#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3, MOD = 1e9 + 7;

int n;
string s;
ll dp[MXN];

void add(ll &a, ll &b) {
    a += b;
    a %= MOD;
}

int main() {
    memset(dp, 0, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'X') dp[i] = dp[i + 1];
        for (int len = 1; len <= (n - i + 1) / 2; len++) {
            bool flag = true;
            for (int j = 0; j < len; j++) {
                if (i + j >= n || s[i + j] == 'B' || i + j + len >= n || s[i + j + len] == 'R') {
                    flag = false; break;
                }
            }
            if (flag) add(dp[i], dp[i + 2 * len]);
        }
    }
    cout << dp[0] << endl;
}