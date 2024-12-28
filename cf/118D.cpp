#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

using ll = long long;

array<int, 2> n, k;

int d[2][2] = {{-1, 0}, {0, -1}};

ll memo[101][101][2][11];

ll f(array<int, 2> left, int cur, int cnt) {
    if (memo[left[0]][left[1]][cur][cnt] != -1) return memo[left[0]][left[1]][cur][cnt];
    if (left[0] == 0 && left[1] == 0) return 1;
    // cur, 0 = f, 1 = h
    ll ans = 0;
    if (left[cur] && cnt < k[cur]) {
        // as in, you can continue
        ans += f({left[0] + d[cur][0], left[1] + d[cur][1]}, cur, cnt + 1);
        ans %= MOD;
    }
    if (left[1 - cur]) {
        ans += f({left[0] + d[1 - cur][0], left[1] + d[1 - cur][1]}, 1 - cur, 1);
        ans %= MOD;
    }
    return memo[left[0]][left[1]][cur][cnt] = ans;
}

int main() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 11; l++) {
                    memo[i][j][k][l] = -1;
                }
            }
        }
    }
    cin >> n[0] >> n[1] >> k[0] >> k[1];
    int dp[101][101][10][2];
    cout << f(n, 0,0) % MOD << endl;
}