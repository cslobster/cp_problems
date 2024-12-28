#include <bits/stdc++.h>
using namespace std;

const int MXN = 20, MOD = 1e9 + 7;

int n;
string s;
int memo[MXN][1 << MXN];

int solve(int pos, int mask) {
    // Base case: reached end of string
    if (pos == n) return 1;

    // Check memoized result
    if (memo[pos][mask] != -1) return memo[pos][mask];

    int ways = 0;

    // Option 1: Skip this point
    if (s[pos] == 'X') {
        ways = (ways + solve(pos + 1, mask)) % MOD;
    }

    // Option 2: Try placing a red interval
    if (s[pos] != 'B') {
        for (int len = 1; pos + len <= n; len++) {
            // Check if we can place a red interval of this length
            bool can_place = true;
            for (int j = 0; j < len; j++) {
                if (s[pos + j] == 'B' || (mask & (1 << (pos + j)))) {
                    can_place = false;
                    break;
                }
            }

            // If can place, recursively solve for next uncolored position
            if (can_place) {
                int new_mask = mask;
                for (int j = 0; j < len; j++) {
                    new_mask |= (1 << (pos + j));
                }
                ways = (ways + solve(pos + len, new_mask)) % MOD;
            }
        }
    }

    // Option 3: Try placing a blue interval
    if (s[pos] != 'R') {
        for (int len = 1; pos + len <= n; len++) {
            // Check if we can place a blue interval of this length
            bool can_place = true;
            for (int j = 0; j < len; j++) {
                if (s[pos + j] == 'R' || (mask & (1 << (pos + j)))) {
                    can_place = false;
                    break;
                }
            }

            // If can place, recursively solve for next uncolored position
            if (can_place) {
                int new_mask = mask;
                for (int j = 0; j < len; j++) {
                    new_mask |= (1 << (pos + j));
                }
                ways = (ways + solve(pos + len, new_mask)) % MOD;
            }
        }
    }

    // Memoize and return
    return memo[pos][mask] = ways;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // Read input
    cin >> n >> s;

    // Initialize memoization
    memset(memo, -1, sizeof(memo));

    // Solve and output
    cout << solve(0, 0) << endl;
    
    return 0;
}