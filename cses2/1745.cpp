#include <bits/stdc++.h>
using namespace std;

const int MXN = 103, MXW = 1e5 + 3;

int n;
int x[MXN];
bool dp[MXW];

int main() {
    memset(dp, false, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    dp[0] = true;
    set<int> ans;
    for (int i = 0; i < n; i++) {
        for (int w = MXW - 1; w >= x[i]; w--) {
            dp[w] = dp[w] || dp[w - x[i]];
            if (dp[w]) ans.insert(w);
        }
    }
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e << " ";
    }
}