#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> par, sz;
vector<vector<int>> edges;
vector<int> loc;

int getPar(int a) {
    if (par[a] == a) return a;
    return par[a] = getPar(par[a]);
}

void merge(int a, int b) {
    int pa = getPar(a);
    int pb = getPar(b);
    if (pa == pb) return;
    if (sz[pa] > sz[pb]) swap(pa, pb);
    par[pb] = pa;
    sz[pa] += sz[pb];
}

bool check(int lim) {
    iota(par.begin(), par.end(), 0);
    sz.resize(n + 1, 1);
    for (auto edge : edges) {
        if (edge[2] >= lim) {
            merge(edge[0], edge[1]);
        }
    }
    vector<set<int>> nodes(n + 1), cows(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[getPar(i)].insert(i);
        cows[getPar(i)].insert(loc[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (getPar(i) == i) {
            if (nodes[i] != cows[i]) return false;
        }
    }
    return true;
}

int main() {
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    cin >> n >> m;
    par.resize(n + 1);
    edges.resize(m + 1, vector<int>(3));
    loc.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a; loc[i + 1] = a;
    }

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int l = 0;
    int r = 1e9 + 1;
    while (l != r) {
        int mid = (l + r + 1)/2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    if (l == 1e9 + 1) cout << -1 << endl;
    else cout << l << endl;
}