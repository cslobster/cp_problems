#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

int n, m, k;
vector<pair<int, ll>> adj[MXN];
multiset<ll> dist[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1].insert(0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.first > *dist[tp.second].rbegin()) continue;
        for (auto ch : adj[tp.second]) {
            ll nw = ch.second + tp.first;
            if (dist[ch.first].size() < k) {
                dist[ch.first].insert(nw);
                pq.push({nw, ch.first});
            } else {
                if (*dist[ch.first].rbegin() > nw) {
                    dist[ch.first].erase(dist[ch.first].find(*dist[ch.first].rbegin()));
                    dist[ch.first].insert(nw);
                    pq.push({nw, ch.first});
                }
            }
        }
    }
    while (k) {
        cout << *dist[n].begin() << " ";
        dist[n].erase(dist[n].begin());
        k--;
    }
}