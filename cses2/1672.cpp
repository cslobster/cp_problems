#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 503;

int n, m, q;
ll d[MXN][MXN];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = 1e18;
        }
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll dist = d[i][k] + d[k][j];
                if (dist < d[i][j]) {
                    d[i][j] = d[j][i] = dist;
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << ((d[a][b] == 1e18) ? -1 : d[a][b]) << endl;
    }
}