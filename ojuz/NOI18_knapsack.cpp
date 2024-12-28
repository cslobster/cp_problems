#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>
using namespace std;

int dp[2001];

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> val, cost;

    for (int i = 0; i < n; i++) {
        int v, w, k;
        cin >> v >> w >> k;
        int j = log(k) / log(2);
        for (int x = 0; x < j; x++) {
            val.push_back(v << x);
            cost.push_back(w << x);
            k -= 1 << x;
        }
        if (k) {
            val.push_back(v * k);
            cost.push_back(w * k);
        }
    }
    // vector<int> dp(s + 1);
    int ans = 0;
    for (int i = 0; i < val.size(); i++) {
        // cout << val[i] << " " << cost[i] << endl;
        for (int w = s; w >= cost[i]; w--) {
            dp[w] = max(dp[w], dp[w - cost[i]] + val[i]);
            ans = max(ans, dp[w]);
        }
    }
    cout << ans << endl;
}