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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= i - 1; k++) {
                for (int l = 0; l <= j - 1; l++) {
                    if (checkAverage(k + 1, i, l + 1, j)) {
                        // cout << "added " << dp[i][j] << " or " << i << " " << j << " to " << k << " " << l << "\t cur ans is: " << dp[n][n] << endl;
                        dp[i][j] += dp[k][l];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}