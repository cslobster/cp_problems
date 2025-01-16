#include <bits/stdc++.h>
using namespace std;

const int MXN = 2503;

int n, m, k;
int val[MXN], d[MXN][MXN], vis[MXN];
vector<int> adj[MXN], withinRange[MXN];
set<pair<int, int>> best[MXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) cin >> val[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            for (auto ch : adj[tp]) {
                if (vis[ch]) continue;
                vis[ch] = 1;
                d[i][ch] = d[i][tp] + 1;
                if (d[i][ch] > k) continue;
                withinRange[i].push_back(ch);
                best[i].insert({d[i][ch], ch});
                if (best[i].size() > 4) best[i].erase(best[i].begin());
                q.push(ch);
            }
        }

    }

}