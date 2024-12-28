#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3, MOD = 1e9 + 7;

ll ans[MXN], two[MXN];

int main() {
    two[0] = 1;
    for (int i = 1; i < MXN; i++) {
        two[i] = (two[i - 1] * 2) % MOD;
        ans[i] = two[i - 1] - two[i / 2];
        ans[i] = (ans[i] + MOD) % MOD;
        ans[i] = (ans[i] + ans[i - 1]) % MOD;
    }
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        l--;
        cout << (ans[r] - ans[l] + MOD) % MOD << endl;
    }
}