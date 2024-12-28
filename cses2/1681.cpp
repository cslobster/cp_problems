#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3, MOD = 1e9 + 7;

int n, m;
vector<int> adj[MXN];
ll dp[MXN]; int in[MXN];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    dp[1] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        for (auto ch : adj[tp]) {
            dp[ch] += dp[tp];
            dp[ch] %= MOD;
            in[ch]--;
            if (in[ch] == 0) q.push(ch);
        }
    }
    cout << dp[n] << endl;
}