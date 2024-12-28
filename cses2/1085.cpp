#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

ll n, k;
ll x[MXN];

bool check(ll mx) {
    ll cnt = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + x[i] > mx) {
            cur = 0;
            cnt++;
            if (cnt > k) return false;
        }
        cur += x[i];
        if (cur > mx) return false;
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
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