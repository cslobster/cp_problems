#include <bits/stdc++.h>
using namespace std;

const int MX = 17;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int primes[17] = {2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59};

    vector<vector<int>> dp(n, vector<int>(1 << MX, 0x3f3f3f3f));
    vector<vector<int>> b(n, vector<int>(1 << MX));
    vector<int> z(1 << MX, 0);
    dp[0] = z;
    vector<int> f(61);
    for (int i = 0; i < 61; i++) {
        for (int j = 0; j < 17; j++) {
            if (i % primes[j] == 0) {
                f[i] += (1 << j);
            }
        }
    }
    // 1110001010
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= 20; k++) {
            int x = (~f[k]) & ((1 << MX) - 1);
            for (int s = x; s >= 0; s = ((s - 1) & x)) {
                int temp = dp[i - 1][s] + abs(a[i] - k);
                if (temp <= dp[i][s | f[k]]) {
                    dp[i][s | f[k]] = min(dp[i][s | f[k]], temp);
                    b[i][s | f[k]] = k;
                }
                if (s == 0) break;
            }
        }
    }
    vector<int> ans;
    for (int i = n - 1, m = (1 << MX) - 1; i >= 0; i--) {
        int cur = b[i][m];
        ans.push_back(cur);
        m ^= f[cur];
    }
    reverse(ans.begin(), ans.end());
//    cout << dp[n - 1][(1 << MX) - 1] << endl;
    for (auto e : ans) {
        cout << e << endl;
    }
}