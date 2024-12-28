#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e9 + 3, MOD = 1e9 + 7, MXQ = 206, MXC = 1e4 + 3;

struct Pair {
    ll h, a;
};

bool operator<(const Pair &a, const Pair &b) {
    if (a.a != b.a) return a.a < b.a;
    return a.h < b.h;
}

int n, q, c;
ll dp[MXQ][MXC];
Pair p[MXQ];
vector<pair<int, int>> points;
set<pair<int, int>> s;

ll power(ll a, ll b) {
    assert(b >= 0);
    a %= MOD;
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int main() {
    cin >> n >> q >> c;
    p[0].h = 0;
    for (int i = 1; i <= q; i++) {
        cin >> p[i].a >> p[i].h;
    }
    sort(p, p + q + 1);
    for (int i = 1; i <= 5; i++) {
        cout << p[i].a << " " << p[i].h << endl;
    }
    s.insert({1, 0});
    s.insert({n, 0});
    for (int i = 1; i <= q; i++) {
        if (i != 1 && p[i].a < p[i - 1].h) {
            if (p[i].h == p[i - 1].h) {
                continue;
            }
            cout << 0 << endl; return 0;
        }
        if (!s.count({p[i].a, 1})) s.insert({p[i].a, 0});
        s.insert({p[i].h, 1});
        if (s.count({p[i].h, 0})) {
            s.erase({p[i].h, 0});
        }
    }
    for (auto e : s) {
        points.push_back(e);
    }
    for (int j = 1; j <= c; j++) dp[0][j] = 1;
    for (int k = 1; k < points.size(); k++) {
        if (points[k].second == 1) {
            for (int jp = 1; jp <= c; jp++) {
                for (int j = 1; j < jp; j++) {
                    ll mult = power(jp, points[k].first - points[k - 1].first - 1) % MOD;
                    dp[k][jp] += (dp[k - 1][j] * mult) % MOD;
                    dp[k][jp] %= MOD;
                }
                cout << points[k].first << " " << jp << " " << dp[k][jp] << endl;
            }
            // cout << points[k].first << " " << jp << " " << dp[k][jp] << endl;
            // }
        } else {
            for (int jp = 2; jp <= c; jp++) {
                ll mult = power(jp, points[k].first - points[k - 1].first) % MOD;
                dp[k][jp] += (dp[k - 1][jp] * mult) % MOD;
                dp[k][jp] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= c; j++) {
        ans += dp[points.size() - 1][j];
        ans %= MOD;
    }
    if (points[points.size() - 1].second == 0) cout << dp[points.size() - 1][c] % MOD << endl;
    else cout << ans << endl;
}