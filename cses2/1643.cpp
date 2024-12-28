#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
ll a[MXN];

int main() {
    cin >> n;
    ll ans = -1e9, cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; ans = max(ans, a[i]);
        if (cur + a[i] < 0) {
            cur = max(0LL, a[i]);
            if (cur != 0) ans = max(ans, cur);
            continue;
        }
        cur += a[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
}