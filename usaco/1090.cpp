#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 5e5 + 2;

int n, k;
vector<pair<int, int>> adj[MX];
int s[51][51], breed[MX];
ll dist[MX];
int lastOcc[51];

int main() {
    // ifstream cin("in.in");
    cin >> n >> k;
    for (int b = 1; b <= k; b++) lastOcc[b] = -1;
    for (int i = 1; i <= n; i++) cin >> breed[i];
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            char c; cin >> c;
            s[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e18;
        for (int b = 1; b <= k; b++) {
            if (lastOcc[b] == -1 || !s[breed[i]][b]) continue;
            adj[i].push_back({lastOcc[b], abs(i - lastOcc[b])});
        }
        lastOcc[breed[i]] = i;
    }
    for (int b = 1; b <= k; b++) lastOcc[b] = -1;
    for (int i = n; i >= 1; i--) {
        for (int b = 1; b <= k; b++) {
            if (lastOcc[b] == -1 || !s[breed[i]][b]) continue;
            adj[i].push_back({lastOcc[b], abs(i - lastOcc[b])});
        }
        lastOcc[breed[i]] = i;
    }
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    ll ans = 1e18;
    while (!pq.empty()) {
        auto tp = pq.top();
        if (s[breed[tp.second]][breed[n]]) ans = min(ans, -tp.first + n - tp.second);
        pq.pop();
        if (-tp.first != dist[tp.second]) continue;
        for (auto ch : adj[tp.second]) {
            if (ch.second - tp.first < dist[ch.first]) {
                pq.push({-(dist[ch.first] = ch.second - tp.first), ch.first});
            }
        }
    }
    // for (int i = 1; i <= k; i++) {
    //     cout << lastOcc[i] << " " << dist[lastOcc[i]] << endl;
    // }
    cout << ((ans == 1e18) ? -1 : ans) << endl;
}
