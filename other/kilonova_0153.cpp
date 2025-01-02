#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2003;

int n, k;
ll a[MXN];
ll dp[MXN][MXN][3];
// 0 is infected, 1 is wants to disinfect but has not reached a 0, 2 is has reached 0 & disinfect

void reset() {
    for (int i = 0; i < MXN; i++) {
        for (int j = 0; j < MXN; j++) {
            for (int l = 0; l < 3; l++) {
                dp[i][j][l] = 1e18;
            }
        }
    }
}


int main() {
    ifstream cin("antivirus.in");
    ofstream cout("antivirus.out");
    int t; cin >> t;
    while (t--) {
        reset();
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (a[0] == 0) {
            dp[0][1][2] = 0;
        } else {
            dp[0][1][1] = a[0];
            dp[0][0][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (a[i] == 0) {
                    if (j) dp[i][j][2] = min({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]});
                } else {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][2]);
                    if (j) dp[i][j][1] = min(dp[i - 1][j - 1][0] + a[i], dp[i - 1][j - 1][1] + a[i]);
                    if (j) dp[i][j][2] = dp[i - 1][j - 1][2] + a[i];
                }
            }
        }
        cout << min(dp[n - 1][k][0], dp[n - 1][k][2]) << endl;
    }
}