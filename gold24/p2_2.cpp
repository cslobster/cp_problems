#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3, MOD = 1e9 + 7;

int n, q;
vector<int> blocs, rlocs;
int rind = 0;

ll pow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int countbtwn(int lastb, int b) {
    int bdist = b - lastb;
    while (rind < rlocs.size() && rlocs[rind] < lastb) rind++;
    if(rlocs[rind] > b || rlocs[rind] < lastb) {
        // all white
        return (bdist+2) / 2;
    }

    vector<int> r_pos;
    while (rind < rlocs.size() && rlocs[rind] < b) {
        r_pos.push_back(rlocs[rind]);
        rind++;
    }

    ll result = 1;

    //space b4 first r
    int first_space = rlocs[rind]-lastb;
    if(first_space > 0) {
        result = (result * (first_space + 1)) % MOD;
    }

    // space after last r
    int last_space = n - 1 - r_pos.back();
    if(last_space > 0) {
        result = (result * (last_space + 1)) % MOD;
    }

    for(int i = 1; i < r_pos.size(); i++) {
        int gap = r_pos[i] - r_pos[i-1] - 1;
        if(gap > 0) {
            result = (result * ((gap + 2) / 2)) % MOD;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    blocs.push_back(0);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == 'R') rlocs.push_back(i);
        if (c == 'B') {
            blocs.push_back(i);
        }
    }
    if (blocs.size() == 0 || blocs[blocs.size()-1] != n)
        blocs.push_back(n);
    vector<int> dp(blocs.size());
    for (int i = 0; i < blocs.size(); i++) {
        dp[i] = countbtwn(blocs[i-1], blocs[i]) + dp[i-1];
    }
    cout << dp[blocs.size()-1];
}