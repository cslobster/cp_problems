#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
ll p[MXN], pre[MXN];

int main() {
    cin >> n;
    ll sum = 0;
    if (n == 1) {
        cout << 0; return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    sort(p, p + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = p[i];
        if (i - 1) pre[i] += pre[i - 1];
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i < n; i++) {
        ll x;
        if (2 * i > n) {
            // min x
            x = p[i];
        } else {
            // max x
            x = p[i + 1];
        }
        ans = min(ans, sum - 2 * pre[i] - (n - 2 * i) * x);
    }
    cout << ans << endl;
}