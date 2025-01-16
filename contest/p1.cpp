#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 3, MXM = 1e4 + 3;

struct Edge {
    int to, i, d;
};

struct Edges {
    int from, to, d;
};

int n, m, q;
int in[MXN], out[MXN];
set<int> ogAdj[MXN];
set<int> adj[MXN], radj[MXN]; // all queries to this stronghold
Edges edges[MXM];

int main() {
    cin >> n >> m ;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ogAdj[b].insert(a);
        adj[b].insert(a);
        radj[a].insert(b);
        edges[i] = {a, b, 1};
        in[b]++, out[a]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> v >> u;
            adj[u].erase(v);
            radj[v].erase(u);
            in[v]--, out[u]--;
        } else if (t == 2) {
            int u; cin >> u;
            for (auto ch : adj[u]) {
                in[ch]--;
                radj[ch].erase(u);
            }
            out[u] = 0;
            adj[u].clear();
        } else if (t == 3) {
            int u, v; cin >> v >> u;
            adj[u].insert(v);
            radj[v].insert(u);
            in[v]++, out[u]++;
        } else {
            int u; cin >> u;
            for (auto ch : ogAdj[u]) {
                if (adj[u].count(ch)) continue;
                adj[u].insert(ch);
                radj[ch].insert(u);
                out[u]++, in[ch]++;
            }
        }
        bool flag = true;
        for (int node = 1; node <= n; node++) {
            if (in[node] != 1) {
                flag = false;
                break;
            }
            vector<int> vis(n + 1);
            queue<int> q;
            q.push(node);
            vis[node] = 1;
            bool works = true;
            while (!q.empty()) {
                auto tp = q.front();
                q.pop();
                for (auto ch : radj[tp]) {
                    if (vis[tp]) {
                        works = false;
                        break;
                    }
                    vis[tp] = true;
                    q.push(ch);
                }
                if (works == false) break;
            }
            if (works) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}