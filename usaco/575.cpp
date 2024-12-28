#include <bits/stdc++.h>
using namespace std;

struct Square {
    int x, y, s;
};

bool operator<(const Square &a, const Square &b) {
    return a.x < b.x;
}

struct State {
    int a; Square b;
};

bool operator<(const State &a, const State &b) {
    return a.a > b.a;
}

int dst[1001][1001][2];
int grid[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ifstream cin("dream.in");
    ofstream cout("dream.out");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    if (grid[0][0] == 0) {
        cout << -1 << endl;
        return 0;
    }
    memset(dst, 0x3f, sizeof(dst));
    priority_queue<State> pq;
    pq.push({dst[0][0][0] = 0, {0, 0, 0}});
    while (!pq.empty()) {
        auto [d, a] = pq.top();
        pq.pop();
        // cout << d << " " << a.x << " " << a.y << " " << a.s << endl;
        if (d != dst[a.x][a.y][a.s]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + a.x;
            int ny = dy[i] + a.y;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == 0) continue;
            if (grid[nx][ny] == 1 && dst[nx][ny][a.s] > d + 1) {
                pq.push({dst[nx][ny][a.s] = d + 1, {nx, ny, a.s}});
            } else if (grid[nx][ny] == 2 && dst[nx][ny][1] > d + 1) {
                pq.push({dst[nx][ny][1] = d + 1, {nx, ny, 1}});
            } else if (grid[nx][ny] == 3 && a.s == 1 && dst[nx][ny][a.s] > d + 1) {
                pq.push({dst[nx][ny][a.s] = d + 1, {nx, ny, a.s}});
            } else if (grid[nx][ny] == 4 && dst[nx][ny][0] > d + 1) {
                int cnt = d + 1;
                int nnx = nx, nny = ny;
                bool flag = false;
                while (true) {
                    int px = nnx + dx[i];
                    int py = nny + dy[i];
                    if (px < 0 || py < 0 || px >= n || py >= m || (grid[px][py] == 3 && a.s == 0) || grid[px][py] == 0) break;
                    nnx = px, nny = py;
                    cnt++;
                    if (grid[px][py] != 4) break;
                }
                if (dst[nnx][nny][a.s] <= cnt) continue;
                pq.push({dst[nnx][nny][0] = cnt, {nnx, nny, 0}});
            }
        }
    }
    int ans = min(dst[n - 1][m - 1][0], dst[n - 1][m - 1][1]);
    cout << ((ans == 0x3f3f3f3f) ? -1 : ans) << endl;
}