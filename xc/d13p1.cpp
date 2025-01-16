/*
 * for how many (i, j) where i <= n and j <= m are there so that c(j, i) is divisible by k
 * basically precalculate combinations w triangle and 2d prefix sum it
 * don't know why, calculating # of powers in each factorial to do combinations didn't work
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2006;

int n, k;
ll a[MXN], works[MXN][MXN], works2[MXN][MXN], pre[MXN][MXN], c[MXN][MXN];

void init() {
    for (int i = 0; i < MXN; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i][j] + c[i - 1][j]) % k;
            c[i][j] = (c[i][j] + c[i - 1][j - 1]) % k;
        }
    }
}

int main() {
    int t; cin >> t >> k;
    init();
    for (int i = 0; i < MXN; i++) {
        int cnt = 0, num = i;
        while (num) {
            cnt += num / k;
            num /= k;
        }
        a[i] = cnt;
        // cout << i << " " << cnt << endl;
    }
    for (int i = 0; i < MXN; i++) {
        for (int j = 0; j < MXN; j++) {
            if (j >= i) works[i][j] = ((a[j] - a[i] - a[j - i]) > 0);
            else works[i][j] = 0;
            if (j >= i) works2[i][j] = (c[j][i] == 0);
            else works2[i][j] = 0;
            pre[i][j] = works2[i][j];
            if (i >= 1) pre[i][j] += pre[i - 1][j];
            if (j >= 1) pre[i][j] += pre[i][j - 1];
            if (i >= 1 && j >= 1) pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b][a] << endl;
    }
}