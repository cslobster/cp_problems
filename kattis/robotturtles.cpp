#include <bits/stdc++.h>
using namespace std;

int dist[8][8][4];
char grid[8][8];

struct state {
    int d, x, y, dir;
    string path;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

priority_queue<state> pq;

void upd(int len, int dir, string path, int nx, int ny, char c) {
    if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) return;
    if (grid[nx][ny] == 'C') return;
    if (grid[nx][ny] == 'I' && c == 'F') {
        path += 'X';
        len++;
    }
    path += c;
    len++;
    if (dist[nx][ny][dir] > len) {
        dist[nx][ny][dir] = len;
        state nxt = {len, nx,ny, dir, path};
        pq.push(nxt);
    }
}
bool operator<(const state &a, const state &b) {
    return a.d > b.d;
}

int main() {
    int di, dj;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'D') {
                di = i, dj = j;
            }
        }
    }
    state start = {0, 7,  0, 0, ""};
    pq.push(start);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++)
                dist[i][j][k] = 100;
        }
    }
    dist[7][0][0] = 0;
    while (!pq.empty()) {
        auto [d, x, y, dir, path] = pq.top();
//        cout << x << " " << y << " " << dir << " " << path << endl;
        pq.pop();
        if (x == di && y == dj) {
            cout << path << endl;
            return 0;
        }
        // turn left
        upd(d, (dir + 3) % 4, path, x, y, 'L');
        // turn right
        upd(d, (dir + 1) % 4, path, x, y, 'R');
        // move forward
        upd(d, dir, path, x + dx[dir], y + dy[dir], 'F');
    }
    cout << "no solution" << endl;
}