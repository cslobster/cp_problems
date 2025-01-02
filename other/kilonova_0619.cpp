#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, INF = 0x3f3f3f3f;;

int n, q;
string s;
int pr[MXN], pl[MXN], p[MXN];

struct Seg {
    int sz;
    vector<int> tree;
    Seg(int _sz) {
        sz = _sz + 1;
        tree.resize(sz * 4);
    }
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = p[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
    void upd(int node, int l, int r, int x, int y) {
        if (l == r) {
            tree[node] = y;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) upd(node * 2, l, mid, x, y);
        else upd(node * 2 + 1, mid + 1, r, x, y);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int node, int l, int r, int x, int y) {
        if (r < x || l > y) return INF;
        if (x <= l && r <= y) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(node * 2, l, mid, x, y), query(node * 2 + 1, mid + 1, r, x, y));
    }
};

int main() {
    ifstream cin("excursie.in");
    ofstream cout("excursie.out");
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        pl[i] = (s[i] == 'L');
        pl[i] += pl[i - 1];
    }
    for (int i = n ; i >= 1; i--) {
        pr[i] = (s[i] == 'R');
        pr[i] += pr[i + 1];
        p[i] = pr[i + 1] + pl[i - 1];
    }
    p[1] = pr[2], p[n] = pl[n - 1];
    cin >> q;
    Seg tree(n);
    tree.build(1, 1, n);
    while (q--) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        int ans = tree.query(1, 1, n, l, r);
        ans -= pl[l - 1];
        ans -= pr[r + 1];
        cout << ans << endl;
    }
}