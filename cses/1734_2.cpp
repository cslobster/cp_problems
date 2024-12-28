#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;
int n, q;
int a[MXN], prevOcc[MXN];
pair<int, int> queries[MXN], qq[MXN];
map<int, int> pre;
map<pair<int, int>, int> ans;
int mxAdded = 0;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int sz) {
        n = sz;
        tree.resize(4 * sz + 3);
    }
    void upd(int i, int x) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += x;
        }
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= i & -i) {
            ans += tree[i];
        }
        return ans;
    }
};

struct BIT2 {
    int n;
    vector<int> tree;
    BIT2(int sz) {
        n = sz;
        tree.resize(sz + 1);
    }
    void upd(int i, int x) {
        tree[i] += x;
    }
    int query(int i) {
        int ans = 0;
        for (int j = 1; j <= i; j++) {
            ans += tree[j];
        }
        return ans;
    }
};


int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pre.count(a[i])) {
            prevOcc[i] = pre[a[i]];
        } else {
            prevOcc[i] = -1;
        }
        pre[a[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        qq[i].first = queries[i].first, qq[i].second = queries[i].second;
    }

    sort(queries, queries + q, [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    });

    BIT bit(n);

    for (int x = 0; x < q; x++) {
        auto &[i, j] = queries[x];
        if (j > mxAdded) {
            // add more to the bit tree
            for (int y = mxAdded + 1; y <= j; y++) {
                // add y
                bit.upd(y, 1);
                if (prevOcc[y] != -1) {
                    bit.upd(prevOcc[y], -1);
                }
            }
            mxAdded = j;
        }
        int cnt = bit.query(j);
        if (i != 1) cnt -= bit.query(i - 1);
        ans[{i, j}] = cnt;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[qq[i]] << endl;
    }
}