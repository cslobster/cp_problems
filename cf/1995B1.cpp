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
            vector<int> dp; set<int> s;
            dp.push_back(0), s.insert(0);
            for (int i = 0; i < f[x].second; i++) {
                int sz = dp.size();
                for (int j = 0; j < sz; j++) {
                    int v = dp[j] + f[x].first;
                    if (s.count(v) || v > k) continue;
                    dp.push_back(v);
                    s.insert(v);
                    ans = max(ans, v);
                }
            }
            if (x + 1 < f.size() && f[x].first + 1 == f[x + 1].first) {
                for (int i = 0; i < f[x + 1].second; i++) {
                    int sz = dp.size();
                    for (int j = 0; j < sz; j++) {
                        int v = dp[j] + f[x + 1].first;
                        if (s.count(v) || v > k) continue;
                        dp.push_back(v);
                        s.insert(v);
                        ans = max(ans, v);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}