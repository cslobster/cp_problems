#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXM = 10005;

int n;
int a[MXN], b[MXN];
bool dp[MXN][MXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cin >> b[j];
    int sumMin = 0, sumMax = 0, sumSq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        sumSq += a[i] * a[i] + b[i] * b[i];
        sumMin += a[i];
        sumMax += b[i];
    }
    bitset<MXM> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp |= dp << (b[i] - a[i]);
    }
    int ans = sumMin * sumMin + sumMax * sumMax;
    for (int i = 0; i <= sumMax - sumMin; i++) {
        if (dp[i]) {
            ans = min(ans, (sumMin + i) * (sumMin + i) + (sumMax - i) * (sumMax - i));
        }
    }
    cout << sumSq * (n - 2) + ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}