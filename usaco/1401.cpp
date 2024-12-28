#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e4 + 3;

struct Edge {
    int to; ll d;
};

struct State {
    ll d; int node, root;
};

bool operator<(const State &a, const State &b) {
    if (a.d != b.d) return a.d > b.d;
    if (a.node != b.node) return a.node > b.node;
    return a.root > b.root;
}

int n, m, c, r, k;
vector<Edge> adj[MXN];
int cnt[MXN];
vector<int> ans;
unordered_set<int> vis[MXN];

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");

    cin >> n >> m >> c >> r >> k;

    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << adj[i].size() << " ";
    //     if (!adj[i].empty()) cout << adj[i][0].to << endl;
    //     else cout << "EMPTY" << endl;
    // }
    priority_queue<State> pq;
    for (int i = 1; i <= c; i++) {
        pq.push({0, i, i});
    }

    while (!pq.empty()) {
        auto [d, node, root] = pq.top();
        // cout << d << " " << node << " " << root << endl;
        pq.pop();
        if (vis[node].count(root) > 0) continue;
        if (cnt[node] >= k) continue;
        vis[node].insert(root);
        cnt[node]++;
        if (cnt[node] == k && node > c) {
            ans.push_back(node);
        }
        for (auto &[ch, d2] : adj[node]) {
            // cout << node << " " << ch << endl;
            if (cnt[ch] >= k) continue;
            if (d2 + d > r) continue; // can't reach

            pq.push({d2 + d, ch, root});
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << e << endl;
    }
}