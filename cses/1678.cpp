#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
vector<int> ans;
int vis[MXN], onStack[MXN];
bool found = false;

bool dfs(int node) {
    vis[node] = 1;
    onStack[node] = 1;

    for (int ch : adj[node]) {
        if (onStack[ch]) {
            ans.push_back(node);
            onStack[node] = onStack[ch] = false;
            return true;
        }
        if (!vis[ch]) {
            if (dfs(ch)) {
                if (onStack[node]) {
                    ans.push_back(node);
                    onStack[node] = false;
                    return true;
                }
                ans.push_back(node);
                return false;
            }
        }
        if (!ans.empty()) {
            return false;
        }
    }
    onStack[node] = 0;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (!ans.empty()) {
            break;
        }
    }
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(ans.begin(), ans.end());
        cout << ans.size() + 1 << endl;
        for (auto node : ans) {
            cout << node << " ";
        }
        cout << ans[0] << endl;
    }
}