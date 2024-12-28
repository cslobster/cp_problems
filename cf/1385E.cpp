#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1);
        vector<pair<int, int>> un;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 0) un.push_back({b, c});
            else {
                adj[b].push_back(c);
                in[c]++;
            }
        }
        queue<int> q;
        vector<int> ind(n + 1, -1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                ind[i] = 0;
            }
        }
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            ind[tp] = cnt;
            cnt++;
            for (auto ch : adj[tp]) {
                in[ch]--;
                if (in[ch] == 0) {
                    q.push(ch);
                }
            }
        }
        if (cnt != n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (auto& [u, v] : un) {
            if (ind[u] < ind[v]) cout << u << " " << v << endl;
            else cout << v << " " << u << endl;
        }
        for (int i = 1; i <= n; i++) {
            for (auto j : adj[i]) {
                cout << i << " " << j << endl;
            }
        }
    }
}