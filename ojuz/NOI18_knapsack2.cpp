#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> dp(s + 1, INT_MIN);
    map<int, vector<pair<int, int>>> items;
    for (int i = 0; i < n; i++) {
        int v, w, k;
        cin >> v >> w >> k;
        items[w].push_back({v, k});
    }
    int ans = 0;
    dp[0] = 0;
    for (auto &[w, a] : items) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (int c = s; c >= 0; c--) {
            int i = 0, tot = 0, used = 0, gained = 0;
            while ((tot + 1) * w <= c && i < a.size()) {
                tot++;
                gained += a[i].first;
                if (dp[c - w * tot] != INT_MIN) {
                    dp[c] = max(dp[c], dp[c - w * tot] + gained);
                    ans = max(ans, dp[c]);
                }
                used++;
                if (used == a[i].second) {
                    i++;
                    used = 0;
                }
            }
        }
    }
    cout << ans << endl;
}