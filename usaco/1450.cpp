#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3, MOD = 1e9 + 7;

struct BIT {
    int sz;
    vector<ll> tree;
    void init(int _sz) {
        sz = _sz;
        tree.resize(sz * 4);
    }
    void upd(int i, ll x) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += x;
        }
    }
    ll query(int i) {
        ll ans = 0;
        for (; i > 0; i -= i & -i) {
            ans += tree[i];
        }
        return ans;
    }
};

struct BIT2 {
    int sz;
    vector<ll> tree;
    void init(int _sz) {
        sz = _sz;
        tree.resize(sz + 1);
    }
    void upd(int i, ll x) {
        tree[i] += x;
    }
    ll query(int i) {
        ll ans = 0;
        while (i > 0) {
            ans += tree[i];
            i--;
        }
        return ans;
    }
};

int n;
string s;
ll dp[MXN];
vector<int> bPoints;
ll preDP[MXN][2];

ll sum(int l, int r, int i) {
    l += (l % 2 != i % 2);
    r -= (r % 2 != i % 2);
    if (l > r) return 0;
    return (preDP[r][i % 2] - (l - 1 >= 0 ? preDP[l - 1][i % 2] : 0) + MOD) % MOD;
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> s;
    s = " " + s;;
    dp[0] = preDP[0][0] = 1;
    int lastR = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            lastR = i;
        } else if (s[i] == 'B') {
            bPoints.push_back(i);
        } else if (s[i] == 'X') {
            dp[i] = dp[i - 1]; // can be W
        }
        // original sum: dp[i - 2] + dp[i - 4], etc
        // ok, so which ranges cannot be added anymore?
        // we cannot transition from a point <= i - 2(i - lastR + 1)
        int bound = i - 2 * (i - lastR + 1);
        int cur = -1;
        int st = lower_bound(bPoints.begin(), bPoints.end(), bound + 2) - bPoints.begin();
        dp[i] = (dp[i] + sum(bound + 1, i - 1, i)) % MOD;
        for (int j = st; j < bPoints.size(); j++) {
            int badL = max({2 * bPoints[j] - i, bound + 1, 0});
            int badR = bPoints[j] - 1;
            if (badL > cur) {
                cur = badL - 1;
            }
            if (badR >= cur) {
                dp[i] = (dp[i] - sum(cur + 1, badR, i) + MOD) % MOD;
                cur = badR;
            }
        }

        // update prefix sum
        for (int p = 0; p < 2; p++) {
            preDP[i][p] = (preDP[i - 1][p] + (p == i % 2 ? dp[i] : 0)) % MOD;
        }

    }
    cout << dp[n] << endl;
}