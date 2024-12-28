#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dc[4] = {'R', 'L', 'D', 'U'};

int n, m;
int vis[MXN][MXN], grid[MXN][MXN], t[MXN][MXN], t2[MXN][MXN], par[MXN][MXN];
vector<pair<int, int>> monsters;
int ax, ay;

queue<pair<int, int>> q;

int main() {
    memset(t, 0x3f, sizeof(t));
    memset(t2, 0x3f, sizeof(t2));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c; grid[i][j] = c;
            vis[i][j] = (c != '.');
            if (c == 'A') {
                t2[i][j] = 0;
                ax = i, ay = j;
            }
            if (c == 'M') {
                vis[i][j] = 1;
                t[i][j] = 0;
                monsters.push_back({i, j});
                q.push({i, j});
            }
        }
    }
    for (int i = 1; i <= n; i++) vis[i][0] = vis[i][m + 1] = 1;
    for (int j = 1; j <= m; j++) vis[0][j] = vis[n + 1][j] = 1;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = dx[d] + i;
            int ny = dy[d] + j;
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (vis[nx][ny]) continue;
            if (grid[nx][ny] == '#') continue;
            t[nx][ny] = t[i][j] + 1;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    q.push({ax, ay});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == 1 || i == n || j == 1 || j == m) {
            cout << "YES\n" << t2[i][j] << "\n";
            vector<char> ans;
            while (i != ax || j != ay) {
                int prev = par[i][j];
                i -= dx[prev];
                j -= dy[prev];
                ans.push_back(dc[prev]);
            }
            reverse(ans.begin(), ans.end());
            for (auto e : ans) cout << e;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = dx[d] + i;
            int ny = dy[d] + j;
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (t2[nx][ny] != 0x3f3f3f3f) continue;
            if (t[nx][ny] <= t2[i][j] + 1) continue;
            if (grid[nx][ny] == '#') continue;
            t2[nx][ny] = t2[i][j] + 1;
            par[nx][ny] = d;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    cout << "NO\n";
}