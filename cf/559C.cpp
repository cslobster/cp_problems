#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2003, MXM = 2e6, MOD = 1e9 + 7;

ll f[MXM];

void init() {
    f[0] = 1;
    for (int i = 1; i < MXM; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
}

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

ll inv(ll a) {
    return power(a, MOD - 2) % MOD;
}
ll c(int a, int b) {
    // assert(a >= b);
    if (a < b) {
        cout << a << " " << b << " " << endl;
    }
    ll ans = f[a];
    ans = (ans * inv(f[b])) % MOD;
    ans = (ans * inv(f[a - b])) % MOD;
    return ans;
}

struct Loc {
    int x, y;
};

bool operator<(const Loc &a, const Loc &b) {
    if (a.x < b.x && a.y < b.y) return true;
    if (a.x > b.x && a.y > b.y) return false;
    if (a.x == b.x) return a.y < b.y;
    if (a.y == b.y) return a.x < b.y;
    return false;
}

int h, w, n;
Loc sq[MXN];
ll dp[MXN];

ll dist(Loc a, Loc b) {
    if (a.x == b.x) return a.y - b.y;
    if (a.y == b.y) return a.x - b.x;
    return c(a.y - b.y + a.x - b.x, a.y - b.y);
}

int main(int argc, char *argv[]) {
    ifstream cin("./in.in");
    init();
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sq[i].x >> sq[i].y;
    }
    sq[0] = {1, 1}, sq[n + 1] = {h, w};
    sort(sq, sq + n + 2);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = dist(sq[i], {1, 1}) % MOD;
        for (int j = 0; j < i; j++) {
            if (sq[i].x < sq[j].x || sq[i].y < sq[j].y) continue;
            dp[i] = ((dp[i] - (dp[j] * dist(sq[i], sq[j])) % MOD) % MOD + MOD) % MOD;
        }
        cout << dp[i] << endl;
    }
    cout << dp[n + 1] << endl;
    return 0;
}