#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            mp[a]++;
        }
        vector<pair<int, int>> f;
        for (auto p : mp) {
            f.push_back(p);
        }
        int ans = 0;
        for (int x = 0; x < f.size(); x++) {
            if (x == f.size() - 1 || f[x].first != f[x + 1].first - 1) {
                ans = max(ans, min(f[x].second, k / f[x].first) * f[x].first);
                continue;
            }
            for (int i = 0; i <= min(f[x].second, k / f[x].first); i++) {
                int j = min(f[x + 1].second, (k - i * f[x].first) / f[x + 1].first);
                ans = max(ans, j * f[x + 1].first + i * f[x].first);
            }
        }
        cout << ans << "\n";
    }
}