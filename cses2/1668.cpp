#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
int color[MXN];

bool dfs(int node) {
    for (auto ch : adj[node]) {
        if (color[ch] == color[node]) return false;
        if (color[ch] != 0) continue;
        color[ch] = 3 - color[node];
        if (!dfs(ch)) return false;
    }
    return true;
}

int main() {
    memset(color, 0, sizeof(color));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            if (!dfs(i)) {
                cout << "IMPOSSIBLE\n"; return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
}