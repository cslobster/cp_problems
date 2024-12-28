#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MXN = 1e6 + 3, MOD = 1e9 + 7;

int n;
ll b[MXN], f[MXN], fp[MXN];

ll pow(ll a, ll b) {
    ll ans = 1;
    a %= MOD;
    while (b) {
        if (b % 2 == 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans % MOD;
}

ll inv(ll a) {
    return pow(a, MOD - 2);
}


void prep() {
    f[0] = 1;
    for (int i = 1; i < MXN; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }

    fp[MXN - 1] = inv(f[MXN - 1]);
    for (int i = MXN - 2; i >= 0; i--) {
        fp[i] = (i * fp[i + 1]) % MOD;
    }
}

ll c(ll a, ll b) {
    assert(a >= b);
    ll tp = f[a];
    ll b1 = f[b], b2 = f[a - b];
    ll x = (tp  * inv(b1)) % MOD;
    return (x * inv(b2)) % MOD;
}

int main() {
    prep();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] /= 2;
    }

    ll ans = 1;

    for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
            ans = (ans * c(b[i], b[i + 1])) % MOD;
        } else {
            ans = (ans * c(b[i + 1] - 1, b[i] - 1)) % MOD;
        }
    }
    cout << ans << endl;
}