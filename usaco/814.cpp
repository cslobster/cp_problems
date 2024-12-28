#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, cnt = 0;
vector<vector<int>> adj;
vector<int> dp, h, sz;
vector<bool> leaf;
vector<string> items;
map<string, int> ind;
vector<int> cost;

void dfs(int node, int p) {
    for (auto c : adj[node]) {
        if (c != p) {
            h[c] = h[node] + cost[c];
            if (leaf[c]) dp[1] += h[c];
            dfs(c, node);
            sz[node] += sz[c];
        }
    }
}

void dfs2(int node, int p) {
    for (auto c : adj[node]) {
        if (c != p) {
            dp[c] = dp[node] + (sz[1] - sz[c]) * 3 - sz[c] * cost[c];
            dfs2(c, node);
        }
    }
}

signed main() {
    ifstream cin("dirtraverse.in");
    ofstream cout("dirtraverse.out");
    cin >> n;
    adj.resize(n + 1);
    h.resize(n + 1);
    dp.resize(n + 1);
    sz.resize(n + 1);
    leaf.resize(n + 1);
    items.resize(n + 1);
    cost.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        string s; int m;
        cin >> s >> m;
        items[i] = s;
        cost[i] = items[i].size() + 1;
        ind[s] = i;
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            adj[i].push_back(a);
        }
        if (m == 0) {
            leaf[i] = true;
            sz[i] = 1;
            cost[i]--;
        }
    }
    dfs(1, -1);
    dfs2(1, -1);
    int ans = dp[1];
    for (int i = 1; i <= n; i++) {
        if (!leaf[i]) ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}