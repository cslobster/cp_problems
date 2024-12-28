#include <bits/stdc++.h>
using namespace std;

const int MXN = 753;

int n;
int p[MXN][MXN], g[MXN][MXN];
int ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        string s; cin >> s;
        for (int j = i + 1, ind = 0; j <= n; j++, ind++) {
            p[i][j] = s[ind] - '0';
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            // from i to j
            g[i][j] = 0;
            for (int k = i + 1; k < j; k++) {
                g[i][j] += p[i][k] * g[k][j];
                g[i][j] %= 2;
            }
            if (g[i][j] != p[i][j]) {
                g[i][j] = 1;
                ans++;
                // g[i][j] = 1 - g[i][j];
            } else {
                g[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
}