#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e6 + 3;

int n;
vector<int> adj[MXN];
ll sz[MXN], ans[MXN];
bitset<MXN> dp;

void processItem(ll sum2, ll v, ll &mx) {
    for (ll w = sum2; w >= v; w--) {
        if (dp[w - v]) dp[w] = true;
        if (dp[w] && abs(w - sum2) < abs(mx - sum2)) mx = w;
    }
}

void dfs(int node, int par) {
    sz[node] = 1;
    if (adj[node].size() == 1 && node != 1) {
        ans[node] = 0;
        return;
    }
    ll cur = 0;
    map<ll, ll> vals;
    vector<ll> items;
    ll mx = 0;
    for (auto ch : adj[node]) {
        if (ch == par) continue;
        dfs(ch, node);
        sz[node] += sz[ch];
        cur += ans[ch];
        mx = max(sz[ch], mx);
        vals[sz[ch]]++;
    }
    ll sum = sz[node] - 1, sum2 = sum / 2;
    if (mx >= sum2) {
        cur += 1LL * mx * (sum - mx);
        ans[node] = cur;
        return;
    }
    mx = 0;
    dp[0] = true;
    for (auto v : vals) {
        int pw = 1;
        while (v.second > pw) {
            v.second -= pw;
            processItem(sum2, pw * v.first, mx);
            pw *= 2;
        }
        if (v.second != 0) processItem(sum2, v.first * v.second, mx);
    }

    for (ll w = sum2; w >= 0; w--) {
        dp[w] = false;
    }

    cur += mx * (sum - mx);
    ans[node] = cur;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int node = 2; node <= n; node++) {
        int a; cin >> a;
        adj[node].push_back(a);
        adj[a].push_back(node);
    }

    dfs(1, -1);
    cout << ans[1] << "\n";
}