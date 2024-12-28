#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
ll dist[MXN];
int par[MXN], in[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = -1e18;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    par[1] = -100;
    dist[1] = 0;
    int node;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (auto ch : adj[node]) {
            in[ch]--;
            if (dist[node] != -1e18 && dist[node] + 1 > dist[ch]) {
                par[ch] = node;
                dist[ch] = max(dist[ch], dist[node] + 1);
            }
            if (in[ch] == 0) {
                q.push(ch);
            }
        }
    }
    if (dist[n] == -1e18) {
        cout << "IMPOSSIBLE\n"; return 0;
    }
    cout << dist[n] + 1 << "\n";
    node = n;
    vector<int> path;
    path.push_back(node);
    while (dist[n]) {
        node = par[node];
        path.push_back(node);
        dist[n]--;
    }
    reverse(path.begin(), path.end());
    for (auto e : path) {
        cout << e << " ";
    }
}