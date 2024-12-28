#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        if (a == b) {
            cout << ((a % 3 == 0) ? "YES" : "NO") << endl;
            continue;
        }
        ll c = a - b;
        a -= 2 * c;
        b -= c;
        if (a < 0) {
            cout << "NO" << endl; continue;
        }
        assert(a == b);
        cout << ((a % 3 == 0) ? "YES" : "NO") << endl;
    }
}