#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

struct Type {
    int p, q, x, y;
};

int n, m, k;
Type a[MXN];
vector<pair<int, int>> adj[MXN];
int cur[MXN];

int val(int a, int b) {
    if (cur[a] < b) return 0;
    if (cur[a] == b) return 1;
    return 2;
}

bool valid(int i) {
    return val(a[i].p, a[i].x) == val(a[i].q, a[i].y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cur[i] = 1;
    queue<int> q;
    for (int i = 0; i < k; i++) {
        cin >> a[i].p >> a[i].x >> a[i].q >> a[i].y;
        adj[a[i].p].push_back({a[i].x, i});
        adj[a[i].q].push_back({a[i].y, i});
        q.push(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }
    while (!q.empty()) {
        auto i = q.front();
        q.pop();
        if (valid(i)) continue;
        // what is the problem? current value =
        int changed = -1;
        if (cur[a[i].p] > a[i].x) {
            cur[a[i].q] = a[i].y + 1;
            changed = a[i].q;
        } else if (cur[a[i].q] > a[i].y) {
            cur[a[i].p] = a[i].x + 1;
            changed = a[i].p;
        } else if (cur[a[i].p] == a[i].x) {
            cur[a[i].q] = a[i].y;
            changed = a[i].q;
        } else if (cur[a[i].q] == a[i].y) {
            cur[a[i].p] = a[i].x;
            changed = a[i].p;
        }
        if (cur[a[i].p] > m || cur[a[i].q] > m) {
            cout << -1 << endl;
            return 0;
        }
        // assert(valid(i));
        while (!adj[changed].empty() && adj[changed].back().first < cur[changed]) {
            q.push(adj[changed].back().second);
            adj[changed].pop_back();
        }
        for (int ind = adj[changed].size() - 1; ind >= 0; ind--) {
            if (adj[changed][ind].first > cur[changed]) break;
            q.push(adj[changed][ind].second);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //     cout << cur[i] << " ";
        ans += cur[i];
    }
    cout << ans << endl;
}