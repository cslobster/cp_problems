#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj[2], radj[2];
vector<int> in[2];

void f(int i, int n, vector<set<int>> &dp) {
    queue<int> q;
    for (int j = 1; j <= n; j++) {
        if (in[0][j] == 0) {
            q.push(j);
        }
    }
    dp[1].insert(0);
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        for (auto ch : adj[i][tp]) {
            for (auto e : dp[tp]) {
                dp[ch].insert(e + 1);
            }
            in[i][ch]--;
            if (in[i][ch] == 0) q.push(ch);
        }
    }
}

int main() {
    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;
    adj[0].resize(n1 + 1); adj[1].resize(n2 + 2);
    radj[0].resize(n1 + 1); radj[1].resize(n2 + 2);
    in[0].resize(n1 + 1); in[1].resize(n2 + 1);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        adj[0][a].push_back(b);
        radj[0][b].push_back(a);
        in[0][b]++;
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        adj[1][a].push_back(b);
        radj[1][b].push_back(a);
        in[1][b]++;
    }
    vector<set<int>> dp1(n1 + 1), dp2(n2 + 1);
    f(0, n1, dp1), f(1, n2, dp2);
    set<int> ans;
    for (auto e : dp1[n1]) {
        for (auto f : dp2[n2]) {
            ans.insert(e + f);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a; cin >> a;
        if (ans.count(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}