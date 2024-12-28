#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3;

int n;
ll a[MXN], b[MXN];
map<ll, int> c;
ll sum = 0;

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    rotate(a, next(min_element(a, a + n)), a + n);
    int ind = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) ind = i;
        if (i < n) {
            b[i] = ind;
            c[b[i] - i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        sum -= c[i];
        cout << sum << endl;
    }
}