#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> order, st, ed, type, h;
vector<vector<int>> adj, up;
int t = 0;

void dfs(int node, int par) {
    order.push_back(type[node]);
    st[node] = t++;
    for (auto ch : adj[node]) {
        if (ch != par) {
            up[ch][0] = node;
            dfs(ch, node);
        }
    }
    ed[node] = t;
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

int bs(vector<pair<int, int>> pre, int goal) {
    int l = 0;
    int r = pre.size() - 1  ;
    while (l != r) {
        int mid = (l + r + 1)/2;
        if (pre[mid].first <= goal) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return pre[l].second;
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m;
    type.resize(n + 1), st.resize(n + 1), ed.resize(n + 1), adj.resize(n + 1);
    up.resize(n + 1, vector<int>(20, 1)), h.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> type[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);

    vector<vector<pair<int, int>>> cows(n + 1);
    for (int i = 1; i <= n; i++) {
        cows[type[i]].push_back({st[i], ed[i]});
    }
    vector<vector<pair<int, int>>> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        if (events[i].size() == 0 || events[i].count(0) == 0) {
            pre[i].push_back({0, 0});
        }
        for (auto &[j, amt] : events[i]) {
            cur += amt;
            pre[i].push_back({j, cur});
        }
    }
    bj();

    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        int c = lca(a, b);
        // from a to lca

        int cnt = bs(pre[d], st[a]) + bs(pre[d], st[b]);
        if (st[c]) cnt -= bs(pre[d], st[c] - 1) * 2;
        cout << (cnt > 0);
    }
}