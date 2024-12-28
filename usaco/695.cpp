#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int grid[21][21];

int n;

struct Loc {
    int x, y, d;
    void mv(int i) {
        if (i == 0) {
            if (x == 0 && y == n - 1) return;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) return;
            if (grid[nx][ny]) return;
            x = nx, y = ny;
        } else if (i == 1) {
            d = (d + 3) % 4;
        } else {
            d = (d + 1) % 4;
        }
    }
};

struct State {
    int l;
    Loc a; Loc b;
};

queue<State> pq;
int d[20][20][5][20][20][5];

string ds[3] = {"F", "L", "R"};

void mv(int l, Loc a, Loc b, int i) {
    a.mv(i), b.mv(i);
    // if (d[a.x][a.y][a.d][b.x][b.y][b.d] > l + 1) {
    if (d[a.x][a.y][a.d][b.x][b.y][b.d] == 0) {
        d[a.x][a.y][a.d][b.x][b.y][b.d] = l + 1;
        pq.push({l + 1, a, b});
    }
}

int main() {
    ifstream cin("cownav.in");
    ofstream cout("cownav.out");
    memset(d, 0, sizeof(d));
    // memset(d, 0x3f, sizeof(d));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == 'H') grid[i][j] = true;
        }
    }
    pq.push({0, {n - 1, 0, 0}, {n - 1, 0, 1}});
    int cnt = 0;
    while (!pq.empty()) {
        auto &[l, a, b] = pq.front();
        cnt++;
        // cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << a.d << endl;
        pq.pop();
        if (a.x == 0 && a.y == n - 1 && b.x == 0 && b.y == n - 1) {
            cout << l  << endl;
            break;
        }
        for (int i = 2; i >= 0; i--) {
            mv(l, a, b, i);
        }
    }
    // cout << cnt << endl;
}