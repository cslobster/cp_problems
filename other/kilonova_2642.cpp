#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 3, MXM = 1e6 + 6;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int c, n, k;
int cnt[MXN][MXN], mxcnt;
array<int, 2> nxt[MXN][MXN];
int id[MXN][MXN]; // cycle id current node is on
int sz[MXM]; // sizes of cycles
array<int, 2> up[MXM][MXN][20]; // sizes of cycles
int dist[MXN][MXN]; // distance from cycle
bool treeRoot[MXN][MXN];
int ii = 1; // current cycle id
vector<array<int, 2>> pre[MXN][MXN];

int main() {
    cin >> c >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            id[i][j] = -1;
            dist[i][j] = -1;
            int d; cin >> d; d--;
            nxt[i][j] = {i + dx[d], j + dy[d]};
            cnt[nxt[i][j][0]][nxt[i][j][1]]++;
            mxcnt = max(mxcnt, cnt[nxt[i][j][0]][nxt[i][j][1]]);
            pre[nxt[i][j][0]][nxt[i][j][1]].push_back({i, j});
        }
    }
    if (c == 1) {
        cout << mxcnt << endl;
        return 0;
    }
    queue<pair<int, int>> qq;
    // locate cycles!
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (id[i][j] != -1) continue;
            vector<array<int, 2>> path;
            path.push_back({i, j});
            array<int, 2> cur = {i, j};
            while (id[nxt[cur[0]][cur[1]][0]][nxt[cur[0]][cur[1]][1]] == -1) {
                cur = nxt[cur[0]][cur[1]];
                id[cur[0]][cur[1]] = -2;
                path.push_back(cur);
            }
            bool inCyc = false;
            queue<array<int, 2>> q;
            for (auto node : path) {
                inCyc = inCyc || (node == nxt[cur[0]][cur[1]]);
                if (inCyc) {
                    dist[node[0]][node[1]] = 0;
                    sz[ii]++;
                    q.push({node[0], node[1]});
                }
            }
            while (!q.empty()) {
                auto &[x, y] = q.front();
                q.pop();
                id[x][y] = ii;
                if (dist[x][y] == 0 && pre[x][y].size() > 0) {
                    treeRoot[x][y] = true;
                }
                for (auto &[cx, cy] : pre[x][y]) {
                    if (dist[cx][cy] == -1) {
                        dist[cx][cy] = dist[x][y] + 1;
                        q.push({cx, cy});
                    }
                }
            }
            ii++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 0) {
                ans += min(k, sz[id[i][j]]);
            } else {
                int temp = k - dist[i][j];
                if (temp <= 0) ans += dist[i][j];
                else {
                    ans += min(temp, sz[id[i][j]]);
                }
            }
        }
    }
    cout << ans << endl;
}