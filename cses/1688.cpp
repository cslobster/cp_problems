#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
vector<vector<int>> adj(200000);
vector<pair<int, int>> euler(200000);
vector<int> idx(200000);
int t = 0;
const int MX = INT_MAX;

void dfs(int node, int p, int d = 0) {
    idx[node] = t;
    euler[t] = make_pair(d, node);
    t++;
    for (auto c : adj[node]) {
        if (c != p) {
            dfs(c, node, d + 1);
            euler[t] = make_pair(d, node);
            t++;
        }
    }
}

template<class T> struct SEG {
    vector<T> arr;
    vector<T> tree;
    void init(vector<T> &_arr) {
        tree.resize(4 * _arr.size());
        arr = _arr;
    }

    void build(int p, int l, int r) {
        if (l == r) {tree[p] = arr[l]; return;}

        int mid = (l + r)/2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);

        tree[p] = min(tree[2*p], tree[2*p + 1]);
    }

    void update(int p, int l, int r, int x, int y) {
        // turn arr[x] into y
        if (l == r) { tree[p] = y; return; }

        int mid = (l + r)/2;
        if (x <= mid) {
            update(2*p, l, mid, x, y);
        }
        else {
            update(2*p + 1, mid + 1, r, x, y);
        }

        tree[p] = min(tree[2*p], tree[2*p + 1]);
    }

    T query(int p, int l, int r, int x, int y) {
        if (l == r) { return tree[p]; }

        int mid = (l + r)/2;
        T ans = {1e9, -1};
        if (x <= mid) {
            ans = min(ans, query(2 * p, l, mid, x, y));
        }
        if (y >= mid + 1) {
            ans = min(ans, query(2 * p + 1, mid + 1, r, x, y));
        }

        return ans;
    }
};

signed main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(1, -1);
//    for (int i = 0; i < path.size(); i++) {
//        cout << path[i] << " " << depth[i] << endl;
//    }
    SEG<pair<int, int>> seg;
    seg.init(euler);
    seg.build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int x = idx[a], y = idx[b];
        if (x > y) swap(x, y);
        cout << seg.query(x, x, y, x, y).second << endl;
    }
}


/*
8
1 2
1 3
1 4
4 7
2 5
2 6
6 8

 */