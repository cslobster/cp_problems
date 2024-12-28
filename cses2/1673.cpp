#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5003;

int n, m;
ll edges[MXN][3];
vector<ll> adj[MXN], adj2[MXN];
ll dist[MXN];
ll vis[MXN], vis2[MXN];

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = 1;
    for (auto ch : adj[node]) {
        dfs(ch);
    }
}

void dfs2(int node) {
    if (vis2[node]) return;
    vis2[node] = 1;
    for (auto ch : adj2[node]) {
        dfs2(ch);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }
        adj[edges[i][0]].push_back(edges[i][1]);
        adj2[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 1; i <= n; i++) dist[i] = -1e18;
    dist[1] = 0;
    dfs(1), dfs2(n);
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) {
            auto &[a, b, c] = edges[i];
            dist[b] = max(dist[b], dist[a] + c);
        }
    }
    for (int i = 0; i < m; i++) {
        auto &[a, b, c] = edges[i];
        if (vis[b] && vis2[b] && dist[a] + c > dist[b]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << dist[n] << endl;
}