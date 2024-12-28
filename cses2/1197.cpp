#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2503, MXE = 5003;

int n, m;
vector<pair<int, ll>> adj[MXN];
array<int, 3> edges[MXE];
ll dist[MXN];
int par[MXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = 1e18;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    dist[1] = 0;
    par[1] = 1;
    for (int k = 1; k < n; k++) {
        for (int e = 0; e < m; e++) {
            auto &[a, b, c] = edges[e];
            if (dist[a] + c < dist[b]) {
                par[b] = a;
                dist[b] = dist[a] + c;
            }
        }
    }
    bool found = false;
    int st = -1;
    for (int e = 0; e < m; e++) {
        auto &[a, b, c] = edges[e];
        if (dist[a] + c < dist[b]) {
            par[b] = a;
            st = b;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) st = par[st];
    vector<int> path;
    int node = par[st];
    while (st != node) {
        path.push_back(node);
        node = par[node];
    }
    cout << st << " ";
    reverse(path.begin(), path.end());
    for (auto e : path) cout << e << " ";
    cout << st;
}