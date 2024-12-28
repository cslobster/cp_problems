#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, INF = 1e9 + 3;

int n, m;
vector<pair<int, int>> radj[MXN];
int in[MXN], vis[MXN];
int dp[MXN][3];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = INF;
        dp[i][2] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        radj[b].push_back({a, c});
        in[a]++;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            pq.push({0, i});
            dp[i][0] = 0, dp[i][1] = 0, dp[i][2] = 0;
            vis[i] = 1;
        }
    }
    while (!pq.empty()) {
        auto [v, node] = pq.top();
        pq.pop();
        v *= -1;
        if (v != dp[node][1]) continue;
        for (auto &[to, c] : radj[node]) {
            if (!vis[to]) {
                in[to]--;
                if (dp[node][0] + 1 > dp[to][0]) {
                    dp[to][0] = dp[node][0] + 1;
                    dp[to][1] = c;
                    dp[to][2] = dp[node][2] + c;
                } else if (v + 1 == dp[to][0]) {
                    if (c < dp[to][1]) {
                        dp[to][1] = c;
                        dp[to][2] = dp[node][2] + c;
                    }
                } else continue;
                if (in[to] == 0) {
                    pq.push({-dp[to][1], to});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i][0] << " " << dp[i][2] << endl;
    }
}