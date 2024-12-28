#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
int c[3][MXN];
vector<int> adj[MXN];
map<int, vector<int>> mp;
int reachable[MXN], keys[MXN], visited[MXN];
int pos[2][MXN];

void bfs(int xx, int a, int b) {
    memset(reachable, 0, sizeof(reachable));
    memset(keys, 0, sizeof(keys));
    memset(visited, 0, sizeof(visited));
    mp.clear();

    for (int i = 1; i <= n; i++) {
        mp[c[a][i]].push_back(i);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int i = q.front();
        visited[i] = 1;
        q.pop();
        // get the key
        keys[c[b][i]] = 1;
        // can you reach any new rooms?
        for (auto j : mp[c[b][i]]) {
            if (reachable[j] && !visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
        // what about your neighbors?
        for (auto j : adj[i]) {
            if (visited[j] || (xx == 1 && pos[0][j] == 0)) continue;
            reachable[j] = 1;
            if (keys[c[a][j]] || (xx == 1 && c[a][j] == c[b][j])) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) pos[xx][i] = 1;
    }
}

bool solve() {
    memset(pos[0], 0, sizeof(pos[0]));
    memset(pos[1], 0, sizeof(pos[1]));
    memset(c[0], 0, sizeof(c[0]));
    memset(c[1], 0, sizeof(c[1]));
    memset(c[2], 0, sizeof(c[2]));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cin >> c[0][i];
    }
    for (int i = 1; i <= n; i++) cin >> c[1][i];
    for (int i = 1; i <= n; i++) cin >> c[2][i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0, 0, 1);
    bfs(1, 0, 2);

    for (int i = 1; i <= n; i++) {
        if (pos[0][i]) {
            if (!pos[1][i]) return false;
        } else {
            if (c[1][i] != c[2][i]) return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}