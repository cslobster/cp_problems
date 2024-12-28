#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MXN = 503, MOD = 1e9 + 7;

int n;
ll a[MXN], b[MXN], preA[MXN], preB[MXN];
vector<int> orderI[MXN], orderJ[MXN];
ll dp[MXN][MXN], preDP[MXN][MXN];
int ii;

bool checkAverage(int i, int k, int j, int l) {
    ll sumA = preA[k] - preA[i];
    ll sumB = preB[l] - preB[j];
    ll szA = k - i;
    ll szB = l - j;
    return sumA * szB <= sumB * szA;
}

bool checkAverage2(int i, int j) {
    ll sumA = preA[ii] - preA[i];
    ll sumB = preA[ii] - preA[j];
    ll szA = ii - i;
    ll szB = ii - j;
    return sumA * szB < sumB * szA;
}

bool checkAverage3(int i, int j) {
    ll sumA = preB[ii] - preB[i];
    ll sumB = preB[ii] - preB[j];
    ll szA = ii - i;
    ll szB = ii - j;
    return sumA * szB < sumB * szA;
}

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    preA[0] = 0, preB[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preA[i] = a[i] + preA[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        // cout << b[i] << " " << preB[i - 1] << endl;
        preB[i] = b[i] + preB[i - 1];
    }
    for (ii = 1; ii <= n; ii++) {
        orderI[ii].resize(0);
        orderJ[ii].resize(0);
        for (int xx = 0; xx < ii; xx++) {
            orderI[ii].push_back(xx);
            orderJ[ii].push_back(xx);
        }
        sort(orderI[ii].begin(), orderI[ii].end(), [](const int a, const int b) {
            return checkAverage2(a, b);
        });
        sort(orderJ[ii].begin(), orderJ[ii].end(), [](const int a, const int b) {
        return checkAverage3(a, b);
        });
    }
    // return 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < i; r++) {
            for (int j = 0; j <= n; j++) {
                preDP[r][j] = dp[orderI[i][r]][j];
                if (r) preDP[r][j] += preDP[r - 1][j];
                preDP[r][j] %= MOD;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l <= j - 1; l++) {
                int left = 0;
                int right = i - 1;
                while (left != right) {
                    int mid = (left + right + 1) / 2;
                    if (checkAverage(orderI[i][mid], i, l, j)) {
                        left = mid;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                // for (int x = 0; x <= left; x++) {
                //     int k = orderI[i][x];
                //     if (checkAverage(k, i, l, j)) {
                //         dp[i][j] += dp[k][l];
                //         dp[i][j] %= MOD;
                //         // cout << "added " << dp[k][l] << " or " << k << " " << l << " to " << i << " " << j << " to get: " << dp[i][j] << "\t cur ans is: " << dp[n][n] << endl;
                //     }
                // }
                if (checkAverage(orderI[i][left], i, l, j)) {
                    dp[i][j] += preDP[left][l];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}