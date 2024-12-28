#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, x;
int p[MXN], paired[MXN];

int main() {
    memset(paired, 0, sizeof(paired));
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> p[i];
    int ans = 0;
    sort(p, p + n);
    int l = 0, r = n - 1;
    while (l < r) {
        while (p[l] + p[r] > x) {
            r--;
        }
        // pair these two
        ans++;
        paired[r] = 1;
        paired[l] = 1;
        r--;
        l++;
    }
    for (int i = 0; i < n; i++) {
        if (!paired[i]) ans++;
    }
    cout << ans << endl;
}