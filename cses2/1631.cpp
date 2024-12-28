#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n;
ll t[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    ll a = accumulate(t, t + n, 0LL), b = *max_element(t, t + n);
    cout << (long long) max(a, 2LL * b) << endl;
}