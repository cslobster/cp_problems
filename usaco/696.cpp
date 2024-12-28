#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 1;

int n, cnt = 0;
int p[MX], st[MX], ed[MX], par[MX], scnt[MX];
vector<int> adj[MX];

struct BIT {
    vector<int> tree;
    BIT(int n) {
        tree.resize(4 * n + 5);
    }
    void upd(int a, int x) {
        for (; a <= tree.size(); a += a & -a) {
            tree[a] += x;
        }
    }
    int query(int a) {
        int ans = 0;
        for (; a; a -= a & -a) {
            ans += tree[a];
        }
        return ans;
    }
};

vector<int> ord;
int t = 0;

void dfs(int node, int par) {
    st[node] = t++;
    ord.push_back(node);
    for (auto ch : adj[node]) {
        if (ch != par) {
            dfs(ch, node);
            scnt[node] += scnt[ch];
        }
    }
    ed[node] = t - 1;
}

int main() {
    ifstream cin("promote.in");
    ofstream cout("promote.out");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scnt[i] = 1;
        cin >> p[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    dfs(1, -1);

    BIT bit(t);
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 1);
    sort(ind.begin(), ind.end(), [](int a, int b){return p[a] < p[b];});

    vector<int> ans(n + 1);
    for (auto i : ind) {
        ans[i] = bit.query(ed[i] + 2) - bit.query(st[i] + 1);
        bit.upd(st[i] + 2, 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << scnt[i] - 1 - ans[i] << endl;
    }
}