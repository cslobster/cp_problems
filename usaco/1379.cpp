#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
ll a[MXN];

ll sum(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

void clear() {
    memset(a, 0, sizeof(a));
}

bool check(int b) {
    if (b == n) return true;
    int bCount = 0;
    for (int i = 0; i + 1 < n; i++) {
        while (bCount < b && sum(b - bCount, b) <= a[i]) {
            bCount++; // add this element to bessie's pile
        }
        if (i + 1 - bCount == n - b) {
            return true;
        }
    }
    return false;
}

void solve() {
    clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int l = 0;
    int r = n;
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << min(sum(1, l), a[n - 1]) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}