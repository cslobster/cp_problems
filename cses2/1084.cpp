#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, m, k;
int a[MXN], b[MXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && b[j] < a[i] - k) {
            j++;
        }
        if (j >= m) break;
        if (b[j] > a[i] + k) continue;
        ans++;
        j++;
    }
    cout << ans << endl;
}