#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 1e5 + 2;
int n, m;
ll h[MX], de[MX]; int up[MX][20];
vector<pair<int, ll>> adj[MX], adj2[MX];
map<int, vector<ll>> mp;


void dfs(int node, int par) {
    for (auto ch : adj2[node]) {
        if (ch.first != par) {
            up[ch.first][0] = node;
            h[ch.first] = h[node] + ch.second;
            de[ch.first] = de[node] + 1;
            dfs(ch.first, node);
        }
    }
}

void dij(int u, vector<ll> &d) {
    priority_queue<pair<ll, int>> pq;
    d.resize(n + 1, 1e13);
    pq.push({0, u});
    d[u] = 0;
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (d[tp.second] != -tp.first) continue;
        for (auto e : adj[tp.second]) {
            if (-tp.first + e.second < d[e.first]) {
                pq.push({-(d[e.first] = e.second - tp.first), e.first});
            }
        }
    }
}

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n + 1);
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
        par[a] = b;
    }
};

void bj() {
    up[1][0] = 1;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

int lca(int a, int b) {
    if (de[a] > de[b]) swap(a, b);
    ll k = de[b] - de[a];
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


int main() {
    cin >> n >> m;
    vector<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<array<int, 2>> bad;
    vector<array<int, 3>> run;
    for (auto &[c, a,b] : edges) {
        if (dsu.getPar(a) != dsu.getPar(b)) {
            dsu.merge(a, b);
            adj2[a].push_back({b, c});
            adj2[b].push_back({a, c});
        } else {
            bad.push_back({a, b});
            if (!mp.count(a)) {
                run.push_back({a, b, c});
            }
        }
    }
    dfs(1, -1);
    bj();
    for (auto &[a, b, c] : run) {
        dij(a, mp[a]);
    }
    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        ll ans = h[a] + h[b] - 2 * h[c];
        for (auto &[u, v] : bad) {
            ans = min(ans, mp[u][a] + mp[u][b]);
        }
        cout << ans << endl;
    }
}