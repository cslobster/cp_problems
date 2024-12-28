#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int pow(int a, int b) {
    int ans = 1;
    while (b >= 1) {
        if (b % 2 == 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}

int inv(int a) {
    return pow(a, MOD - 2);
}

signed main() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = ((ans * (i + n)) % MOD) % MOD;
        ans = (ans * inv(i)) % MOD;
    }
    cout << ans << endl;
}