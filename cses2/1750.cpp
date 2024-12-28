#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, MXD = 32;

int n, q;
int p[MXN][MXD];

void build() {
    for (int j = 1; j < MXD; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int up(int a, int b) {
    for (int j = MXD - 1; j >= 0; j--) {
        if (b & (1 << j)) {
            a = p[a][j];
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> p[i][0];
    build();
    while (q--) {
        int a, b; cin >> a >> b;
        cout << up(a, b) << "\n";
    }
}