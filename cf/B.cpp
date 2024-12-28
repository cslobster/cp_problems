#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, k;
        cin >> n >> x >> y >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > x || a < y || a == k) continue;
            mp[a]++;
        }
        if (mp[x] == 0 || mp[y] == 0) {
            cout << "0\n"; continue;
        }
        int ans = (mp[x] - 1) * (mp[y] - 1);
        for (auto &[u, v] : mp) {
            if (u != x && u != y) {
                ans *= v;
            }
        }
        cout << ans << endl;
    }
}