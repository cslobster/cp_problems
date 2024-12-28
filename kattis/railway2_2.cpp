#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
int n, m, k;
vector<int> adj[MX], xx, yy[MX];
int cnt[MX], h[MX], ans[MX];
set<int> s[MX];
vector<pair<int, int>> edges;

void merge(set<int> &a, set<int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto e : b) a.insert(e);
}

void dfs(int node, int par) {
    for (auto ch : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            dfs(ch, node);
            merge(s[node], s[ch]);
        }
    }
    for (auto e : yy[node]) {
        cnt[e]--;
        if (cnt[e] == 0) s[node].erase(e);
    }
    if (node != 1) ans[node] = s[node].size();
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        cnt[i] = c;
        while (c--) {
            int a; cin >> a;
            s[a].insert(i);
            yy[a].push_back(i);
        }
    }
    dfs(1, 1);
    vector<int> res;
    for (int i = 0; i < n - 1; i++) {
        auto &[a, b] = edges[i];
        if (h[a] < h[b]) swap(a, b);
        if (ans[a] >= k) res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (auto e : res) cout << e << " ";
}