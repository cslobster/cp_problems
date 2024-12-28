#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sqsum(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");
    int n;
    cin >> n;
    vector<int> c(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cnt = max(0, cnt + c[i] - 1);
    }

    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            rotate(c.begin(), c.begin() + i, c.begin() + n);
            break;
        }
        cnt = max(0, cnt + c[i] - 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqsum(c[i] + cnt - 1) - sqsum(cnt - 1);
        cnt = max(0, cnt + c[i] - 1);
    }
    cout << ans << endl;
}
