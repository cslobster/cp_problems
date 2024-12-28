#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN], adj2[MXN];
int vis[MXN], ans[MXN];
vector<int> ord;
int id = 1;

void dfs(int node) {
    vis[node] = true;
    for (auto ch : adj[node]) {
        if (!vis[ch]) {
            dfs(ch);
        }
    }
    ord.push_back(node);
}

void dfs2(int node) {
    if (ans[node] != 0) return;
    ans[node] = id;
    for (auto par : adj2[node]) {
        dfs2(par);
    }
}

int main() {
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    reverse(ord.begin(), ord.end());

    memset(vis, 0, sizeof(vis));

    for (auto i : ord) {
        if (ans[i] == 0) {
            dfs2(i);
            id++;
        }
    }
    cout << id - 1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}