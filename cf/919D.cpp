#include <bits/stdc++.h>
using namespace std;

int n, m; string s;
vector<vector<int>> adj;

int f(char c, vector<int> in) {
    queue<int> q;
    vector<int> vis(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
        if (s[i] == c) dp[i] = 1;
    }
    int cnt = 0;
    while (!q.empty()) {
        int tp = q.front();
        vis[tp] = true;
        cnt++;
        q.pop();
        for (auto ch : adj[tp]) {
            if (vis[ch]) return -1;
            in[ch]--;
            if (s[ch] == c) dp[ch] = max(dp[ch], dp[tp] + 1);
            else dp[ch] = max(dp[ch], dp[tp]);
            if (in[ch] == 0) q.push(ch);
        }
    }
    if (cnt != n) return -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    adj.resize(n + 1);
    vector<int> in(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        int cur = f(c, in);
        if (cur == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}