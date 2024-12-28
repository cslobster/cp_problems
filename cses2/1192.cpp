#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char grid[MXN][MXN];
bool vis[MXN][MXN];
int ans = 0;

void dfs(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;
    for (int d = 0; d < 4; d++) {
        dfs(i + dx[d], j + dy[d]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            vis[i][j] = (c == '#');
        }
    }
    for (int i = 1; i <= n; i++) vis[i][0] = vis[i][m + 1] = true;
    for (int i = 1; i <= m; i++) vis[0][i] = vis[n + 1][i] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}