#include <bits/stdc++.h>
using namespace std;

#define int long long

struct BIT {
    vector<int> tree;
    int sz;
    BIT(int n) {
        tree.resize(4 * n);
        sz = n;
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
    BIT2(int n) {
        tree.resize(n);
        sz = n;
    }
    void upd(int i, int x) {
        tree[i] = x;
    }
    int query(int i) {
        int ans = 0;
        for (int j = 0; j <= i; j++) {
            ans += tree[j];
        }
        return ans;
    }
};

signed main() {
    ifstream cin("mincross.in");
    ofstream cout("mincross.out");
    int n;
    cin >> n;
    vector<int> f(n), s(n);
    map<int, int> loc;
    for (int i = 0; i < n; i++) cin >> f[i];
    BIT bit(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        loc[s[i]] = i;
    }
    int inv = 0;
    for (int i = n - 1; i >= 0; i--) {
        inv += bit.query(loc[f[i]]);
        bit.upd(loc[f[i]] + 1, 1);
    }

    int ans = inv;
    for (int i = 0; i < n; i++) {
        inv -= loc[f[i]];
        inv += n - loc[f[i]] - 1;
        ans = min(ans, inv);
    }

    BIT bit2(n + 1);

    inv = 0;
    for (int i = 0; i < n; i++) {
        loc[f[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        inv += bit2.query(loc[s[i]]);
        bit2.upd(loc[s[i]] + 1, 1);
    }

    ans = min(ans, inv);
    for (int i = 0; i < n; i++) {
        inv -= loc[s[i]];
        inv += n - loc[s[i]] - 1;
        ans = min(ans, inv);
    }
    cout << ans << endl;
}