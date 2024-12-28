#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

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

struct Edge {
    int i, j, cost;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<int>> p(n, vector<int>(4));
    DSU dsu(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
        dsu.merge(p[i][0], p[i][1]);
        dsu.merge(p[i][2], p[i][3]);
    }
    vector<int> comps;
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (dsu.getPar(i) == i) {
            cnt++;
            comps.push_back(i);
        }
    }
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        edges.push_back({dsu.getPar(p[i][0]), dsu.getPar(p[i][3]), c[i]});
    }
    int ans = 0;
    sort(edges.begin(), edges.end());
    for (auto &[i, j, w] : edges) {
        if (dsu.getPar(i) != dsu.getPar(j)) {
            ans += w;
            dsu.merge(i, j);
        }
    }
    cout << ans << endl;
}