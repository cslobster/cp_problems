#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, t;
ll k[MXN];

bool check(ll time) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += time / k[i];
        if (cnt >= t) return true;
    }
    return false;
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> k[i];
    ll l = 0;
    ll r = 1e18;
    while (l != r) {
        ll mid = (l + r)/2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}