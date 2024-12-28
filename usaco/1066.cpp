#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
const int MOD = 1e9 + 7;

using ll = long long;
int n;
vector<int> a;
ll dp[MX][5][4][4];

void add(ll &a, ll b) {
    a += b;
    a %= MOD;
}

int main() {
    string s; cin >> s;
    n = s.size();
    a.resize(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a[i] = 0;
        else if (s[i] == 'T') a[i] = 1;
        else if (s[i] == 'C') a[i] = 2;
        else if (s[i] == 'G') a[i] = 3;
        else a[i] = 4;
    }
    if (s[0] == '?') {
        for (int i = 0; i < 4; i++) {
            dp[0][4][i][i] = 1;
        }
    } else {
        dp[0][4][a[0]][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int l = 0; l < 4; l++) {
            if (a[i] != l && a[i] != 4) continue;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int m = 0; m < 5; m++) {
                        if (m != l && m != 4)
                            add(dp[i][j][k][l], dp[i - 1][j][k][m]);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    add(dp[i][j][l][l], dp[i - 1][k][j][k]);
                    add(dp[i][j][l][l], dp[i - 1][4][j][k]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            add(ans, dp[n - 1][i][j][i]);
            add(ans, dp[n - 1][4][j][i]);
        }
    }
    cout << ans % MOD << endl;
}