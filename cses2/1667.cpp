#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
int par[MXN];
queue<int> q;

int main() {
    memset(par, 0, sizeof(par));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(1);
    par[1] = -1;
    while (!q.empty()) {
        int node = q.front();
        if (node == n) {
            vector<int> ans;
            while (node != -1) {
                ans.push_back(node);
                node = par[node];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (auto e : ans) cout << e << " ";
            return 0;
        }
        q.pop();
        for (auto ch : adj[node]) {
            if (par[ch] == 0) {
                par[ch] = node;
                q.push(ch);
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}