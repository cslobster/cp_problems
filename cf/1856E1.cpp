#include <bits/stdc++.h>
using namespace std;

const int MXN = 5003;

int n;
vector<int> adj[MXN];
int sz[MXN], ans[MXN];
bool dp[MXN];
vector<int> in;

void dfs(int node, int par) {
    sz[node] = 1;
    if (adj[node].size() == 1 && node != 1) {
        ans[node] = 0;
        return;
    }
    int cur = 0, sum = 0, sum2 = 0;
    vector<int> vals;
    for (auto ch : adj[node]) {
        if (ch == par) continue;
        dfs(ch, node);
        sz[node] += sz[ch];
        cur += ans[ch];
        vals.push_back(sz[ch]);
        sum += sz[ch];
    }
    int mx = 0;
    dp[0] = true;
    sum2 = sum / 2;
    for (auto v : vals) {
        for (int w = sum; w >= v; w--) {
            dp[w] |= dp[w - v];
            if (dp[w] && abs(w - sum2) < abs(mx - sum2)) mx = w;
        }
    }
    for (int w = sum; w >= 0; w--) {
        dp[w] = false;
    }

    cur += mx * (sum - mx);
    ans[node] = cur;

}

int main() {
    cin >> n;
    for (int node = 2; node <= n; node++) {
        int a; cin >> a;
        in.push_back(a);
        adj[node].push_back(a);
        adj[a].push_back(node);
    }

    dfs(1, -1);
    cout << ans[1] << endl;
}