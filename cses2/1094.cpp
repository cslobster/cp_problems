#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i) {
            if (x[i] >= x[i - 1]) continue;
            ans += x[i - 1] - x[i];
            x[i] = x[i - 1];
        }
    }
    cout << ans << endl;
}