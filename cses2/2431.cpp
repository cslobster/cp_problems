#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll pow10[19];

void init() {
    pow10[0] = 1;
    for (int i = 1; i <= 18; i++) pow10[i] = pow10[i - 1] * 10;
}

void solve(ll n) {
    ll sum = 0;
    ll digCount = 1;
    while (sum < n) {
        digCount += 1;
        sum += 9LL * pow10[digCount - 2] * (digCount - 1);
        if (sum >= n) {
            digCount--;
            sum -= 9LL * pow10[digCount - 1] * (digCount);
            break;
        }
    }
    assert(digCount > 0);
    n -= sum;
    ll digInd, num;
    digInd = (n - 1) % digCount;
    num = (n - 1) / digCount;
    // digIndth digit of the numth digCount-digit number
    num += pow10[digCount - 1];
    string s = to_string(num);
    // cout << n + sum << " " << num << " " << digInd << " " << digCount << endl; return;

    cout << s[digInd] << endl;
}

int main() {
    init();
    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        solve(n);
    }
    // for (int i = 0; i <= 120; i++) {
    //     solve(i);
    //     if (i % 50 == 0) cout << endl;
    // }
}