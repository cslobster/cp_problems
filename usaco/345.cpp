#include <bits/stdc++.h>
using namespace std;

struct Target {
    int x, p;
};

bool operator<(const Target &a, const Target &b) {
    return a.x < b.x;
}

struct Seg {
    vector<int> tree, arr;
    void set(int n, vector<int> x) {
        arr = x, tree.resize(4 * n);
    }
    void build(int p, int l, int r) {
        if (l == r) {tree[p] = arr[l]; return;}

        int mid = (l + r) / 2;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);

        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }
    void upd(int p, int l, int r, int x, int y) {
        if (l == r) {tree[p] = y; return;}

        int mid = (l + r) / 2;
        if (x <= mid) upd(2 * p, l, mid, x, y);
        else upd(2 * p + 1, mid + 1, r, x, y);

        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }
    int query(int p, int l, int r, int x, int y) {
        if (l == r) return tree[p];

        int mid = (l + r) / 2;
        int ans = 0;
        if (x <= mid) {
            ans = max(ans, query(2 * p, l, mid, x, y));
        }
        if (y >= mid + 1) {
            ans = max(ans, query(2 * p + 1, mid + 1, r, x, y));
        }
        return ans;
    }
};

int main() {
    ifstream cin("pogocow.in");
    ofstream cout("pogocow.out");
    int n;
    cin >> n;
    vector<Target> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].x >> t[i].p;
    }
    // dp[i] = max score you can get if you land here last
    vector<int> dp[2][1001];
    Seg tree[2][1001];
    sort(t.begin(), t.end());
    int ans = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = n - 1; i >= 0; i--) {
            dp[k][i].push_back(0x3f3f3f3f);
            vector<int> vals;
            vals.push_back(t[i].p);
            ans = max(ans, t[i].p);
            for (int j = n - 1; j > i; j--) {
                int dst = abs(t[i].x - t[j].x);
                auto it = lower_bound(dp[k][j].begin(), dp[k][j].end(), dst);
                if (it == dp[k][j].end()) continue;
                int v = tree[k][j].query(1, 1, dp[k][j].size() - 1, it - dp[k][j].begin(), dp[k][j].size() - 1);
                dp[k][i].push_back(abs(t[i].x - t[j].x));
                vals.push_back(v + t[i].p);
                ans = max(ans, v + t[i].p);
            }
            dp[k][i].push_back(0);
            vals.push_back(0);
            reverse(vals.begin(), vals.end());
            reverse(dp[k][i].begin(), dp[k][i].end());
            tree[k][i].set(vals.size(), vals);
            tree[k][i].build(1, 1, vals.size() - 1);
        }
        reverse(t.begin(), t.end());
    }
    cout << ans << endl;
}