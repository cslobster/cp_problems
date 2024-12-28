#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 3;

int n;
int a[MXN], powsOf2UnderN[MXN];

void init() {
    powsOf2UnderN[0] = 0;
    for (int i = 1; i < MXN; i++) {
        int cnt = __builtin_ctz(i & -i);
        powsOf2UnderN[i] = powsOf2UnderN[i - 1] + cnt;
    }
}

int checkOdd(int m, int k) {
    assert(m >= k);
    int ans = powsOf2UnderN[m];
    ans -= powsOf2UnderN[k];
    ans -= powsOf2UnderN[m - k];
    assert(ans >= 0);
    if (ans == 0) return 1;
    return 0;
}

int main() {
    init();
    // for (int n = 1; n <= 8; n++) {
    //     for (int k = 0; k <= n; k++) {
    //         cout << checkOdd(n, k) << ' ';
    //     }
    //     cout << endl;
    // }
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // n - 1 choose i mod 2 = check parity(n - 1, i)
        if (checkOdd(n - 1, i)) {
            ans ^= a[i];
        }
    }
    cout << ans << endl;
}