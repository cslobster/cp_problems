#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 4e6 + 3, MXM = 52, MOD = 1e9 + 7;

int conv(char c) {
    if ('a' <= c && 'z' >= c) {
        return c - 'a';
    }
    return c - 'A' + 26;
}

string s;
ll sum[MXN];

int main() {
    ifstream cin("sdistante.in");
    ofstream cout("sdistante.out");
    cin >> s;
    ll ans = 0, sumsum = 0;
    for (ll i = 1; i <= s.size(); i++) {
        int v = conv(s[i - 1]);
        ans += (sumsum - sum[v]) * (s.size() - i + 1);
        ans %= MOD;
        sumsum += i;
        sum[v] += i;
    }
    cout << ans << endl;
}