#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3, MOD = 1e9 + 7;

int n;
string s;
int leftBound = 0; // leftmost valid point
ll dp[MXN];
vector<int> badPoints;
int canTransition[MXN];
ll sum[2];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> s;
    s = " " + s;;
    dp[0] = sum[0] = canTransition[0] = 1;
    int lastR = 0;
    for (int i = 1; i <= n; i++) {
        canTransition[i] = true;
        if (i - 1 >= 1 && s[i - 1] == 'B') badPoints.push_back(i - 1);
        vector<int> newPoints;
        for (auto point : badPoints) {
            int np = point - 1;
            if (np >= 0 && canTransition[np]) {
                canTransition[np] = false;
                if (np >= leftBound) {
                    // anything >= leftBound has not been subtracted yet, so subtract now
                    sum[np % 2] = (sum[np % 2] - dp[np] + MOD) % MOD;
                }
                newPoints.push_back(np);
            }
        }
        badPoints = newPoints;
        if (s[i] == 'R') lastR = i;
        int bound = max(i - 2 * (i - lastR + 1) + 1, 0);
        // consider from bound...i
        while (leftBound < bound) {
            sum[leftBound % 2] = (sum[leftBound % 2] - dp[leftBound] * canTransition[leftBound] + MOD) % MOD;
            leftBound++;
        }
        while (leftBound > bound) {
            leftBound--;
            sum[leftBound % 2] = (sum[leftBound % 2] + dp[leftBound] * canTransition[leftBound] + MOD) % MOD;
        }

        // update sum
        dp[i] += sum[i % 2];
        dp[i] %= MOD;
        if (s[i] == 'X') dp[i] += dp[i - 1];
        dp[i] %= MOD;

        sum[i % 2] = (sum[i % 2] + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
}