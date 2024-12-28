#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2, MXQ = 2e5 + 2;

int n, q;
vector<int> adj[MX];
int ans[MX], active[MX], vis[MX], which[MX], rel[MX], edge_active[MXQ];
array<int, 3> queries[MXQ];
vector<array<int, 2>> edges;
set<array<int, 2>> edges_set;
vector<vector<int>> comps;
int id = 0;

void dfs(int node, int t, int par=-1) {
    if (ans[node] == 0) {
        ans[node] = t;
        for (auto ch : adj[node]) {
            dfs(ch, t, node);
        }
    }
}


int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) active[i] = 1;
    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == 'A') {
            int a, b;  cin >> a >> b;
            queries[i] = {0, a, b};
            edges.push_back({a, b});
            edge_active[cnt] = 1;
            cnt++;
        } else if (c == 'D') {
            int a; cin >> a;
            queries[i] = {1, a, 0};
            active[a] = 0;
        } else {
            int ind; cin >> ind;
            auto &[a, b] = edges[ind - 1];
            edge_active[ind - 1] = 0;
            queries[i] = {2, a, b};
        }
    }
    for (int i = 1; i <= n; i++) ans[i] = 0;
    reverse(queries, queries + q);
    for (int i = 0; i < cnt; i++) {
        if (edge_active[i]) {
            auto &[a, b] = edges[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (active[i]) {
            dfs(i, q);
        }
    }
    int t = q;
    for (auto &[c, a, b] : queries) {
        t--;
        if (c == 0) continue;
        if (c == 2) {
            adj[a].push_back(b), adj[b].push_back(a);
            if (ans[a] != 0 || ans[b] != 0) {
                dfs(a, t);
                dfs(b, t);
            }
        } else  {
            dfs(a, t);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}