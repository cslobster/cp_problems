#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1, 1);
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
        sz[b] += sz[a];
        par[a] = b;
    }
};

struct DSU2{
    vector<int> p;
    DSU2(int n){ p = vector<int>(n+5, -1); }
    int getPar(int x){ return (p[x] < 0? x : p[x] = getPar(p[x])); }
    void merge(int a, int b){
//        adj[a].pb({b, w});
//        adj[b].pb({a, w});
        a = getPar(a), b = getPar(b);
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b]; p[b] = a;
    }
};
struct E{ int a, b, dis; };
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    DSU2 dsu(n);

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, -1));
    vector<E> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if ((i == j && grid[i][j] != 0) || (i != j && grid[i][j] == 0)) {
                cout << "NO\n";
                return 0;
            }
            if (grid[j][i] != -1) {
                if (grid[j][i] != grid[i][j]) {
                    cout << "NO\n";
                    return 0;
                }
                edges.push_back({i, j, grid[i][j]});
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const E &x, const E &y){return x.dis < y.dis;});
    vector<vector<pair<int, int>>> adj(n + 1);

    int cnt = 0;
    for (auto edge : edges) {
        int u = edge.a, v = edge.b, w = edge.dis;
        if (cnt == n) {
            break;
        }
        if (dsu.getPar(u) != dsu.getPar(v)) {
            cnt++;
            dsu.merge(u, v);
            adj[u].push_back({v, grid[u][v]});
            adj[v].push_back({u, grid[u][v]});
        }
    }
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    /*
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            for (auto ch : adj[tp]) {
                if (dist[i][ch.first] == -1) {
                    q.push(ch.first);
                    dist[i][ch.first] = dist[i][tp] + ch.second;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != grid[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    */
    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (q.size()){
            int v = q.front(); q.pop();
            for (auto[u, w]: adj[v]){
                if (dist[i][u] == -1){
                    dist[i][u] = dist[i][v]+w;
                    q.push(u);
                }
            }
        }
        for (int j = 1; j <= n; j++) if (dist[i][j] != grid[i][j]){ cout << "NO\n"; return 0; }
    }
    cout << "YES\n";

}