#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
int n;
vector<int> l;

int comp(int a, int b) {
    if (a > b) return 2;
    return a == b;
}

void add(int &a, int b) {
    a = (a + b) % MOD;
}

void solve(vector<vector<int>> &DP, int t) {
    string b = to_string(t);
    int d = b.size();
    for (int i = 0; i < n; i++) {
        int dp[19][19][3];
        memset(dp, 0, sizeof(dp));
        for (int j = i; j < n; j++) {
            for (int x = 0; x < d; x++) {
                for (int y = d - 1; y > x; y--) {
                    if (b[x] - '0' == l[j])
                        for (int k = 0; k < 3; k++)
                            add(dp[x][y][k], dp[x + 1][y][k]);
                    else if (l[j] > b[x] - '0')
                        for (int k = 0; k < 3; k++)
                            add(dp[x][y][2], dp[x + 1][y][k]);
                    else
                        for (int k = 0; k < 3; k++)
                            add(dp[x][y][0], dp[x + 1][y][k]);
                    add(dp[x][y][0], dp[x][y - 1][0]);
                    add(dp[x][y][2], dp[x][y - 1][2]);
                    add(dp[x][y][comp(l[j], b[y] - '0')], dp[x][y - 1][1]);
//                    printf("%d, %d, %d, %d, %d\n", x, y, dp[x][y][0], dp[x][y][1], dp[x][y][2]);
                }
            }
            for (int x = 0; x < d; x++) {
                add(dp[x][x][comp(l[j], b[x] - '0')], 2);
            }
            for (int k = 0; k < d; k++) {
                add(DP[i][j], dp[k][d - 1][0]);
                add(DP[i][j], dp[k][d - 1][1]);
                if (k) add(DP[i][j], dp[k][d - 1][2]);
//                printf("%d %d %d\n", i, j, DP[i][j]);
            }
        }
    }
}

signed main() {
    int a, b;
    cin >> n >> a >> b;
    l.resize(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    vector<vector<int>> A(n + 1, vector<int>(n + 1)), B(n + 1, vector<int>(n + 1));
    solve(A, a - 1); solve(B, b);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << (B[x][y] - A[x][y] + MOD) % MOD << endl;
    }
}