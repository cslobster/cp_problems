#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;

int n, m;
int h[MX], s[MX], e[MX], type[MX];
int cnt = 0;
vector<int> st[MX], adj[MX];
vector<int> cows[MX];
vector<pair<int, int>> q[MX];
vector<array<int, 3>> qu;
int ans[MX][2];
int up[MX][20];

void dfs1(int node, int par) {
    s[node] = cnt++;
    for (auto ch : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            up[ch][0] = node;
            dfs1(ch, node);
        }
    }
    e[node] = cnt - 1;
}

void dfs2(int node, int par) {
    cows[type[node]].push_back(node);
    for (auto &[i, x] : q[node]) {
        int t = qu[i][2];
        if (cows[t].size()) {
            ans[i][x] = cows[t].back();
        }
    }
    for (auto ch : adj[node]) {
        if (ch != par) {
            dfs2(ch, node);
        }
    }
    cows[type[node]].pop_back();
}

void bj() {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    int k = h[b] - h[a];
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) b = up[b][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

bool isAnc(int a, int p) {
    return s[p] < s[a] && e[p] >= e[a];
}

int calc(int i) {
    int x = ans[i][0], y = ans[i][1], a = qu[i][0], b = qu[i][1];
    int c = lca(a, b);
    if (x == y) {
        return x == c;
    }
    return !isAnc(x, b) || !isAnc(y, a);
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> type[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, -1);
    bj();
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        q[a].push_back({i, 0});
        q[b].push_back({i, 1});
        qu.push_back({a, b, t});
    }
    dfs2(1, -1);
    for (int i = 0; i < m; i++) {
        cout << calc(i);
    }
}