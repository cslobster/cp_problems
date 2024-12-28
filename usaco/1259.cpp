#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;
using ll = long long;

struct DSU {
    int n;
    vector<ll> par, sz;

    void resize(int _n) {
        par.resize(_n + 1), sz.resize(_n + 1, 1);
        n = _n;
        iota(par.begin(), par.end(), 0);
    }

    int getPar(int a) {
        if (par[a] == a) return a;
        return par[a] = getPar(par[a]);
    }

    void merge(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

struct Graph {
    int n, m;

    vector<vector<int>> adj;
    vector<int> deg, on;

    Graph(int _n) {
        _n++;
        adj.resize(_n), deg.resize(_n), on.resize(_n, 1);
        n = _n - 1;
    }

    set<pair<int, int>> active;

    void makeSet() {
        for (int i = 1; i <= n; i++) {
            active.insert({deg[i], i});
        }
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
        active.erase({deg[a], a});
        for (auto b : adj[a]) {
            if (!on[b]) continue;
            active.erase({deg[b], b});
            deg[b]--;
            active.insert({deg[b], b});
        }
    }

    vector<pair<int, int>> findOrder() {
        vector<pair<int, int>> ans;
        while (!active.empty()) {
            int a = active.begin()->second;
            ans.push_back(*active.begin());
            removeNode(a);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.makeSet();
    vector<pair<int, int>> ord = g.findOrder();
    // for (auto a : ord) {
    //     cout << a << endl;
    // }
    // g.resetOn();
    DSU dsu;
    dsu.resize(n);
    ll ans = 0, mx = 1;
    for (int i = 0; i < n; i++) {
        auto a = ord[i];
        g.on[a.second] = 1;
        for (auto b : g.adj[a.second]) {
            if (g.on[b]) {
                dsu.merge(a.second, b);
                mx = max(mx, dsu.sz[a.second]);
            }
        }
        ans = max(ans, mx * a.first);
    }
    cout << ans << endl;
}