#include <bits/stdc++.h>
using namespace std;

const int MXN = 21, MXM = (1 << 20);

int n, b, i, j, mask;
int dp[MXM], s[MXN][MXN];
vector<pair<int, int>> bonus[MXN];

int award(int a, int x) {
    for (int i = 0; i < bonus[x].size(); i++) {
        if (a < bonus[x][i].first) break;
        a += bonus[x][i].second;
    }
    return a;
}

int main() {
    ifstream cin("dec.in");
    ofstream cout("dec.out");
    cin >> n >> b;
    for (int i = 0; i < b; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bonus[a].push_back({b, c});
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        sort(bonus[i].begin(), bonus[i].end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
    }
    for (mask = 1; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);
        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int score = dp[mask ^ (1 << i)] + s[i][cnt - 1];
                dp[mask] = max(dp[mask], score);
            }
        }
        dp[mask] = award(dp[mask], cnt);
    }
    cout << dp[(1 << n) - 1] << endl;
}