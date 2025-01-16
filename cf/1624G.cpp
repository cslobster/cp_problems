#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, m;
int vis[MXN];
vector<int> adj[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> edges(m + 1, vector<int>(3));
        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        int ans = 0;
        for (int j = 29; j >= 0; j--) {
            memset(vis, 0, n + 1);
            for (int i = 0; i < m; i++) {
                if (edges[i][2] < (1 << j)) {
                    adj[edges[i][0]].push_back(edges[i][1]);
                    adj[edges[i][1]].push_back(edges[i][0]);
                }
            }
            queue<int> q;
            q.push(1);
            int cnt = 0;
            vis[0] = 1, vis[1] = 1;
            while (!q.empty()) {
                auto tp = q.front();
                q.pop();
                cnt++;
                for (auto ch : adj[tp]) {
                    if (!vis[ch]) {
                        vis[ch] = 1;
                        q.push(ch);
                    }
                }
            }
            if (cnt != n) {
                ans ^= (1 << j);
                for (int i = 0; i < m; i++) {
                    if (edges[i][2] & (1 << j)) {
                        edges[i][2] ^= (1 << j);
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                adj[i].clear();
            }
        }
        cout << ans << "\n";
    }
}