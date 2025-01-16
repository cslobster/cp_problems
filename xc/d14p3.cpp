/*
 * max sum of node labels to get from 1->a->b->c->d->1
 * meet me in the middle, calculate 3 best 1->a->b for each b
 * for each pair (b, c) check answer
 *
 * debugging note: remember, n is 2503! not 1e5 + 3 lol
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2503;

int n, m, k;
int dist[MXN][MXN], label[MXN];
vector<int> adj[MXN];
set<array<int, 3>> best[MXN];

int main() {
    cin >> n >> m >> k; k++;
    for (int i = 2; i <= n; i++) cin >> label[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(dist[i], 0x3f, sizeof(dist[i]));
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            for (auto ch : adj[tp]) {
                if (dist[i][ch] == 0x3f3f3f3f) {
                    dist[i][ch] = dist[i][tp] + 1;
                    q.push(ch);
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[1][i] > k) continue;
        for (int j = 2; j <= n; j++) {
            if (i == j) continue;
            if (dist[i][j] > k) continue;
            best[j].insert({label[i] + label[j], i, j});
            if (best[j].size() > 3) {
                best[j].erase(best[j].begin());
            }
        }
    }
    int ans = -1;
    for (int b = 2; b <= n; b++) {
        for (int c = 2; c <= n; c++) {
            if (b == c) continue;
            for (auto &[v1, aa, bb] : best[b]) {
                for (auto &[v2, cc, dd] : best[c]) {
                    if (aa == cc || aa == dd || bb == cc || bb == dd) continue;
                    if (dist[bb][dd] > k) continue;
                    ans = max(ans, v1 + v2);
                }
            }
        }
    }
    cout << ans << endl;
}