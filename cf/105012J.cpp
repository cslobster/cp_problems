#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3;

int n;
ll a[MXN];
vector<int> adj[MXN];
pair<ll, ll> dp[MXN][2];
ll ans[MXN];
ll res = 0;

ll f(ll a, ll b) {
    ll p1 = max(a, b);
    ll p2 = sqrtl(min(a, b));
    return p1 + p2;
}

void dfs(int node, int par) {
    dp[node][0] = dp[node][1] = {a[node], node};
    for (auto ch : adj[node]) {
        if (ch != par) {
            dfs(ch, node);
            ll temp = f(dp[ch][0].first, a[node]);
            if (temp >= dp[node][0].first) {
                dp[node][1] = dp[node][0];
                dp[node][0] = {temp, ch};
            } else if (temp > dp[node][1].first) {
                dp[node][1] = {temp, ch};
            }
        }
    }
}

void dfs2(int node, int par) {
    ans[node] = max(ans[node], a[node]);
    res = max({res, dp[node][0].first, ans[node]});
    for (auto ch : adj[node]) {
        if (ch != par) {
            ans[ch] = max(ans[ch], f(ans[node], a[ch]));
            if (dp[node][0].second != ch) {
                ans[ch] = max(ans[ch], f(dp[node][0].first, a[ch]));
            } else {
                ans[ch] = max(ans[ch], f(dp[node][1].first, a[ch]));
            }
            dfs2(ch, node);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << res << endl;
}