#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1), pre(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == c) {
            pre[i]++;
        }
        mp[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];

    int ans = 0;
    for (auto k : mp) {
        int cnt = 0;
        int l = 0;
        for (auto v : k.second) {
            l = max(l, pre[v - 1] - cnt);
            cnt++;
            ans = max(ans, l + cnt + pre[n] - pre[v]);
//            cout << l << " " << ans << endl;
        }
    }
    cout << ans << endl;
}