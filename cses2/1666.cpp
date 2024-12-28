#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
bool vis[MXN];
vector<int> v;

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto ch : adj[node]) dfs(ch);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            v.push_back(i);
            dfs(i);
        }
    }
    cout << v.size() - 1 << endl;
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " " << v[i + 1] << endl;
    }
}