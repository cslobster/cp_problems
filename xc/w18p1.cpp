/*
 * what is the min number of nodes needed to get from 1->2->1
 *
 * dp[i][j] = get from 1->i->j->1 in min number of nodes
 * imagine graph with 1 -> 3, 3 -> 4, 4 -> 1, b -> 3, 4 -> a, a -> b
 * now you can go 1 -> 3 -> 4 -> a
 * and a -> b -> 3, 3 -> 4, 4 -> 1
 */

#include <bits/stdc++.h>
using namespace std;

const int MXN = 203;

int n, m;
vector<int> adj[MXN], radj[MXN];
int dp[MXN][MXN], dist[MXN][MXN];

struct State {
    int dist, i, j;
};

bool operator<(const State &a, const State &b) {
    if (a.dist != b.dist) return a.dist > b.dist;
    if (a.i != b.i) return a.i < b.i;
    return a.j < b.j;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 10000;
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 10000;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
        dist[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == 10000 || dist[k][j] == 10000) continue;
                int temp = dist[i][k] + dist[k][j];
                if (temp < dist[i][j]) {
                    dist[i][j] = temp;
                }
            }
        }
    }
    priority_queue<State> q;
    q.push({1, 1, 1});
    dp[1][1] = 1;
    while (!q.empty()) {
        auto [d, i, j] = q.top();
        q.pop();
        if (dp[i][j] != d) continue;
        // cout << d << " " << i << " " << j << endl;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (a == i && b == j) continue;
                int temp = dp[i][j] + dist[j][a] + dist[a][b] + dist[b][i] - 1;
                if (dp[a][b] > temp) {
                    dp[a][b] = temp;
                    q.push({dp[a][b], a, b});
                }
            }
        }
    }
    cout << dp[2][2] << endl;
}