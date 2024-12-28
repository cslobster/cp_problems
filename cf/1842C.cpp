#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
int a[MXN];
int dp[MXN];
map<int, int> mp;

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[i] = 0x3f3f3f3f;
        }
        dp[0] = 0, mp[a[0]] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i - 1] + 1, mp[a[i]]);
            mp[a[i]] = min(mp[a[i]], dp[i - 1]);
        }
        cout << n - dp[n] << endl;
    }

}