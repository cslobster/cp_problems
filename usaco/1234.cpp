#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003, MOD = 1e9 + 7;

int n, t;
int dp[MXN][MXN][2];

void add(int &a, int b) {
    a += b;
    a %= MOD;
}

int main() {
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        string xx, yy, b, e;
        cin >> xx >> yy;
        for (int i = 0; i < n; i++) {
            if (xx[i] == '1') continue;
            if (xx[i] == '0') b = "";
            if (xx[i] != '+') b += '2';
            else b += '+';
        }
        for (int i = 0; i < n; i++) {
            if (yy[i] == '1') continue;
            if (yy[i] == '0') e = "";
            if (yy[i] != '+') e += '2';
            else e += '+';
        }
        b = " " + b, e = " " + e;
        dp[0][0][0] = 1;
        for (int i = 0; i < e.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (i + 1 <= e.size()) {
                    if (e[i + 1] != b[j]) add(dp[i + 1][j][1], dp[i][j][0]);
                    add(dp[i + 1][j][1], dp[i][j][1]);
                }
                if (j + 1 <= b.size()) {
                    add(dp[i][j + 1][0], dp[i][j][0]);
                    add(dp[i][j + 1][0], dp[i][j][1]);
                }
                // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;

            }
        }
        cout << (dp[e.size() - 1][b.size() - 1][1] + dp[e.size() - 1][b.size() - 1][0]) % MOD << endl;
    }
}