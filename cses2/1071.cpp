#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;
        ll ring = max(x, y);
        ll ringMax = ring * ring;
        ll ringMin = (ring - 1) * (ring - 1) + 1;
        if (ring % 2 == 0) swap(x, y);
        if (x > y) {
            // smaller side, go down by x - y
            cout << ringMax - min(x, y) + 1 << endl;
        } else {
            // larger side, go right by y - x
            cout << ringMin + min(x, y) - 1 << endl;
        }
    }
}