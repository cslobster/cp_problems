#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    int t; cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        DSU dsu(n);
        vector<int> b(n + 1);
        iota(b.begin(), b.end(), 0);
        sort(b.begin(), b.end(), [&](const int x, const int y){return a[x] < a[y];});

        int ans = 0, cnt = 0;
        for (auto i : b) {
            if (i == 0) continue;
            if (a[i] > p) break;
            int j = i;
            int v = a[i];
            while (j > 1 && dsu.getPar(j - 1) != dsu.getPar(j) && a[j - 1] % v == 0) {
                cnt++;
                ans += v;
                dsu.merge(j - 1, j);
                j--;
            }
            j = i;
            while (j + 1 <= n && dsu.getPar(j + 1) != dsu.getPar(j) && a[j + 1] % v == 0) {
                cnt++;
                ans += v;
                dsu.merge(j, j + 1);
                j++;
            }
        }
        ans += (n - cnt - 1) * p;
        cout << ans << endl;
    }
}