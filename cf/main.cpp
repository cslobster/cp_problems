#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
vector<int> adj[MX];
vector<pair<int, int>> ans;
int st[MX], low[MX];
int t = 0;
bool vis[MX];

void dfs(int node, int par) {
    vis[node] = true;
    low[node] = st[node] = t++;
    for (auto ch : adj[node]) {
        if (ch == par) continue;
        if (vis[ch]) {
            low[node] = min(low[node], st[ch]);
        } else {
            dfs(ch, node);
            low[node] = min(low[node], low[ch]);
            if (low[ch] > st[ch]) ans.push_back({node, ch});
        }
    }
}

void solve(int i) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vis[i] = false, st[i] = 0, low[i] = MX;
        adj[i].clear();
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
        int node; cin >> node;
        int cnt; cin >> cnt;
        while (cnt--) {
            int ch; cin >> ch;
            adj[node].push_back(ch);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i, -1);
    }
    cout << "Case " << i + 1 << "\n";
    cout << ans.size() << " critical links\n";
    for (auto &[u, v] : ans) {
        if (u > v) swap(u, v);
        cout << u << " - " << v << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
}