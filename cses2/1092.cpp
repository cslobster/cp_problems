#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll targSum = n * (n + 1) / 2;
    if (targSum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    targSum /= 2;
    ll left = targSum;
    ll i = n;
    vector<ll> inc(n + 1);
    set<ll> one, two;
    while (left) {
        // cout << left << endl;
        if (left - i >= 0) {
            inc[i] = 1;
            left -= i;
            one.insert(i);
        }
        i--;
    }
    cout << one.size() << endl;
    for (auto e : one) {
        cout << e << " ";
    }
    cout << endl << n - one.size() << endl;
    for (int x = 1; x <= n; x++) {
        if (!inc[x]) cout << x << " ";
    }
}