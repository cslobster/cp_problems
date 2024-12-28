#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
int x[MXN], y[MXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        y[x[i]] = i;
    }
    int ans = 0, prev = n + 1;
    for (int i = 1; i <= n; i++) {
        if (y[i] < prev) ans++;
        prev = y[i];
    }
    cout << ans << endl;
}