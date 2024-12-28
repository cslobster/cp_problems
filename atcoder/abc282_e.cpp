#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <algorithm>
using namespace std;

using ll = long long;

ll exp(ll a, ll b, ll m) {
    a %= m;
    ll ans = 1;
    while (b) {
        if (b % 2 == 1) ans = ans * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ans;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<array<ll, 3>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                ll cost = (exp(a[i], a[j], m) + exp(a[j], a[i], m)) % m;
                edges.push_back({cost, i, j});
            }
        }
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    ll ans = 0;
    DSU dsu(n);
    for (auto &[w, u, v] : edges) {
        if (dsu.getPar(u) != dsu.getPar(v)) {
            dsu.merge(u, v);
            ans += w;
        }
    }
    cout << ans << endl;
}