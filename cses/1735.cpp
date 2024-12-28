#include <bits/stdc++.h>
using namespace std;

struct TREE {
    vector<int> tree;

    TREE(int n) {
        tree.resize(4 * n + 1);
    };

    void build(int p, int l, int r, vector<int> &x) {
        if (l == r) {
            tree[p] = x[l]; return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, x);
        build(2 * p + 1, mid + 1, r, x);
        tree[p] = tree[2 * p] + tree[2 * p + 1];
    }

    void upd(int p, int l, int r, int x, int y) {
        if (l == r) {
            tree[p] = y;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            upd(2 * p, l, mid, x, y);
        } else {
            upd(2 * p + 1, mid + 1, r, x, y);
        }

        tree[p] = tree[2 * p] + tree[2 * p + 1];
    }

    int query(int p, int l, int r, int x, int y) {
        if (l == r) return tree[p];
        int mid = (l + r) / 2;
        int ans = query(2 * p, l, mid, x, y) + query(2 * p + 1, mid + 1, r, x, y);
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    TREE tree(n);
    tree.build(0, 0, n - 1, x);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            juppd)()
        }
    }
}