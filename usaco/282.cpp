#include <bits/stdc++.h>
using namespace std;

const int MX = 501;
int n, m;

bool vis[501][501][2];
int cx, cy, dx, dy;

char grid[MX][MX];

struct State {
    int x, y, g, cnt; bool out = false;
    bool fall() {
        int nx = x + (g == 0 ? 1 : -1);
        if (nx < 0 || nx >= n) {
            out = true; return false;
        }
        if (grid[nx][y] == '#') return false;
        x = nx;
        if (x == dx && y == dy) return false;
        return true;
    }
    void drop() {
        while (fall());
    }
    bool left() {
        int ny = y + 1;
        if (ny < 0 || ny >= n) {
            out = true; return false;
        }
        if (grid[x][ny] == '#') return false;
        y = ny;
        if (x == dx && y == dy) return false;
        return true;
    }
    bool right() {
        int ny = y - 1;
        if (ny < 0 || ny >= n) {
            out = true; return false;
        }
        if (grid[x][ny] == '#') return false;
        y = ny;
        if (x == dx && y == dy) return false;
        return true;
    }
    void flip() {
        cnt++;
        g = 1 - g;
        drop();
    }
};

bool v(State s) {
    return vis[s.x][s.y][s.g];
}

int main() {
    ifstream cin("gravity.in");
    ofstream cout("gravity.out");
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') cx = i, cy = j;
            if (grid[i][j] == 'D') dx = i, dy = j;
        }
    }
    queue<State> q;
    State st = {cx, cy, 0, 0};
    st.drop();
    q.push(st);
    vis[st.x][st.y][st.g] = true;
    while (!q.empty()) {
        State tp = q.front();
        // cout << tp.x << " " << tp.y << " " << tp.g << " " << v(tp) << endl;
        if (tp.x == dx && tp.y == dy) {
            cout << tp.cnt << endl;
            return 0;
        }
        tp.left(), tp.drop();
        if (!tp.out && !v(tp)) {
            vis[tp.x][tp.y][tp.g] = true; q.push(tp);
        }
        tp = q.front();
        tp.right(), tp.drop();
        if (!tp.out && !v(tp)) {
            vis[tp.x][tp.y][tp.g] = true; q.push(tp);
        }
        tp = q.front();
        tp.flip();
        if (!tp.out && !v(tp)) {
            vis[tp.x][tp.y][tp.g] = true; q.push(tp);
        }

        q.pop();
    }
    cout << -1 << endl;
}