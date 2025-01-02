#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 4e5 + 3, MXA = 20, MXM = (1 << 20);

int n;
int a[MXN], inside[MXA];
ll cost[MXA][MXM], dif[MXA][MXA], dp[MXM];
map<int, vector<int>> mp;

int main() {
    cin >> n;
    int all = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (inside[a[i]] == 0) all += (1 << a[i]);
        inside[a[i]] = 1;
        mp[a[i]].push_back(i);
    }
    for (int i = 0; i < MXA; i++) {
        for (int j = 0; j < MXA; j++) {
            if (i == j) continue;
            if (mp[i].empty() || mp[j].empty()) continue;
            vector<pair<int ,int>> v;
            for (auto e : mp[i]) {
                v.push_back({e, 0});
            }
            for (auto e : mp[j]) {
                v.push_back({e, 1});
            }
            sort(v.begin(), v.end());
            ll ans = 0, zi = 0;
            for (int xx = 0; xx < v.size(); xx++) {
                if (v[xx].second == 0) {
                    ans += xx - zi;
                    zi++;
                }
            }
            dif[i][j] = ans;
        }
    }
    for (int mask = 0; mask <= all; mask++) {
        dp[mask] = 1e18;
        bool flag = false;
        for (int i = 0; i < MXA; i++) {
            if (mask & (1 << i) && mp[i].empty()) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int i = 0; i < MXA; i++) {
            if (mp[i].empty()) continue;
            if (!(mask & (1 << i))) {
                ll sum = cost[i][mask ^ (1 << i)];
                for (int j = 0; j < MXA; j++) {
                    if (!mp[j].empty() && (mask & (1 << j))) {
                        sum += dif[i][j];
                    }
                }
                // bitset<4> mm(mask);
                // cout << mm << " " << i << " " << sum << endl;
                cost[i][mask] = sum;
            }
        }
    }
    dp[0] = 0;
    for (int mask = 0; mask <= all; mask++) {
        bool flag = false;
        for (int i = 0; i < MXA; i++) {
            if (mask & (1 << i) && mp[i].empty()) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int i = 0; i < MXA; i++) {
            if (!mp[i].empty() && !(mask & (1 << i))) {
                int inv = (all) ^ (mask ^ (1 << i));
                dp[mask ^ (1 << i)] = min(dp[mask ^ (1 << i)], dp[mask] + cost[i][inv]);
                // bitset<4> mm(mask ^ (1 << i));
                // cout << mm << " = " << dp[mask ^ (1 << i)] << " when just added " << i << endl;
            }
        }
    }
    cout << dp[all] << endl;
}