#include <bits/stdc++.h>
using namespace std;

const int MXN = 20, MXM = 1 << 20;
int t, n;

bool dp[3 * MXN + 1][MXM];

int mv[3 * MXN + 1][MXN];

int convert(string a) {
    int out = 0;
    for (int i = 0; i < n; i++) {
        out ^= (a[i] - '0') << i;
    }
    return out;
}

int cyc(int a) {
    a <<= 1;
    if (a & (1 << n)) {
      a ^= (1 << n) ^ 1;
    }
    return a;
}

int main() {
    cin >> t >> n;
    dp[0][0] = true;

    for (int i = 1; i <= 3 * n; i++) {
        for (int j = 0; j < n; j++) {
            mv[i][j] = (1 << j) ^ mv[i - 1][(j + 1) % n];
        }
    }

    for (int i = 1; i <= 3 * n; i++) {
        for (int mask = 0; mask < MXM; mask++) {
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][mask ^ mv[i][j]]) dp[i][mask] = true;
            }
        }
    }

    while (t--) {
        string c, d;
        cin >> c >> d;
        int a = convert(c), b = convert(d);

        int cur = 0;
        bool solved = false;
        for (int i = 0; i <= 3 * n; i++) {
            if (dp[i][cur ^ a]) {
                cout << i << endl;
                solved = true;
                break;
            }
            cur ^= b;
            b = cyc(b);
        }
        if (solved) continue;
        cout << -1 << endl;
    }
}