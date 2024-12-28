#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("pails.in");
    ofstream cout("pails.out");
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    queue<vector<int>> q;
    q.push({0, 0, 0});
    map<pair<int, int>, bool> vis;
    int ans = m;
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        if (tp[0] > k) break;
        vis[{tp[1], tp[2]}] = true;
        ans = min(ans, abs(m - tp[1] - tp[2]));
//        cout << tp[1] << " " << tp[2] << " " << ans << endl;
        // option 1: fill either pail
        tp[0]++;
        if (vis[{x, tp[2]}] != true) q.push({tp[0], x, tp[2]});
        if (vis[{tp[1], y}] != true) q.push({tp[0], tp[1], y});
        // option 2:  empty either pail
        if (vis[{0, tp[2]}] != true) q.push({tp[0], 0, tp[2]});
        if (vis[{tp[1], 0}] != true) q.push({tp[0], tp[1], 0});
        // option 3: pour
        //       3a: from X to Y
        int aa = min(y - tp[2], tp[1]);
        if (vis[{tp[1] - aa, tp[2] + aa}] != true) q.push({tp[0], tp[1] - aa, tp[2] + aa});
        aa = min(x - tp[1], tp[2]);
        if (vis[{tp[1] + aa, tp[2] - aa}] != true) q.push({tp[0], tp[1] + aa, tp[2] - aa});
    }
    cout << ans << endl;

}