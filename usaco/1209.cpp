#include <bits/stdc++.h>
using namespace std;

const int MXN = 18, MXB = (1 << 18);

int n, q;
int pref[MXN][MXN];
int lim[MXN];
vector<int> masks[MXN + 1];
int dp[1 << MXN];

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    int bitMax = (1 << n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pref[i][j];
            pref[i][j]--;
            if (pref[i][j] == i) lim[i] = j;
        }
    }
    cin >> q;
    for (int i = 0; i < bitMax; i++) {
        int cnt = __builtin_popcount(i);
        masks[cnt].push_back(i);
    }
    for (int x = 0; x < q; x++) {
        string b; cin >> b;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (auto mask : masks[i + 1]) {
                for (int k = 0; k <= lim[i]; k++) {
                    int j = pref[i][k];
                    if ((mask & (1 << j)) && b[i] == b[j]) {
                        int old_mask = mask - (1 << j);
                        dp[mask] += dp[old_mask];
                    }
                }
            }
        }
        cout << dp[bitMax - 1] << endl;
    }
}