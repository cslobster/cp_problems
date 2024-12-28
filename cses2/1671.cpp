#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

int n, m;
vector<pair<int, int>> adj[MXN];
ll dist[MXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.first != dist[tp.second]) continue;
        for (auto ch : adj[tp.second]) {
            if (ch.second + tp.first < dist[ch.first]) {
                pq.push({dist[ch.first] = ch.second + tp.first, ch.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}