/*
 * generate a grid such that every path has a unique sum
 * use powers of two, each diagonal is alternating between 2^d and 0
 * 0 1 2 4 8
 * 0 0 0 0 0
 * 2 4 8 16 32
 * 0 0 0 0 0
 * 8 16 32 64
 *
 * note: the problem is interactive. it generates data BASED on your grid
 * basically it will find a path *based on your grid*, and give you the sum
 * and you retrace the path
 */



#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 26;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a);
        }
        a = (a * a);
        b /= 2;
    }
    return ans;
}

int n;
ll a[MXN][MXN];

int main() {
    cin >> n;
    for (int d = 0; d < 2 * n - 1; d++) {
        for (int i = 0; i < n; i++) {
            if (!(d - i >= 0 && d - i < n)) continue;
            int j = d - i;
            if (i % 2 == 0 && d != 0) a[i][j] = power(2, d);
            else a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int t; cin >> t;
    while (t--) {
        ll d; cin >> d;
        int i = 0, j = 0;
        cout << i + 1 << " " << j + 1 << endl;
        for (int xx = 0; xx < 2 * n - 2; xx++) {
            d /= 2;
            if (d % 2 == (i % 2)) {
                i++;
            } else {
                j++;
            }
            cout << i + 1 << " " << j + 1 << endl;
        }
    }
}