#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
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
    int u, v; double a, b;
};

int n, m;
vector<Edge> edges;
// bool flag = false, dd = false;

bool check(double c) {
    sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b){return a.a - c * a.b > b.a - c * b.b;});
    double ans = 0;
    DSU dsu(n);
    for (auto &[u, v, a, b] : edges) {
        // cout << u << " " << v << " " << a << " " << b;
        if (dsu.getPar(u) != dsu.getPar(v)) {
            // cout << " merged";
            ans += a - c * b;
            dsu.merge(u, v);
            // if (flag) {
            //     cout << "Merging: " << u << " " << v << "\t" << dsu.getPar(u) << " "<< dsu.getPar(v) << endl;
            // }
        }
        // cout << endl;
    }
    return ans >= 0;
}

 int main() {
    // ifstream cin("text.in");
    // ofstream cout("text.out");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; double a, b;
        cin >> u >> v >> a >> b;
        edges.push_back({u, v, a, b});
    }
    double l = 0;
    double r = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r)/2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    double c = l;
    sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b){return a.a - c * a.b > b.a - c * b.b;});
    int num = 0, dem = 0;
    DSU dsu(n);
    for (auto &[u, v, a, b] : edges) {
        if (dsu.getPar(u) != dsu.getPar(v)) {
            num += a;
            dem += b;
            dsu.merge(u, v);
        }
    }
    for (int i = 100; i > 0; i--) {
        if (num % i == 0 && dem % i == 0) {
            num /= i, dem /= i;
        }
    }
    cout << num << "/" << dem << endl;
}