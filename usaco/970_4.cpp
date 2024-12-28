#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;

int n, m;
int h[MX], ind[MX], type[MX];
int cnt = 0;
vector<int> st[MX], adj[MX];
vector<pair<int, int>> cows[MX];
int up[MX][20];

void dfs(int node, int par) {
    ind[node] = cnt++;
    st[type[node]].push_back({node});
    cows[type[node]].push_back({ind[node], node});
    for (auto ch : adj[node]) {
        if (ch != par) {
            h[ch] = h[node] + 1;
            up[ch][0] = node;
            dfs(ch, node);
        }
    }
    st[type[node]].pop_back();
    cows[type[node]].push_back({cnt, st[type[node]].empty() ? 0 : st[type[node]].back()});
    // cows[type[node]].push_back({cnt, 0});
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

int last(int a, int t) {
    auto it = upper_bound(cows[t].begin(), cows[t].end(), make_pair(a, MX));
    if (it == cows[t].begin()) return 0;
    return (--it)->second;
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
    dfs(1, -1);
    bj();
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        int c = lca(a, b);
        int la = last(ind[a], t), lb = last(ind[b], t);
        if ((la && h[la] >= h[c]) || (lb && h[lb] >= h[c])) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}