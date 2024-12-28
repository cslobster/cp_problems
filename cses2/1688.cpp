#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, MXD = 32;

int n, q;
int h[MXN];
int up[MXN][MXD];
vector<int> adj[MXN];

void build() {
    for (int j = 1; j < MXD; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}


void dfs(int node) {
    for (auto ch : adj[node]) {
        h[ch] = h[node] + 1;
        dfs(ch);
    }
}

int lift(int a, int b) {
    for (int j = 0; j < MXD; j++) {
        if (b & (1 << j)) {
            a = up[a][j];
        }
    }
    return a;
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    int k = h[b] - h[a];
    b = lift(b, k);
    if (a == b) return a;
    for (int i = MXD - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) h[i] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
        adj[up[i][0]].push_back(i);
    }
    h[1] = 0;
    up[1][0] = 1;
    dfs(1);
    build();
    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}