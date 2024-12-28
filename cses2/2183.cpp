#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
ll x[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans < x[i]) {
            cout << ans; return 0;
        }
        ans += x[i];
    }
    cout << ans << endl;
}