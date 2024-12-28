#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3, M = 1e9;

/*
 * in order for range 2 to be inside range 1
 * you need l1 < l2 && r1 > r2
 * by sorting in increasing order of r you can fix the 2nd statement
 * then, use bit tree to count how many ranges have l1 < l2
*/

int n;
ll l[MXN], r[MXN], order[MXN], res[MXN], res2[MXN];
set<ll> s;
map<ll, int> mp;

struct BIT {
    vector<int> tree;
    void init(int _n) { tree.resize(_n); }

    void upd(int i, int x) {
        while (i < tree.size()) {
            tree[i] = (tree[i] + x);
            //if (tree[i] < 0) tree[i] += M;
            if (tree[i] > M) tree[i] -= M;
            tree[i] = (tree[i] + M) % M;
            i += (i & (-i));
        }
    }

    long long query(int i) {
        long long ans = 0;
        while (i > 0) {
            ans += tree[i];
            //if (ans < 0) ans += M;
            if (ans > M) ans -= M;
            ans = (ans + M) % M;
            i -= (i & (-i));
        }
        return ans;
    }
};

// struct BIT {
//     int sz;
//     vector<ll> tree;
//     BIT(int _sz) {
//         sz = _sz;
//         tree.resize(sz * 4);
//     }
//     void upd(int i, ll x) {
//         for (; i < tree.size(); i += i & -i) {
//             tree[i] += x;
//         }
//     }
//     ll query(int i) {
//         ll ans = 0;
//         for (; i; i -= i & -i) {
//             ans += tree[i];
//         }
//         return ans;
//     }
// };

struct BIT2 {
    int sz;
    vector<ll> tree;
    BIT2(int _sz) {
        sz = _sz;
        tree.resize(sz + 1);
    }
    void upd(int i, int x) {
        tree[i] += x;
    }
    ll query(int i) {
        ll ans = 0;
        for (; i; i--) {
            ans += tree[i];
        }
        return ans;
    }
};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        s.insert(l[i]);
        s.insert(r[i]);
    }
    int ii = 0;
    for (auto e : s) {
        mp[e] = ++ii;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
    }
    ii++;

    iota(order, order + n + 1, 0);
    sort(order + 1, order + n + 1, [](const int &a, const int &b)  {
        if (r[a] != r[b]) return r[a] < r[b];
        return l[a] > l[b];
    });

    BIT tree;
    tree.init(ii + 1);
    for (int ind = 1; ind <= n; ind++) {
        int i = order[ind];
        ll cur = tree.query(r[i]);
        if (l[i] - 1) cur -= tree.query(l[i] - 1);
        res[i] = cur;
        tree.upd(l[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    sort(order + 1, order + n + 1, [](const int &a, const int &b)  {
        if (r[a] != r[b]) return r[a] > r[b];
        return l[a] < l[b];
    });

    BIT tree2;
    tree2.init(ii + 1);
    for (int ind = 1; ind <= n; ind++) {
        int i = order[ind];
        res2[i] = tree2.query(l[i]);
        tree2.upd(l[i], 1);
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << res2[i] << " ";
    }
}