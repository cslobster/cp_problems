#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 20, MXB = (1 << MXN);

int n, q;
int pref[MXN][MXN];
int lim[MXN];
vector<int> masks[MXN + 1];
ll dp[MXB][MXN];
ll ans[MXB];

int main() {

    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    int bitMax = (1 << n);
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            a--;
            pref[i][a] = flag;
            if (a == i) {
                flag = false;
            }
        }
    }
    cin >> q;
    ans[0] = 1;
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 1 << i; mask < 1 << (i + 1); mask++) {
            for (int j = 0; j <= i; j++) {
                if (!(mask & (1 << j))) continue;
                 for (int k = 0; k < i; k++) {
                     if (!(mask & (1 << k)) && pref[j][k]) {
                         dp[mask ^ (1 << k)][k] += dp[mask][j];
                     }
                 }
                if (pref[j][i]) {
                   ans[mask] += dp[mask][j];
                }
            }
            for (int k = i + 1; k < n; k++) {
                dp[mask ^ (1 << k)][k] += ans[mask];
            }
        }
    }
    while (q--) {
        string b;
        cin >> b;
        int h = 0, g = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 'H') h ^= 1 << i;
            else g ^= 1 << i;
        }
        // cout << ans[g] << " " << ans[h] << endl;

        cout << ans[h] * ans[g] << endl;
    }
}