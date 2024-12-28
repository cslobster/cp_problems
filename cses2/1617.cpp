#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    ans %= MOD;
    return ans;
}

int main() {
    ll n; cin >> n;
    cout << power(2, n) << endl;
}