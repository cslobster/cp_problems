#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3;

int n;
ll a[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    // after m minutes
    for (int m = 1; m <= n; m++) {
        ll a0 = a[0], sum = 0;
        for (int i = 0; i < n - 1; i++) {
            a[i] = min(a[i], a[i + 1]);
            sum += a[i];
        }
        a[n - 1] = min(a[n - 1], a0);
        sum += a[n - 1];
        cout << sum << endl;
    }
}