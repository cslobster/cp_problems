#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n, m;
vector<int> adj[MXN];
int in[MXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        ans.push_back(tp);
        for (auto ch : adj[tp]) {
            in[ch]--;
            if (in[ch] == 0) q.push(ch);
        }
    }
    if (ans.size() != n) cout << "IMPOSSIBLE\n";
    else {
        for (auto e : ans) {
            cout << e << " ";
        }
    }
}