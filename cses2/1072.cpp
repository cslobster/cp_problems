#include <bits/stdc++.h>
using namespace std;

/*
 a b c b a
 b d e d b
 c e x e c
 b d e d b
 a b c b a

 a = 2, b = 3, c = 4, d = 4, e = 6, x = 8
 */

using ll = long long;

int main() {
    int n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll abd = 4 * (2 + 2 * 3 + 4);
        ll c = 4 * (i - 4) * 4;
        ll e = 4 * (i - 4) * 6;
        ll x = (i - 4) * (i - 4) * 8;
        ll total = (i * i) * (i * i - 1) / 2;
        ll abcdex = abd + c + e + x;
        ll xx = abcdex / 2;
        ll ans = total - xx;
        cout << ans << endl;
    }
}