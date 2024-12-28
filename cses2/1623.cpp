#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    ll total = accumulate(p.begin(), p.end(), 0LL);
    ll ans = total;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += p[i];
            }
        }
        ll other = total - sum;
        assert(total >= sum);
        ans = min(ans, abs(sum - other));
    }
    cout << ans << endl;
}