#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

struct BIT {
    int sz;
    vector<ll> tree;
    BIT(int _sz) {
        sz = _sz;
        tree.resize(sz * 4);
    }
    void upd(int i, ll x) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += x;
        }
    }
    ll query(int i) {
        ll ans = 0;
        for (; i > 0; i -= i & -i) {
            ans += tree[i];
        }
        return ans;
    }
    void reset() {
        tree.clear();
        tree.resize(sz + 1, 0);
    }
};

struct BIT2 {
    int sz;
    vector<ll> tree;
    BIT2(int _sz) {
        sz = _sz;
        tree.resize(sz + 1);
    }
    void upd(int i, ll x) {
        tree[i] += x;
    }
    ll query(int i) {
        ll ans = 0;
        while (i > 0) {
            ans += tree[i];
            i--;
        }
        return ans;
    }
    void reset() {
        tree.clear();
        tree.resize(sz + 1, 0);
    }
};

int n, k;
int a[MXN];
ll xdp[MXN], xpdp[MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    BIT dp(n + 2), pdp(n + 2);
    for (int j = 1; j <= k + 1; j++) {
        for (int i = 0; i < n; i++) {
            xdp[i] = 0;
            if (j == 1) {
                xdp[i] = 1;
                continue;
            }
            ll val = pdp.query(a[i]);
            xdp[i] = val;
            pdp.upd(a[i] + 1, xpdp[i]);
        }
        swap(dp, pdp);
        dp.reset();
        swap(xdp, xpdp);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += xpdp[i];
    }
    cout << ans << endl;
}
