#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
int n, m, k;
vector<int> adj[MX], xx;
int cnt[MX], h[MX], ans[MX], rem[MX], lc[MX], sz[MX];
unordered_map<int, int> s[MX];
vector<pair<int, int>> edges;

void merge(unordered_map<int, int> &a, unordered_map<int, int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto e : b) a[e.first] += e.second;
}

void dfs0(int node, int par) {
    sz[node] = 1;
    for (auto ch : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            dfs0(ch, node);
            if (sz[ch] > sz[lc[node]]) lc[node] = ch;
            sz[node] += sz[ch];
        }
    }
}

void dfs(int node, int par) {
    if (adj[node].size() > 0) {
        dfs(lc[node], node);
        merge(s[node], s[lc[node]]);
    }
    for (auto ch : adj[node]) {
        if (ch != par && ch != lc[node]) {
            dfs(ch, node);
            merge(s[node], s[ch]);
        }
    }
    for (auto e : s[node]) {
        if (e.second == cnt[e.first]) rem[node]++;
    }
    if (s[node].size() - rem[node] >= k) ans[node] = 1;
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
            s[a][i]++;
        }
    }
    dfs0(1, 1);
    dfs(1, 1);
    vector<int> res;
    for (int i = 0; i < n - 1; i++) {
        auto &[a, b] = edges[i];
        if (h[a] < h[b]) swap(a, b);
        if (ans[a]) res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (auto e : res) cout << e << " ";
}