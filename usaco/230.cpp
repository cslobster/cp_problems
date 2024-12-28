#include <bits/stdc++.h>
using namespace std;

const int MXI = 15, MXN = 51, MXM = (1 << 15);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n = 0, r, c;

char grid[MXN][MXN];
int id[MXN][MXN]; // which island;
bool vis[MXN][MXN], vis2[MXN][MXN];
vector<pair<int, int>> islands[MXI];
int dst[MXI][MXI], dist[MXN][MXN];
int ans[MXM][MXI];

void dfs(int i, int j, int cc) {
    if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j]) return;
    id[i][j] = cc;
    vis[i][j] = true;
    islands[cc].push_back({i, j});
    for (int x = 0; x < 4; x++) {
        dfs(i + dx[x], j + dy[x], cc);
    }
}

int main() {
    ifstream cin("island.in");
    ofstream cout("island.out");
    memset(ans, 0x3f, sizeof(ans));
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            id[i][j] = 0;
            if (grid[i][j] != 'X') vis[i][j] = true;
            if (grid[i][j] == '.') vis2[i][j] = true;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j]) {
                dfs(i, j, n++);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        deque<pair<int, int>> q;
        memset(dist, 0x3f, sizeof(dist));
        for (auto x : islands[i]) {
            q.push_back(x);
            dist[x.first][x.second] = 0;
        }
        while (!q.empty()) {
            auto tp = q.front();
            q.pop_front();
            for (int d = 0; d < 4; d++) {
                int nx = dx[d] + tp.first, ny = dy[d] + tp.second;
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (grid[nx][ny] == '.') continue;
                int cost = dist[tp.first][tp.second] + (grid[nx][ny] == 'S');
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (grid[nx][ny] == 'S') q.push_back({nx, ny});
                    else q.push_front({nx, ny});
                }
            }
        }
        for (int j = i + 1; j < n; j++) {
            int dis = 0x3f3f3f3f;
            for (int ii = 0; ii < r; ii++) {
                for (int jj = 0; jj < c; jj++) {
                    if (id[ii][jj] == j) dis = min(dis, dist[ii][jj]);
                }
            }
            dst[i][j] = dst[j][i] = dis;
        }
    }
    for (int i = 0; i < n; i++) { ans[1 << i][i] = 0; }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    // if (i == 2 && j == 1 && mask == 7) {
                    //     cout << "FFF" << endl;
                    // }
                    if (mask & (1 << j)) {
                        // cout << mask << " " << i << " " << j << " " << ans[mask][i] << " " << ans[mask ^ (1 << i)][j] + dst[i][j] << endl;

                        ans[mask][i] = min(ans[mask][i], ans[mask ^ (1 << i)][j] + dst[i][j]);

                    }
                }
            }
        }
    }
    cout << *min_element(ans[(1 << n) - 1], ans[(1 << n) - 1] + n) << endl;
}