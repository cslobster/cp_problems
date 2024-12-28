#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 2;

int n, t = 0;
vector<int> adj[MX];
int h[MX], st[MX], ed[MX];
int up[MX][20];

int dfs(int node, int par) {
    int ans = node;
    st[node] = t++;
    for (auto ch : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            up[ch][0] = node;
            int x = dfs(ch, node);
            if (h[x] > h[ans]) ans = x;
        }
    }
    ed[node] = t - 1;
    return ans;
}

void rh() {
    for (int i = 1; i <= n; i++) {
        h[i] = 0;
    }
}

void bj(int r) {
    up[r][0] = 1;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

bool isAnc(int a, int b) {
    return st[a] <= st[b] && ed[b] <= ed[a];
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    int k = h[b] - h[a];
    for (int i = 0; i <= 17; i++) {
        if (k & (1 << i)) b = up[b][i];
    }
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int mv(int a, int k) {
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) {
            a = up[a][i];
        }
    }
    return a;
}

int solve(int u, int k) {
    if (h[u] >= k) {
        return mv(u, k);
    }
    return -1;
}

int run(int node) {
    rh();
    int ans = dfs(node, -1);
    bj(node);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int a = run(1);
    int b = run(a);

    int q;
    cin >> q;
    vector<array<int, 2>> queries(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        ans[i] = solve(queries[i][0], queries[i][1]);
    }
    run(b);
    for (int i = 0; i < q; i++) {
        ans[i] = max(ans[i], solve(queries[i][0], queries[i][1]));
        cout << ans[i] << endl;
    }
}