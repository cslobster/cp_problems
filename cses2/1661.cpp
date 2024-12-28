#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, x;
ll a[MXN], pre[MXN];
map<ll, int> mp;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = a[i] + pre[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (mp.count(pre[i] - x)) {
            ans += mp[pre[i] - x];
        }
        mp[pre[i]]++;
    }
    cout << ans << endl;
}