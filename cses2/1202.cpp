#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3, MOD = 1e9 + 7;

int n, m;
vector<pair<int, ll>> adj[MXN];
ll dist[MXN], dp[MXN], mn[MXN], mx[MXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e18, dp[i] = 0, mn[i] = 1e18, mx[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0, dp[1] = 1, mn[1] = 0, mx[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.first != dist[tp.second]) continue;
        for (auto ch : adj[tp.second]) {
            if (ch.second + tp.first < dist[ch.first]) {
                dp[ch.first] = dp[tp.second];
                dist[ch.first] = ch.second + tp.first;
                mn[ch.first] = mn[tp.second] + 1;
                mx[ch.first] = mx[tp.second] + 1;
                pq.push({dist[ch.first], ch.first});
            } else if (ch.second + tp.first == dist[ch.first]) {
                dp[ch.first] += dp[tp.second];
                dp[ch.first] %= MOD;
                mn[ch.first] = min(mn[ch.first], mn[tp.second] + 1);
                mx[ch.first] = max(mx[ch.first], mx[tp.second] + 1);
            }
        }
    }
    cout << dist[n] << " " << dp[n] << " " << mn[n] << " " << mx[n] << endl;
}