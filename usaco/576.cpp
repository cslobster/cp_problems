#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> h, st, ed, ans;

void dfs(int node, int par) {
    for (auto ch : adj[node]) {
        if (ch != par) {
            up[ch][0] = node;
            h[ch] = h[node] + 1;
            dfs(ch, node);
        }
    }
}

int dfs2(int node, int par) {
    int send = st[node] - ed[node];
    ans[node] = st[node] - ed[node] / 2;
    for (auto ch : adj[node]) {
        if (ch != par) {
            int temp = dfs2(ch, node);
            send += temp;
            ans[node] += temp;
        }
    }
    return send;
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    int k = h[a] - h[b];
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) a = up[a][i];
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

int main() {
    ifstream cin("maxflow.in");
    ofstream cout("maxflow.out");
    cin >> n >> k;
    adj.resize(n + 1);
    up.resize(n + 1, vector<int>(20));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    st.resize(n + 1);
    h.resize(n + 1);
    ed.resize(n + 1);
    ans.resize(n + 1);
    dfs(1, -1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        int c = lca(a, b);
//        cout << a << " " << b << " " << c << endl;
        st[a]++, st[b]++, ed[c] += 2;
    }
    dfs2(1, -1);
    int sol = 0;
    for (int i = 1; i <= n; i++) {
        sol = max(sol, ans[i]);
    }
    cout << sol << endl;
}