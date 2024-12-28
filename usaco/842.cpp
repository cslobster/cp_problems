#include <bits/stdc++.h>
using namespace std;

const int MX = 5e4 + 2;

int n, m;
vector<pair<int, int>> adj[MX];
vector<array<int, 3>> roads;
int ans[MX], up[MX][21], h[MX];
pair<int, int> xx[MX];

struct DSU {
    int par[MX], sz[MX];
    void set() {
        iota(par, par + n + 1, 0);
        for (int i = 0; i <= n; i++) sz[i] = 0;
    }
    int getPar(int a) {
        return (a == par[a]) ? a : par[a] = getPar(par[a]);
    }
    void merge(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[a] = b;
    }
};
//
void dfs(int node, int par) {
    up[node][0] = par;
    for (auto &[ch, i] : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            dfs(ch, node);
        }
    }
}

void bj() {
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    int k = h[b] - h[a];
    for (int i = 0; i <= 17; i++) {
        if (k & (1 << i)) b = up[b][i];
    }
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

DSU dsu;

void jump(int node, int lca, int w) {
    node = dsu.getPar(node);
    while (h[node] > h[lca]) {
        ans[node] = w;
        dsu.merge(node, up[node][0]);
        node = dsu.getPar(node);
    }
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
        int a, b, c; cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }
    dsu.set();
    sort(roads.begin(), roads.end());
    dfs(1, 1);
    bj();
    for (auto &[w, a, b] : roads) {
        int c = lca(a, b);
        jump(a, c, w);
        jump(b, c, w);
    }
    for (int i = 0; i < n - 1; i++) {
        auto [a, b] = xx[i];
        if (h[a] < h[b]) swap(a, b);
        cout << ((ans[a]) ? ans[a] : -1) << endl;
    }
}