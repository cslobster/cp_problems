#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

int dfs(int node, int par, int x) {
    int ans = 0;
    for (auto ch : adj[node]) {
        if (ch != par) {
            ans += dfs(ch, node, x);
        }
    }
    ans %= x;
    return ans;
}


int main() {
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n - 1; i++) {
        if ((n - 1) % i == 0 && dfs(1, -1, i) == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}