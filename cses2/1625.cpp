#include <bits/stdc++.h>
using namespace std;

int vis[7][7];
string s;
int ans = 0;

bool av(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j];
}

void dfs(int i, int j, int steps) {
    if (i == 6 && j == 0) {
        if (steps == 48) ans++;
        return;
    }
    vis[i][j] = 1;
    if (s[steps] == '?' || s[steps] == 'L') {
        if (j && !vis[i][j - 1]) {
            if (!(!av(i, j - 2) && av(i + 1, j - 1) && av(i - 1, j - 1))) {
                dfs(i, j - 1, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'R') {
        if (j < 6 && !vis[i][j + 1]) {
            if (!(!av(i, j + 2) && av(i + 1, j + 1) && av(i - 1, j + 1))) {
                dfs(i, j + 1, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'U') {
        if (i && !vis[i - 1][j]) {
            if (!(!av(i - 2, j) && av(i - 1, j + 1) && av(i - 1, j - 1))) {
                dfs(i - 1, j, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'D') {
        if (i < 6 && !vis[i + 1][j]) {
            if (!(!av(i + 2, j) && av(i + 1, j + 1) && av(i + 1, j - 1))) {
                dfs(i + 1, j, steps + 1);
            }
        }
    }
    vis[i][j] = 0;
}

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << endl;
}