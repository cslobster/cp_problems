#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

struct State {
    int node; ll d; int x;
};

bool operator<(const State &a, const State &b) {
    return a.d > b.d;
}

int n, m;
vector<pair<int, ll>> adj[MXN];
ll dist[MXN][2];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = 1e18;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<State> pq;
    dist[1][0] = 0, dist[1][1] = 0;
    pq.push({1, 0, 0});
    pq.push({1, 0, 1});
    while (!pq.empty()) {
        auto [node, d, x] = pq.top();
        pq.pop();
        if (d != dist[node][x]) continue;
        for (auto ch : adj[node]) {
            if (dist[ch.first][x] > dist[node][x] + ch.second) {
                dist[ch.first][x] = dist[node][x] + ch.second;
                pq.push({ch.first, dist[ch.first][x], x});
            }
            int nw = ch.second / 2;
            if (x == 0 && dist[ch.first][1] > dist[node][0] + nw) {
                dist[ch.first][1] = dist[node][0] + nw;
                pq.push({ch.first, dist[ch.first][1], 1});
            }
        }
    }
    cout << dist[n][1] << endl;
}