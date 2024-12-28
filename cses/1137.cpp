#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> st, ed;
vector<vector<int>> adj;
vector<int> val;
int id = 0;
int n, q;

struct BIT {
    vector<int> tree;
    void init(int _n) { tree.resize(_n); }

    void upd(int i, int x) {
        while (i < tree.size()) {
            tree[i] = (tree[i] + x);
            i += (i & (-i));
        }
    }

    long long query(int i) {
        long long ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & (-i));
        }
        return ans;
    }
};

BIT tree;

void dfs(int node, int p) {
    id++;
    st[node] = id;
    tree.upd(id, val[node]);
    for (auto c : adj[node]) {
        if (c != p) {
            dfs(c, node);
        }
    }
    ed[node] = id;
}

signed main() {
    cin >> n >> q;
    adj.resize(n + 1);
    tree.init(n + 1);
    val.resize(n + 1);
    st.resize(n + 1);
    ed.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> val[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            int c; cin >> c;
            tree.upd(st[b], c - val[b]);
            val[b] = c;
        } else {
            cout << tree.query(ed[b]) - tree.query(st[b] - 1) << endl;
        }
    }
}