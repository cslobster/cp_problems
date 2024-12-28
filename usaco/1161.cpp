#include <bits/stdc++.h>
using namespace std;

int t, n, k;


struct Cow {
    int x, y;
    Cow(int a, int b) {
        x = a, y = b;
    }
};

bool operator<(const Cow &a, const Cow &b) {
    return a.x < b.x;
}

int calc_min(vector<Cow> &chain) {
    int ans = 1e9;
    for (int i = 0; i < chain.size(); i++) {
        if (i % 2 == 0 || chain[i + 1].x - chain[i - 1].x <= k) {
            ans = min(ans, chain[i].y);
        }
    }
    return ans;
}

int calc_max(vector<Cow> &chain) {
    if (chain.size() == 0) return 0;
    vector<pair<int, int>> dp(chain.size() + 1);
    dp[chain.size()] = {0, -1e9};
    for (int i = chain.size() - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        Cow c(chain[i].x + k, 1e9);
        int it = upper_bound(chain.begin(), chain.end(), c) - chain.begin();
        if (i == 0 || i == chain.size() - 1 || chain[i + 1].x - chain[i - 1].x <= k || !(chain.size() - i & 1))
            dp[i].first = max(dp[i].first, dp[it].second + chain[i].y);
        if (i == 0 || i == chain.size() - 1 || chain[i + 1].x - chain[i - 1].x <= k || (chain.size() - i & 1))
            dp[i].second = max(dp[i].second, dp[it].first + chain[i].y);
    }
    return (chain.size() & 1 ? dp[0].second : dp[0].first);
}

int main() {
    // ifstream cin("in.in");
    // ofstream cout("out.out");
    cin >> t >> n >> k;
    vector<Cow> cows;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cows.push_back({a, b});
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    vector<Cow> chain;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i].x - pre > k) {
            if (t == 1) {
                if (chain.size() & 1) ans += calc_min(chain);
            }
            else ans += calc_max(chain);
            chain.clear();
        }
        chain.push_back(cows[i]);
        pre = cows[i].x;

    }
    if (t == 1) {
        if (chain.size() & 1) ans += calc_min(chain);
    }
    else ans += calc_max(chain);
    cout << ans << endl;
}