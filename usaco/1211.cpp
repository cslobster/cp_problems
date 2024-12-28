#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#define int long long
using namespace std;

using ll = long long;

struct Edge {
    int i, j; ll dist;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.dist < b.dist;
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

signed main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    vector<int> l(11, -1);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    vector<Edge> edges;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++) {
            if (l[j] != -1) {
                int dist = (c[i].first - c[l[j]].first) * (c[i].first - c[l[j]].first);
                dist += (c[i].second - c[l[j]].second) * (c[i].second - c[l[j]].second);
                edges.push_back({i, l[j], dist});
            }
        }
        l[c[i].second] = i;
    }
    ll ans = 0;
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    for (auto &[i, j, dist] : edges) {
        if (dsu.getPar(i) != dsu.getPar(j)) {
            ans += dist;
            dsu.merge(i, j);
        }
    }
    cout << ans << endl;
}