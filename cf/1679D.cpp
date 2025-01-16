#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, m; ll k;
vector<int> adj[MXN];
int l[MXN], vis[MXN], in[MXN]; ll dp[MXN];

bool check(ll mid) {
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        if (l[i] > mid) continue;
        for (auto j : adj[i]) {
            if (l[j] > mid) continue;
            in[j]++;
        }
    }
    queue<int> q;
    int cnt = n; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] > mid) {
            cnt--;
            continue;
        }
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        cnt--;
        ans = max(ans, dp[tp]);
        for (auto ch : adj[tp]) {
            if (l[ch] > mid) continue;
            in[ch]--;
            if (in[ch] == 0) {
                dp[ch] = dp[tp] + 1;
                q.push(ch);
            }
        }
    }
    if (cnt > 0) {
        return true;
    }
    return ans >= k - 1;
}

int main() {
    cin >> n >> m >> k;
    int mx = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        mx = min(mx, l[i]);
    }
    if (k == 1) {
        cout << mx << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    ll l = 0;
    ll r = 1e9 + 1;
    while (l != r) {
        ll mid = (l + r)/2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ((l == 1e9 + 1) ? -1 : l) << endl;
}