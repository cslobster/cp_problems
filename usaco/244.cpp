#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int cnt = 0;
map<array<int, 2>, int> mp;

void dfs(Point a) {
    if (mp[{a.x, a.y}] == 1) {
        // cout << a.x << " " << a.y << endl;
        cnt++; return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = a.x + dx[i];
        int ny = a.y + dy[i];
        if (mp[{nx, ny}] == 2 || mp[{nx, ny}] == 1) {
            if (mp[{nx, ny}] == 2) mp[{nx, ny}] = 3;
            // else cout << nx << " " << ny << " " << a.x << " " << a.y << endl;
            dfs({nx, ny});
        }
    }
}

int main() {
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    int n;
    cin >> n;
    vector<Point> hbs(n);
    int h = 0, j = 0;
    for (int i = 0; i < n; i++) {
        cin >> hbs[i].x >> hbs[i].y;
        mp[{hbs[i].x, hbs[i].y}] = 1;
        if (hbs[i].y > h) {
            h = hbs[i].y, j = i;
        }
    }

    for (auto a : hbs) {
        for (int i = 0; i < 8; i++) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            if (nx < 0 || ny < 0) continue;
            if (!mp[{nx, ny}]) mp[{nx, ny}]= 2;
        }
    }
    Point stx = {hbs[j].x, hbs[j].y + 1};
    mp[{stx.x, stx.y}] = 3;
    dfs(stx);
    cout << cnt << endl;
}