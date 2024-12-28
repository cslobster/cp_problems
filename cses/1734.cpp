#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;

    BIT(int _n) {
        tree.resize(_n + 1);
    }

    void upd(int i, int x) {
        while (i < tree.size()) {
            tree[i] = (tree[i] + x);
            i += (i & (-i));
        }
    }

    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & (-i));
        }
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        queries[a].push_back({b, i});
    }
    BIT bit(n);
    map<int, int> lid;
    vector<int> ans(q);
    for (int i = n; i >= 1; i--) {
        if (lid.count(x[i])) {
            bit.upd(lid[x[i]], -1);
        }
        bit.upd(i, 1);
        lid[x[i]] = i;
        for (auto a : queries[i]) {
            ans[a.second] = bit.query(a.first) - bit.query(i) + 1;
        }
    }
    for (auto e : ans) {
        cout << e << endl;
    }
}