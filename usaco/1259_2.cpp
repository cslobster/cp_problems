#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;
using ll = long long;


struct Graph {
    int n, m;

    vector<vector<int>> adj;
    vector<int> deg, on;

    vector<int> vis;

    Graph(int _n, int _m) {
        _n++;
        adj.resize(_n), deg.resize(_n), on.resize(_n, 1), vis.resize(_n);
        n = _n - 1, m = _m;
    }

    void resetOn() {
        on.resize(n + 1, 0);
    }

    void addEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++, deg[b]++;
    }

    void removeNode(int a) {
        on[a] = 0;
        for (auto b : adj[a]) {
            if (!on[b]) continue;
            deg[b]--;
        }
    }

    int dfs(int node) {
        assert(!vis[node]);
        vis[node] = 1;
        int ans = 1;
        for (auto ch : adj[node]) {
            if (on[ch] && !vis[ch]) {
                ans += dfs(ch);
            }
        }
        return ans;
    }

    int solve() {
        int ans = 0;
        for (int i = 1; i * i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (deg[j] <= i && on[j]) removeNode(j);
            }
            vis.clear();
            vis.resize(n + 1, 0);
            // find the largest component now
            int mx = 1;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && on[j]) mx = max(mx, dfs(j));
            }
            ans = max(ans, mx * i);
        }

        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cout << g.solve() << endl;
}