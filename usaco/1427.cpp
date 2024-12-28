#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503, MOD = 1e9 + 7;

int n;
ll a[MXN], b[MXN], preA[MXN], preB[MXN];
ll dp[MXN][MXN];

bool checkAverage(int i, int k, int j, int l) {
    assert(i > 0 && j > 0);
    ll sumA = preA[k] - preA[i - 1];
    ll sumB = preB[l] - preB[j - 1];
    ll szA = k - i + 1;
    ll szB = l - j + 1;
    return sumA * szB <= sumB * szA;
}

int main() {
    cin >> n;
    preA[0] = 0, preB[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preA[i] = a[i] + preA[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        preB[i] = b[i] + preB[i - 1];
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == 0) continue;
            for (int k = i + 1; k <= n; k++) {
                for (int l = j + 1; l <= n; l++) {
                    if (checkAverage(i + 1, k, j + 1, l)) {
                        // cout << "added " << dp[i][j] << " or " << i << " " << j << " to " << k << " " << l << "\t cur ans is: " << dp[n][n] << endl;
                        dp[k][l] += dp[i][j];
                        dp[k][l] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}