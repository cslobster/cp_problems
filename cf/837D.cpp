#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string.h>
using namespace std;

using ll = long long;
const int MX = 7000;

signed main() {
    // ifstream cin("text.in");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        // if (i == 26) {
        //     cout << "SDFDSF" << endl;
        // }
        ll num; cin >> num;
        ll x = num;
        while (x % 2 == 0) {
            a[i]++;
            x /= 2;
        }
        x = num;
        while (x % 5 == 0) {
            b[i]++;
            x /= 5;
        }
        // cout << i << endl/**/;
    }
    int dp[201][MX];
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < MX; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            for (int w = MX - 1; w >= b[i]; w--) {
                if (dp[j - 1][w - b[i]] != -1e9) {
                    dp[j][w] = max(dp[j][w], dp[j - 1][w - b[i]] + a[i]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MX; i++) {
        ans = max(ans, min(dp[k][i], i));
        if (ans > 5) {
            // cout << "SDFSDF" << endl;
        }
    }
    cout << ans << "\n";
}