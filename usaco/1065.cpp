#include <bits/stdc++.h>
using namespace std;

int n, d;
char grid[1001][1001];
int rdist[1001][1001];
int shutTime = -1;

struct State {
    int x, y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    queue<State> q;
    cin >> n >> d;
    memset(rdist, 0x3f, sizeof(rdist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                rdist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (rdist[nx][ny] < rdist[x][y] + 1) {
                rdist[nx][ny] = rdist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

}