#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> ans;
int start;
vector<int> path;

bool findcyclesize(int c) {
    auto it = find(path.begin(), path.end(), c);
    if (path.end() - it >= 3) {
        return true;
    }
    return false;
}

bool dfs(int node, int parent) {
    bool flag = false;
    visited[node] = true;
    for (auto c : adj[node]) {
        if (!visited[c] && c != parent) {
            path.push_back(c);
            flag = dfs(c, node);
            path.pop_back();
            if (flag) break;
        }
        else if (visited[c] && c != parent && findcyclesize(c)) {
            path.push_back(c);
            start = c;
            ans = path;
            flag = true;
            break;
        }
    }
    return flag;
}

signed main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        path.clear();
        path.push_back(i);
        if (!visited[i] && dfs(i, -1)) {
            auto it = find(ans.begin(), ans.end(), start);
            int z = it - ans.begin() + 1;
            vector<int> newans;
            newans.push_back(start);
            while (z < ans.size() && ans[z] != start) {
                newans.push_back(ans[z]);
                z++;
            }
            newans.push_back(start);
            if (newans.size() > 3) {
                cout << newans .size() << endl;
                for (auto e : newans) {
                    cout << e << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}