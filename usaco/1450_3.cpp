#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3, MOD = 1e9 + 7;

struct BIT {
    int sz;
    vector<ll> tree;
    void init(int _sz) {
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
};

struct BIT2 {
    int sz;
    vector<ll> tree;
    void init(int _sz) {
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
};

int n;
string s;
ll dp[MXN];
int recR = 0, nxtB[MXN];
set<pair<int, int>> pts;
BIT tree[2];

int main() {
    cin >> n >> s;
    s = " " + s;
    nxtB[n] = -1;
    for (int i = 1; i <= n; i++) {
        nxtB[i - 1] = (s[i] == 'B') ? i : -1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (nxtB[i] == -1) nxtB[i] = nxtB[i + 1];
    }
    tree[0].init(n + 5), tree[1].init(n + 5);
    tree[0].upd(2, 1);
    dp[0] = 1;
    pts.insert({2 * nxtB[0], 0});
    for (int i = 1; i <= n; i++) {
        // remove the removable
        while (!pts.empty() && pts.begin()->first == i) {
            int rmv = pts.begin()->second;
            // remove from bit tree
            tree[rmv % 2].upd(rmv + 2, -dp[rmv]);
            pts.erase(pts.begin());
        }
        int bound = max(i - 2 * (i - recR + 1) + 1, 0);
        if (nxtB[i] != -1) {
            // calculate the possible range
            int jb = nxtB[i];
            pts.insert({jb * 2 - i, i});
        }

        // calculate dp
        dp[i] = (tree[i % 2].query(i + 2) - tree[i % 2].query(bound + 1) + MOD) % MOD;

        // update the bit tree
        if (s[i] == 'X') dp[i] += dp[i - 1];
        else if (s[i] == 'R') {
            recR = i;
            dp[i] = 0;
        }
        dp[i] %= MOD;
        tree[i % 2].upd(i + 2, dp[i]);
    }
    cout << dp[n] % MOD << endl;
}