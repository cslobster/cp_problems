#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
int n, q;
vector<int> adj[MAXN];
int e[MAXN];
vector<int> ord(1);
pair<int, int> r[MAXN];
int up[MAXN][30];
int h[MAXN];

void dfs(int node, int par) {
    for (auto ch : adj[node]) {
        if (ch != par) {
            up[ch][0] = node;
            r[ch].first = ord.size();
            h[ch] = h[node] + 1;
            ord.push_back(e[ch]);
            dfs(ch, node);
        }
    }
    r[node].second = ord.size() - 1;
}

void bj() {
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    int k = h[a] - h[b];
    for (int i = 0; i < 30; i++) {
        if (k & (1 << i)) a = up[a][i];
    }
    if (a == b) return a;
    for (int i = 29; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

struct SEG {
//    vector<int> arr;
    vector<int> tree;
    SEG(int sz) {
//        arr = a;
        tree.resize(4 * sz);
    }
//    void build(int p, int l, int r) {
//        if (l == r) {tree[p] = arr[l]; return;}
//
//        int mid = (l + r)/2;
//        build(2*p, l, mid);
//        build(2*p + 1, mid + 1, r);
//
//        tree[p] = tree[2*p] ^ tree[2*p + 1];
//    }

    void update(int p, int l, int r, int x, int y) {
        // turn arr[x] into y
        if (l == r) { tree[p] ^= y; return; }

        int mid = (l + r)/2;
        if (x <= mid) {
            update(2*p, l, mid, x, y);
        }
        else {
            update(2*p + 1, mid + 1, r, x, y);
        }

        tree[p] = tree[2*p] ^ tree[2*p + 1];
    }

    int query(int p, int l, int r, int x, int y) {
        if (l == r) { return tree[p]; }

        int mid = (l + r)/2;
        int ans = 0;
        if (x <= mid) {
            ans = ans ^ query(2 * p, l, mid, x, y);
        }
        if (y >= mid + 1) {
            ans = ans ^ query(2 * p + 1, mid + 1, r, x, y);
        }
        return ans;
    }
};

struct SEG2 {
    vector<int> tree;
    SEG2(int sz) {
        tree.resize(4 * sz + 4);
    }
    void update(int a, int b, int c, int x, int y) {
        tree[x] += y;
    }
    int query(int a, int b, int c, int x, int y) {
        int ans = 0;
        for (int i = x; i <= y; i++) {
            ans += tree[i];
        }
        return ans;
    }
};

struct BIT {
    vector<int> tree;
    BIT (int sz) {
        tree.resize(4 * sz + 4);
    }
    void upd(int i, int j) {
        while (i < tree.size()) {
            tree[i] ^= j;
            i += i & -i;
        }
    }
    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans ^= tree[i];
            i -= i & -i;
        }
        return ans;
    }
};

int main() {
    ifstream cin("cowland.in");
    ofstream cout("cowland.out");
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> e[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ord.push_back(e[1]);
    r[1].first = 1;
    h[1] = 0;
    up[1][0] = 1;
    dfs(1, -1);
    bj();
    BIT tree(ord.size());
    SEG tree2(ord.size());
    for (int i = 1; i <= n; i++) {
        tree.upd(r[i].first, e[i]);
        tree.upd(r[i].second + 1, e[i]);
//        tree2.update(1, 1, ord.size(), r[i].first, e[i]);
//        tree2.update(1, 1, ord.size(), r[i].second + 1, e[i]);
    }

    while (q--) {
        int a, i, j;
        cin >> a >> i >> j;
        if (a == 1) {
            tree.upd(r[i].first, e[i] ^ j);
            tree.upd(r[i].second + 1, e[i] ^ j);
//            tree2.update(1, 1, ord.size(), r[i].first, e[i] ^ j);
//            tree2.update(1, 1, ord.size(), r[i].second + 1, e[i] ^ j);
            e[i] = j;
        } else {
            int k = lca(i, j);
            int ans = tree.query(r[i].first);
            ans ^= tree.query(r[j].first);
            ans ^= e[k];
            cout << ans << endl;
//            int ans2 = tree2.query(1, 1, ord.size(), r[k].first, r[i].first);
//            ans2 ^= tree2.query(1, 1, ord.size(), r[k].first, r[j].first);
//            cout << (ans2 ^ e[k]) << endl;
//            cout << i << " " << j << " " << k << endl;
        }
    }
}


