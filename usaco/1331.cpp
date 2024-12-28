#include <bits/stdc++.h>
using namespace std;

const int MXN = 1003;

int n, m;
vector<int> adji[MXN], adjf[MXN], height[MXN];
int pari[MXN], parf[MXN], inFin[MXN], h[MXN], outdegree[MXN], mergedInto[MXN];
int dp[MXN][MXN];
int root = -1, mxh = 0;
vector<int> ord;

void reset() {
    for (int i = 0; i < MXN; i++) {
        adji[i].clear(), adjf[i].clear(), height[i].clear();
        pari[i] = 0, parf[i] = 0, inFin[i] = 0, h[i] = 0, outdegree[i] = 0, mergedInto[i] = 0;
        for (int j = 0; j < MXN; j++) {
            dp[i][j] = 0;
        }
    }
    ord.clear();
}

void dfs(int node) {
    mxh = max(mxh, h[node]);
    height[h[node]].push_back(node);
    for (auto ch : adji[node]) {
        h[ch] = h[node] + 1;
        dfs(ch);
    }
}

void solve() {
    reset();
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adji[b].push_back(a);
        pari[a] = b;
        outdegree[a]++;
    }
    cin >> m;
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjf[b].push_back(a);
        parf[a] = b;
        inFin[a] = 1, inFin[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (outdegree[i] == 0) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    dfs(root);
    for (int x = mxh; x >= 0; x--) {
        sort(height[x].begin(), height[x].end());
        for (int a = 0; a < height[x].size(); a++) {
            int i = height[x][a];
            ord.push_back(i);
            if (inFin[i]) {
                dp[i][i] = 1;
                continue;
            }
            for (int b = a + 1; b < height[x].size(); b++) {
                int j = height[x][b];
                if (!inFin[j]) continue;
                dp[i][j] = 1;
                for (auto c : adji[i]) {
                    bool flag = false;
                    for (auto d : adjf[j]) {
                        if (dp[c][d]) flag = true;
                    }
                    if (flag == false) {
                        dp[i][j] = false;
                        break;
                    }
                }
            }
        }
    }
    reverse(ord.begin(), ord.end());
    vector<pair<int, int>> ans;
    for (auto a : ord) {
        if (inFin[a]) {
            mergedInto[a] = a; continue;
        }
        int b = mergedInto[pari[a]];
        for (auto c : adjf[b]) {
            if (dp[a][c]) {
                mergedInto[a] = c;
                ans.push_back({a, c});
                break;
            }
        }
        assert(ans.back().first == a);
    }
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e.first << " " << e.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}