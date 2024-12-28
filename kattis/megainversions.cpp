#include <bits/stdc++.h>
using namespace std;

#define int long long
struct BIT {
    vector<int> tree;
    int sz;
    BIT (int n) {
        sz = n;
        tree.resize(sz * 4);
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
    vector<int> tree;
    int sz;
    BIT2 (int n) {
        sz = n;
        tree.resize(n);
    }
    void upd(int i, int x) {
        tree[i] = x;
    }
    int query(int i) {
        int ans = 0;
        for (int j = 0; j <= i; j++) ans += tree[j];
        return ans;
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    BIT bit(n + 1), bit2(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        b[i] = i - bit.query(a[i]);
        bit.upd(a[i], 1);
    }
    for (int i = 0; i < n; i++) {
        ans += bit2.query(n) - bit2.query(a[i]);
        bit2.upd(a[i], b[i]);
    }
    cout << ans << endl;
}