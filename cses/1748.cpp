#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct BIT {
    vector<int> tree;
    BIT(int n) {
        tree.resize(4 * n);
    }
    void upd(int i, int x) {
        for (; i <= tree.size(); i += i & -i) {
            tree[i] += x;
            tree[i] %= MOD;
        }
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= i & -i) {
            ans += tree[i];
            ans %= MOD;
        }
        return ans;
    }
};

struct BIT2 {
    vector<int> tree;
    BIT2(int n) {
        tree.resize(n + 1);
    }
    void upd(int i, int x) {
        tree[i] += x;
    }
    int query(int i) {
        int ans = 0;
        for (int j = 0; j <= i; j++) ans += tree[j];
        return ans;
    }
};

vector<int> x;

signed main() {
    int n;
    cin >> n;
    x.resize(n + 1);
    BIT tree(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    set<int> sorted(x.begin(), x.end());
    int ind = 0;
    for (auto e : sorted) {
        mp[e] = ind++;
    }

    for (int i = 1; i <= n; i++) {
        int temp = 1;
        if (mp[x[i]] - 1) temp += tree.query(mp[x[i]] - 1);
        tree.upd(mp[x[i]], temp);

    }
    cout << tree.query(n) % MOD << endl;
}