#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 3;

int n, k;
int grid[MXN][MXN];
multiset<int> dp[MXN];

struct State {
    int v;
    multiset<int>::iterator c;
    int j;
};

bool operator<(const State &a, const State &b) {
    return a.v > b.v;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        dp[i].clear();
        for (int j = i; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    dp[0].insert(0);
    for (int i = 0; i < n; i++) {
        priority_queue<State> pq;
        if (i) pq.push({*dp[i - 1].begin(), dp[i - 1].begin(), i - 1});
        dp[i].insert(-grid[0][i]);
        if (i >= 1) {
            dp[i].insert(-grid[1][i]);
        }
        for (int j = 0; j + 2 <= i; j++) {
            assert(!dp[j].empty());
            pq.push({*dp[j].begin() - grid[j + 2][i], dp[j].begin(), j});
        }
        while (!pq.empty()) {
            auto [v, c, j] = pq.top();
            pq.pop();
            bool insert = false;
            if (dp[i].size() < k) {
                dp[i].insert(v);
                insert = true;
            } else {
                if (v < *dp[i].rbegin()) {
                    dp[i].erase(dp[i].find(*dp[i].rbegin()));
                    dp[i].insert(v);
                    insert = true;
                }
            }
            if (insert) {
                if (next(c) == dp[j].end()) continue;
                c++;
                if (j != i - 1) {
                    pq.push({*c - grid[j + 2][i], c, j});
                } else {
                    pq.push({*c, c, j});
                }
            }
        }
    }
    for (auto e : dp[n - 1]) {
        cout << -e << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}