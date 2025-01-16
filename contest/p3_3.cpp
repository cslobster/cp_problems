#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e6 + 5, MXK = 101;

using ll = long long;

int n, kkkk, p;
ll a[MXN], b[MXN];

int cnt[MXN];

int main() {
    // ifstream cin("in.in");
    cin >> n >> kkkk >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) continue;
            bool flag = false;
            for (int k = i; k <= j; k++) {
                if (b[k] < p) {
                    flag = true;
                    // cout << i << " " << k << " " << j << endl;
                }
            }
            if (flag) ans++;
        }
    }
    cout << ans << endl;
}