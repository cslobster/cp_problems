#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 3;

struct BIT {
    int sz;
    vector<int> tree;
    BIT(int _sz) {
        sz = _sz;
        tree.resize(sz * 4);
    }
    void upd(int i, int x) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += x;
        }
    }
    int query(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i) {
            ans += tree[i];
        }
        return ans;
    }
};

struct BIT2 {
    int sz;
    vector<int> tree;
    BIT2(int _sz) {
        sz = _sz;
        tree.resize(sz + 1);
    }
    void upd(int i, int x) {
        tree[i] += x;
    }
    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i--;
        }
        return ans;
    }
};

int q, n = 1;
int elements[MXN];
vector<pair<int, int>> h;
set<int> occ[MXN];
BIT tree(MXN);

int getVal(int i) {
    int ans = tree.query(i);
    if (i - 1) ans -= tree.query(i - 1);
    return ans;
}

int main() {
    cin >> q;
    while (q--) {
        char c; cin >> c;
        if (c == '+') {
            int a; cin >> a;
            if (elements[n] != 0) {
                occ[elements[n]].erase(n);
                if (getVal(n) == 1) {
                    tree.upd(n, - 1);
                }
            }
            auto it = occ[a].upper_bound(n);
            if (it == occ[a].begin()) {
                tree.upd(n, 1);
            }
            elements[n] = a;
            occ[a].insert(n);
            n++;
            h.push_back({0, a});
        } else if (c == '-') {
            int k; cin >> k;
            n -= k;
            h.push_back({1, k});
        } else if (c == '!') {
            auto tp = h.back();
            h.pop_back();
            if (tp.first == 0) {
                n--;
                if (elements[n] != 0) {
                    occ[elements[n]].erase(n);
                    if (getVal(n) == 1) {
                        tree.upd(n, -1);
                    }
                }
                elements[n] = 0;
            } else {
                n += tp.second;
            }
        } else {
            if (n - 1 == 0) {
                cout << 0 << "\n"; continue;
            }
            cout << tree.query(n - 1) << "\n";
        }
    }
}