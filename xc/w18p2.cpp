/*
 * snake game but with obstacles, calculate dist to every point in the grid
 * trick is that the only cycles that will occur (repeat points) are to points originally in the snake
 * so add a timeUntil you can reach those nodes, and then do normal bfs (only care about head of snake)
 * and dijkstra
 */

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int MXN = 3003;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct State {
    ull d; int x, y;
};

bool operator<(const State &a, const State &b) {
    return a.d > b.d;
}

int n, m, k;
ull dist[MXN][MXN], timeUntil[MXN][MXN];
char grid[MXN][MXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = 1e18;

        }
    }
    int hx, hy; cin >> hx >> hy; hx--, hy--;
    timeUntil[hx][hy] = k;
    priority_queue<State> pq;
    for (int i = 1; i < k; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        timeUntil[a][b] = k - i;
        // if (i == 1) {
        //     dist[a][b] = k - 1;
        // }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    pq.push({dist[hx][hy] = 0, hx, hy});
    while (!pq.empty()) {
        auto [d, i, j] = pq.top();
        // cout << i << " " << j << " \t" << d << endl;
        pq.pop();
        for (int x = 0; x < 4; x++) {
            int nx = dx[x] + i;
            int ny = dy[x] + j;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[i][j] + 1 < dist[nx][ny]) {
                ull nwDst = dist[i][j] + 1;
                if (timeUntil[nx][ny] != 0 && timeUntil[nx][ny] > dist[i][j] + 1) {
                    nwDst = timeUntil[nx][ny];
                }
                dist[nx][ny] = nwDst;
                // cout << i << " " << j << " \t" << nx << " " << ny << " " << dist[nx][ny] << endl;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] != 1e18) {
                ans += dist[i][j] * dist[i][j];
                // cout << i << " " << j << " " << dist[i][j] << endl;
            }
        }
    }
    cout << ans << endl;
}