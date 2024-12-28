#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, a, b;
ll x[MXN], pre[MXN];

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> x[i];
    pre[0] = x[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + x[i];
    multiset<ll> s;
    s.insert(0);
    ll sz = b - a + 1, ans = -LLONG_MAX;
    ans = max(ans, pre[a - 1] - *s.begin());
    for (int i = 0; i + a < n; i++) {
        if (i == sz - 1) s.erase(s.find(0));
        if (i >= sz) {
            s.erase(s.find(pre[i - sz]));
        }
        s.insert(pre[i]);
            // j from i to sz, meaning i = i + a
        ans = max(ans, pre[i + a] - *s.begin());
    }
    cout << ans << endl;
}