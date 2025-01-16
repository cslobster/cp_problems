#include <bits/stdc++.h>
using namespace std;

const int MXN = 303;

int n, m, k;
vector<int> adj[MXN];
int val[MXN], vis[MXN], dist[MXN][MXN], inRange[MXN][MXN];
set<int> valid[MXN];

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
        dist[i][i] = -1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            for (auto ch : adj[tp]) {
                if (vis[ch]) continue;
                vis[ch] = 1;
                dist[i][ch] = dist[i][tp] + 1;
                if (dist[i][ch] > k) continue;
                inRange[i][ch] = 1;
                valid[i].insert(ch);
                q.push(ch);
            }
        }
    }
    int ans = 0;
    for (auto a : valid[1]) {
       for (auto b : valid[a]) {
           if (b == 1 || a == b) continue;
           for (auto c : valid[b]) {
               if (c == a || c == b || c == 1) continue;
               for (auto d : valid[c]) {
                   if (d == a || d == b || d == c || d == 1) continue;
                   if (!inRange[d][1]) continue;
                   ans = max(ans, val[a] + val[b] + val[c] + val[d]);
                   // cout << val[a] << " " <<val[b] << " " << val[c] << " " << val[d] << endl;
               }
           }
       }
    }
    cout << ans << endl;
}