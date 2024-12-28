#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
vector<pair<int, int>> events;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 0});
        events.push_back({b, 1});
    }
    sort(events.begin(), events.end());
    int cnt = 0, ans = 0;
    for (auto e : events) {
        if (e.second == 0) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}