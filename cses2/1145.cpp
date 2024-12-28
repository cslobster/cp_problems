#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
int x[MXN], dp[MXN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    dp[0] = -0x3f3f3f3f;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = n;
        while (l != r) {
            int mid = (l + r + 1)/2;
            if (dp[mid] < x[i]) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        // l is the biggest l such that dp[l] < x[i] < dp[l + 1]
        // now you update dp[l + 1]
        if (l + 1 <= n && x[i] < dp[l + 1]) {
            dp[l + 1] = x[i];
        }
        if (dp[l + 1] != 0x3f3f3f3f) ans = max(ans, l + 1);
    }
    cout << ans << endl;
}