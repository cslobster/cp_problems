#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

using ll = long long;

int n;
pair<ll, ll> tasks[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks, tasks + n);
    ll ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        t += tasks[i].first;
        ans += tasks[i].second - t;
    }
    cout << ans << endl;
}