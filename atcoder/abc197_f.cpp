#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
//    ifstream cin("in.in");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; char c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        q.push({i, i});
        dist[i][i] = 0;
        for (auto ch : adj[i]) {
            if (dist[i][ch.first] == INT_MAX) {
                dist[i][ch.first] = dist[ch.first][i] = 1;
                q.push({i, ch.first});
            }
        }
    }
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        if ((tp.first == 1 && tp.second == n) || (tp.first == n && tp.second == 1)) {
            cout << dist[1][n] << endl;
            return 0;
        }
        for (auto ch : adj[tp.first]) {
            for (auto ch2 : adj[tp.second]) {
                if (ch.second == ch2.second && dist[tp.first][tp.second] + 2 < dist[ch.first][ch2.first]) {
                    q.push({ch.first, ch2.first});
                    dist[ch.first][ch2.first] = dist[tp.first][tp.second] + 2;
                }
            }
        }
    }
    cout << -1 << endl;
}