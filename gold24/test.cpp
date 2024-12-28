#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXn = 5e5 + 3, MOD = 1e9 + 7;

void add(ll &a, ll &b) {
    a += b;
    a %= MOD;
}

int n;
string s;
ll dp[MXn], r[MXn], b[MXn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0, sizeof(dp));
    memset(r, 0, sizeof(r));
    memset(b, 0, sizeof(b));
    cin >> n >> s;
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int len = 1; i + 2 * len <= n; len++) {
            bool flag = true;
            for(int j = i; j < i + len; j++) {
                if(s[j] == 'B') {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            for (int j = i + len; j < i + 2 * len; j++) {
                if (s[j] == 'R') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dp[i] = (dp[i] + dp[i + 2 * len]) % MOD;
            }
        }
        if (s[i] == 'X') {
            add(dp[i], dp[i + 1]);
        }
    }
    cout <<  dp[0] << endl;
}
