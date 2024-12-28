#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
int l[MXN], r[MXN], k[MXN], ans[MXN];
int kOrder[MXN], lenOrder[MXN], revkOrder[MXN];
unordered_map<int, int> valToInd;
unordered_map<int, int> indToVal;
set<int> vals;

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

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> k[i];
        vals.insert(l[i]);
        vals.insert(r[i]);
        vals.insert(l[i] + k[i] - 1);
        // vals.insert(l[i] + k[i]);
        vals.insert(r[i] - k[i]);
        // vals.insert(r[i] - k[i] + 1);
    }
    int ii = 0;
    for (auto e : vals) {
        valToInd[e] = ++ii;
        indToVal[ii] = e;
    }
    iota(kOrder, kOrder + n, 0);
    sort(kOrder, kOrder + n, [](const int &a, const int &b) {
        return k[a] > k[b];
    });
    iota(lenOrder, lenOrder + n, 0);
    sort(lenOrder, lenOrder + n, [](const int &a, const int &b) {
        return l[a] - r[a] < l[b] - r[b];
    });
    for (int i = 0; i < n; i++) {
        revkOrder[kOrder[i]] = i;
    }
    // ii = 10;
    BIT left(ii + 1), right(ii + 1);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && r[lenOrder[j]] - l[lenOrder[j]] >= k[kOrder[i]]) {
            left.upd(valToInd[l[lenOrder[j]]], 1);
            right.upd(valToInd[r[lenOrder[j]]], 1);
            j++;
        }
        int sum = j - 1;
        sum -= right.query(valToInd[l[kOrder[i]] + k[kOrder[i]] - 1]);
        sum -= j - left.query(valToInd[r[kOrder[i]] - k[kOrder[i]]]);
        ans[kOrder[i]] = sum;
    }
    // for (int i = 0, j = 0; i < n; i++) {
    //     while (j < n && r[lenOrder[j]] - l[lenOrder[j]] >= k[kOrder[i]]) {
    //         left.upd(l[lenOrder[j]], 1);
    //         right.upd(r[lenOrder[j]], 1);
    //         j++;
    //     }
    //     int sum = j - 1;
    //     sum -= right.query(l[kOrder[i]] + k[kOrder[i]] - 1);
    //     sum -= j - left.query(r[kOrder[i]] - k[kOrder[i]]);
    //     ans[kOrder[i]] = sum;
    // }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}