#include <bits/stdc++.h>
using namespace std;

const int MX = 5e4 + 2;

int n, m;
vector<pair<int, int>> adj[MX];
vector<array<int, 3>> roads;
int ans[MX], h[MX];
set<int> s[MX];
pair<int, int> xx[MX];

void merge(set<int> &a, set<int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto e : b) {
        if (a.count(e)) a.erase(e);
        else a.insert(e);
    }
}

void dfs(int node, int par) {
    for (auto &[ch, i] : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            dfs(ch, node);
            merge(s[node], s[ch]);
        }
    }
    if (s[node].size()) ans[node] = *s[node].begin();
    else ans[node] = -1;
}

int main() {
    ifstream cin("disrupt.in");
    ofstream cout("disrupt.out");
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        xx[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        s[a].insert(c);
        s[b].insert(c);
    }
    dfs(1, 1);
    for (int i = 0; i < n - 1; i++) {
        auto &[a, b] = xx[i];
        if (h[a] < h[b]) swap(a, b);
        cout << ans[a] << endl;
    }
}