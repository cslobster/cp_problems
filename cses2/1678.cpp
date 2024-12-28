#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
int in[MXN], vis[MXN];
vector<int> path;

bool dfs(int node) {
    if (vis[node]) {
        path.push_back(node);
        return true;
    }
    vis[node] = 1;
    path.push_back(node);
    for (auto ch : adj[node]) {
        if (dfs(ch)) return true;
    }
    vis[node] = 0;
    path.pop_back();

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        cnt++;
        vis[tp] = 1;
        for (auto ch : adj[tp]) {
            in[ch]--;
            if (in[ch] == 0) q.push(ch);
        }
    }
    if (cnt == n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) break;
        }
    }
    int i = path.size() - 2;
    while (i) {
        if (path[i] == path[path.size() - 1]) {
            break;
        }
        i--;
    }
    cout << path.size() - i << "\n";
    for (; i < path.size(); i++) {
        cout << path[i] << " ";
    }
}