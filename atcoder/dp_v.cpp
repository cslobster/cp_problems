#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<vector<int>> adj;
vector<int> dp1, dp2;

int mult(int &a, int b) {
    return a = (a * b) % m;
}

int add(int &a, int b) {
    return a = (a + b) % m;
}

int dfs1(int node, int par) {
    int cur = 1;
    for (auto ch : adj[node]) {
        if (ch != par) {
            mult(cur, dfs1(ch, node));
        }
    }
    return dp1[node] = add(cur, 1) % m;
}


void dfs2(int node, int par) {
    vector<int> pre, suf;
    for (auto ch : adj[node]) {
        if (ch != par) {
            pre.push_back(dp1[ch]);
            if (pre.size() >= 2) mult(pre[pre.size() - 1], pre[pre.size() - 2]);
        }
    }
    for (int j = adj[node].size() - 1; j >= 0; j--) {
        int ch = adj[node][j];
        if (ch != par) {
            suf.push_back(dp1[ch]);
            if (suf.size() >= 2) mult(suf[suf.size() - 1], suf[suf.size() - 2]);
        }
    }
    reverse(suf.begin(), suf.end());
    int i = 0;
    for (int j = 0; j < adj[node].size(); j++) {
        int ch = adj[node][j];
        if (ch != par) {
            int temp = 1;
            if (i - 1 >= 0) mult(temp, pre[i - 1]);
            if (i + 1 < suf.size()) mult(temp, suf[i + 1]);
            dp2[ch] = 1 + (dp2[node] * temp) % m;
            dp2[ch] %= m;
            dfs2(ch, node);
            i++;
        }
    }
}

signed main() {
    cin >> n >> m;
    adj.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1, 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        int ans = (dp1[i] - 1 + m) % m;
        mult(ans, dp2[i]);
        cout << (ans + m) % m<< endl;
    }
}