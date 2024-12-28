#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dc[4] = {'L', 'R', 'U', 'D'};
map<pair<int, int>, char> mp;

int n, m;
int ax, ay, bx, by;
bool vis[MXN][MXN];
int par[MXN][MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            vis[i][j] = (c == '#');
            if (c == 'A') ax = i, ay = j;
            if (c == 'B') bx = i, by = j;
        }
    }
    for (int i = 1; i <= n; i++) vis[i][0] = vis[i][m + 1] = true;
    for (int j = 1; j <= m; j++) vis[0][j] = vis[n + 1][j] = true;

    queue<pair<int, int>> q;
    q.push({ax, ay});
    vis[ax][ay] = 1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == bx && j == by) {
            cout << "YES\n";
            vector<char> path;
            while (i != ax || j != ay) {
                int a = par[i][j];
                i -= dx[a];
                j -= dy[a];
                path.push_back(dc[1 - a % 2 + 2 * (a / 2)]);
            }
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (auto e : path) cout << e;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = dx[d] + i;
            int ny = dy[d] + j;
            if (!vis[nx][ny]) {
                vis[nx][ny] = true;
                par[nx][ny] = d;
                q.push({nx, ny});
            }
        }
    }
    cout << "NO\n";
}