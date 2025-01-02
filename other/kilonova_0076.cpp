#include <bits/stdc++.h>
using namespace std;

const int MXN = 3e5 + 3;

int n;
int v[MXN];
map<int, vector<int>> e;

struct Seg {
    int sz;
    vector<int> tree;
    Seg(int _sz) {
        sz = _sz + 1;
        tree.resize(sz * 4);
    }
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    void upd(int node, int l, int r, int x, int y) {
        if (l == r) {
            tree[node] = y;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) upd(node * 2, l, mid, x, y);
        else upd(node * 2 + 1, mid + 1, r, x, y);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int node, int l, int r, int x, int y) {
        if (r < x || l > y) return 0;
        if (x <= l && r <= y) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, x, y), query(node * 2 + 1, mid + 1, r, x, y));
    }
};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        e[a].push_back(i);
        sum += v[i];
    }
    Seg tree(n + 1);
    tree.build(1, 1, n);
    for (auto &[k, v] : e) {
        vector<int> vals;
        for (int i = 0; i < v.size() - 1; i++) {
            vals.push_back(tree.query(1, 1, n, v[i], v[i + 1]));
        }
        stack<int> s;
        vector<int> ans(vals.size());
        for (int i = 0; i < vals.size(); i++) {
            if (s.empty()) {
                ans[i] = -1;
                s.push(i);
            } else {
                while (!s.empty() && vals[s.top()] <= vals[i]) {
                    s.pop();
                }
                if (!s.empty()) {
                    ans[i] = s.top();
                } else {
                    ans[i] = -1;
                }
                s.push(i);
            }
        }
        s = stack<int>();
        vector<int> ans2(vals.size());
        for (int i = vals.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                ans2[i] = vals.size();
                s.push(i);
            } else {
                while (!s.empty() && vals[s.top()] <= vals[i]) {
                    s.pop();
                }
                if (!s.empty()) {
                    ans2[i] = s.top();
                } else {
                    ans2[i] = vals.size();
                }
                s.push(i);
            }
        }
        for (int i = 0; i < vals.size(); i++) {
            int cur = (i - ans[i]) * (ans2[i] - i);
            sum += cur * vals[i];
        }
    }
    cout << sum << endl;
}