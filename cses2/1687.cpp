#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, MXD = 32;

int n, q;
int h[MXN];
int up[MXN][MXD];

void build() {
    for (int j = 1; j < MXD; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int lift(int a, int b) {
    for (int j = 0; j < MXD; j++) {
        if (b & (1 << j)) {
            a = up[a][j];
        }
    }
    return a;
}

int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) h[i] = -1;
    for (int i = 2; i <= n; i++) cin >> up[i][0];
    h[1] = 0;
    up[1][0] = 0;
    build();
    while (q--) {
        int a, b; cin >> a >> b;
        int c = lift(a, b);
        cout << ((c == 0) ? -1 : c) << endl;
    }
}